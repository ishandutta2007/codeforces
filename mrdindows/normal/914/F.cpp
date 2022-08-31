#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define _CRT_SECURE_NO_WARNINGS
# include <bitset>
# include <stdio.h>
# include <iostream>
# include <cstring>

using namespace std;

#define oo 0x3f3f3f3f
#define mp make_pair
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define FO(i,a,b) for(int i=a;i<=b;++i)

inline int read(void){
    int x,f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;
    for(x=0;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
    return x*f;
}
const int __BS = 4096;
static char __buw[__BS + 24], *__iw = __buw, *__ew = __buw + __BS;
template<class T>
void writeInt(T x, char endc = '\n') {
    if (x < 0) *__iw++ = '-', x = -x; if (x == 0) *__iw++ = '0';
    char* s = __iw;
    while (x) { T t = x / 10; char c = x - 10 * t + '0'; *__iw++ = c; x = t; }
    char* f = __iw - 1; while (s < f) swap(*s, *f), ++s, --f;
    if (__iw > __ew) cout.write(__buw, __iw - __buw), __iw = __buw;
    *__iw++ = endc;
}
struct __FL__ { ~__FL__() { if (__iw != __buw) cout.write(__buw, __iw - __buw); } };
static __FL__ __flushVar__;

#define N 100032
bitset<N> S[26],R,ful;
int q,op,l,r,n,p,ans,y;
char str[N],s[N],ch;

int main(void) {
    gets(str);n=strlen(str);
    FO(i,0,n-1) S[str[i]-'a'].set(i),ful.set(i);
    q=read();
    FO(i,1,q){
        op=read();
        if (op==2){
            l=read();r=read();
            gets(s);p=strlen(s);
            if (r-l+1<p){ writeInt(0); continue; }
            R=ful;FO(i,0,p-1) R&=S[s[i]-'a']>>i;
            auto data = (int*)&R;
            int ans = 0;
            r -= p;
            --l;
            if (r - l <= 100) {
                for (int i = l; i <= r; ++i) {
                    ans += R[i];
                }
            } else {
                while (l % 32) {
                    ans += R[l]; ++l;
                }
                ++r;
                while (r % 32) {
                    --r; ans += R[r];
                }
                l /= 32;
                r /= 32;
                data += l;
                r -= l;
                while (r % 4) {
                    --r;
                    ans += __builtin_popcount(data[r]);
                }
                r /= 4;
                for (int i = 0; i < r; ++i) {
                    ans += __builtin_popcount(data[0]) + __builtin_popcount(data[1]) + __builtin_popcount(data[2]) + __builtin_popcount(data[3]);
                    data += 4;
                }
            }
            writeInt(ans);
        }else{
            y=read()-1;ch=getchar();
            S[str[y]-'a'].reset(y);
            S[ch-'a'].set(y);str[y]=ch;
        }
    }
    return 0;
}