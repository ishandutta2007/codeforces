#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
/*
SSE Reference: https://software.intel.com/sites/landingpage/IntrinsicsGuide/#techs=SSE,SSE2,SSE3,SSSE3,SSE4_1,SSE4_2
In MS VC++, when reading input, please use _mm_setr_epi32 instead of _mm_set_epi32
*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <nmmintrin.h>

using namespace std;

#ifdef _MSC_VER
  #define ALIGN(x) __declspec(align(x))
#else
  #define ALIGN(x) __attribute__((aligned(x)))
#endif
const int mn4=25000;
static ALIGN(16) __m128i a[mn4];
typedef __m128i _m128i;typedef __m128i m128i;typedef __m128i __mm128i;typedef __m128i _mm128i;typedef __m128i mm128i;

void pr(__m128i inp) { // Debugging printf for __m128i
    ALIGN(16) uint32_t v[4];
    _mm_store_si128((__m128i*)v, inp);
    printf("(%d %d %d %d)", v[0], v[1], v[2], v[3]);
}

inline void modify4(const int x, const __m128i &val) {
  const __m128i gt = _mm_cmpgt_epi32(a[x], val);
  const __m128i tosub= _mm_and_si128(gt, val);
  a[x]=_mm_sub_epi32(a[x], tosub);
}

void modifyRange(const int l, const int r, const int ival) {
  const __m128i rawval=_mm_set1_epi32(ival);
  int gl=(l+3)>>2;
  int gr=r>>2;
  if (l&3) {
    int x=gl-1;
    const __mm128i indices=_mm_set_epi32(x*4+3,x*4+2,x*4+1,x*4);
    const __m128i mask = _mm_and_si128(
      _mm_cmpgt_epi32(indices, _mm_set1_epi32(l-1)),
      _mm_cmplt_epi32(indices, _mm_set1_epi32(r)));
    modify4(x,_mm_and_si128(rawval, mask));
  }
  for (int x=gl;x<gr;x++) {
    modify4(x,rawval);
  }
  if (gl-1!=gr&&(0!=(r&3))) {
    int x=gr;
    const _mm128i indices=_mm_set_epi32(x*4+3,x*4+2,x*4+1,x*4);
    const __m128i mask = _mm_and_si128(
      _mm_cmpgt_epi32(indices, _mm_set1_epi32(l-1)),
      _mm_cmplt_epi32(indices, _mm_set1_epi32(r)));
    modify4(x,_mm_and_si128(rawval, mask));
  }
}

inline void query4(__m128i &res, const int x, const __m128i &val) {
  const __m128i eq = _mm_cmpeq_epi32(a[x], val);
  res = _mm_sub_epi32(res, eq);
}

__m128i queryRange(const int l, const int r, const int ival) {
  __m128i res=_mm_setzero_si128();
  const __m128i rawval=_mm_set1_epi32(ival);
  int gl=(l+3)>>2;
  int gr=r>>2;
  if (l&3) {
    int x=gl-1;
    const _mm128i indices=_mm_set_epi32(x*4+3,x*4+2,x*4+1,x*4);
    const __m128i mask = _mm_and_si128(
      _mm_cmpgt_epi32(indices, _mm_set1_epi32(l-1)),
      _mm_cmplt_epi32(indices, _mm_set1_epi32(r)));
    query4(res,x,_mm_and_si128(rawval, mask));
  }
  for (int x=gl;x<gr;x++) {
    query4(res,x,rawval);
  }
  if (gl-1!=gr&&(0!=(r&3))) {
    int x=gr;
    const __mm128i indices=_mm_set_epi32(x*4+3,x*4+2,x*4+1,x*4);
    const __m128i mask = _mm_and_si128(
      _mm_cmpgt_epi32(indices, _mm_set1_epi32(l-1)),
      _mm_cmplt_epi32(indices, _mm_set1_epi32(r)));
    query4(res,x,_mm_and_si128(rawval, mask));
  }
  return res;
}

int sumSSE(__m128i &var) {
  // Sums all packed int32s in var. This function MODIFIES the input
  __m128i shuffle1 = _mm_shuffle_epi32(var, _MM_SHUFFLE(1, 0, 3, 2));
  var = _mm_add_epi32(var, shuffle1);
  __m128i shuffle2 = _mm_shuffle_epi32(var, _MM_SHUFFLE(2, 3, 0, 1));
  var = _mm_add_epi32(var, shuffle2);
  return _mm_cvtsi128_si32(var);
}

int rint();
int tmp[4];
int main(){
  ios_base::sync_with_stdio(false);
  memset(a,0,sizeof a);
  const int n=rint(),qlim=rint();
  const int n4=n>>2;
  for(int k = 0; k < n4; ++k) {
    //a[k]=_mm_setr_epi32(rint(),rint(),rint(),rint()); // Use this for MSVC++!
    a[k]=_mm_set_epi32(rint(),rint(),rint(),rint()); // Use this for GCC!
  }
  int rem=n-4*n4;
  if (rem) {
    for (int i=0;i<rem;i++) tmp[i]=rint();
    for (int i=rem;i<4;i++) tmp[i]=-1;
    a[n4]=_mm_load_si128((const __m128i *)tmp);
  }
  for (int q=0;q<qlim;q++) {
    const int32_t t=rint(),l=rint()-1,r=rint(),ival=rint();
    if (t==1) {
      modifyRange(l,r,ival);
    }
    else {
      __m128i res=queryRange(l,r,ival);
      int ans=sumSSE(res);
      printf("%d\n",ans);
    }
  }
}
static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = stdinDataEnd;

void readAhead(size_t amount)
{
    size_t remaining = stdinDataEnd - stdinPos;
    if (remaining < amount) {
       memmove(stdinBuffer, stdinPos, remaining);
       size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
       stdinPos = stdinBuffer;
       stdinDataEnd = stdinBuffer + remaining + sz;
       if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
         *stdinDataEnd = 0;
    }
}

int rint()
{
    readAhead(16);

    int x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}