#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define READER_BUF_SIZE 1048576
#define myIsDigit(x) ('0'<=(x) && (x)<='9')
#define myIsSpace(x) ((x)==' ' || (x)=='\t' || (x)=='\n' || (x)=='\r')

int reader_pt = READER_BUF_SIZE, reader_last;
char reader_buf[READER_BUF_SIZE];

int reader_nonneg_int(){
  int r;

  for(;;){
    if(reader_pt==READER_BUF_SIZE) reader_pt = 0, reader_last = fread(reader_buf, sizeof(char), READER_BUF_SIZE, stdin);
    if(myIsDigit(reader_buf[reader_pt])) break;
    reader_pt++;
  }
  r = reader_buf[reader_pt++] - '0';
  for(;;){
    if(reader_pt==READER_BUF_SIZE) reader_pt = 0, reader_last = fread(reader_buf, sizeof(char), READER_BUF_SIZE, stdin);
    if(!myIsDigit(reader_buf[reader_pt])) break;
    r = r*10 + (reader_buf[reader_pt++]-'0');
  }
  reader_pt++;

  return r;
}

#define WRITER_BUF_SIZE 1048576
int writer_pt = 0;
char writer_buf[WRITER_BUF_SIZE];

void writer_nonneg_int_char(int n, char c){
  int i, sz;
  static char buf[10];

  sz = 0;
  while(n) buf[sz++] = n%10, n/=10;
  if(sz==0) buf[sz++] = 0;

  while(sz--){
    if(writer_pt==WRITER_BUF_SIZE) writer_pt=0, fwrite(writer_buf, sizeof(char), WRITER_BUF_SIZE, stdout);
    writer_buf[writer_pt++] = buf[sz] + '0';
  }
  
  if(writer_pt==WRITER_BUF_SIZE) writer_pt=0, fwrite(writer_buf, sizeof(char), WRITER_BUF_SIZE, stdout);
  writer_buf[writer_pt++] = c;
}

void writer_flush(void){
  fwrite(writer_buf, sizeof(char), writer_pt, stdout);
  writer_pt = 0;
}

#define M 1000000007

void extended_euclid(ll x,ll y,ll *c,ll *a,ll *b){
  ll a0,a1,a2,b0,b1,b2,r0,r1,r2,q;
  r0=x; r1=y; a0=1; a1=0; b0=0; b1=1;
  while(r1>0){
    q=r0/r1; r2=r0%r1; a2=a0-q*a1; b2=b0-q*b1;
    r0=r1; r1=r2; a0=a1; a1=a2; b0=b1; b1=b2;
  }
  *c=r0; *a=a0; *b=b0;
}

ll get_inv(ll n, ll p){
  ll a,b,c;
  extended_euclid(n,p,&c,&a,&b);
  if(a<p) a+=p;
  return a%p;
}

ll fact[200010], fact_inv[200010], inv[200010];

ll comb(int a, int b){
  ll res;
  if(b < 0 || b > a) return 0;
  res = (fact[a] * fact_inv[b]) % M;
  res = (res * fact_inv[a-b]) % M;
  return res;
}

ll pw(ll a,ll b, ll md){
  ll r;
  if(!b) return 1;
  r = pw(a,b/2,md);
  r = (r*r)%md;
  if(b%2) r = (r*a)%md;
  return r;
}



void intReverse(int d[],int size){int a=0,b=size-1,t;while(a<b)t=d[a],d[a]=d[b],d[b]=t,a++,b--;}
int intNextPermutation(int d[],int size){int i,j,k;for(k=size-2;k>=0;k--)if(d[k]<d[k+1])break;if(k<0){intReverse(d,size);return 0;}for(i=size-1;;i--)if(d[i]>d[k])break;j=d[i],d[i]=d[k],d[k]=j;intReverse(d+k+1,size-k-1);return 1;}

int solve_brute(int n, int in[]){
  int i, j, k;
  int d[1000];
  int res;

  rep(i,n) d[i] = i;
  do{
    rep(i,n) if(in[i] != -1 && in[i] != d[i]) break;
    if(i < n) continue;

    k = 0;
    REP(i,1,n-1) if(d[i] > d[i-1] && d[i] > d[i+1]){ k=1; break; }
    if(k) continue;

    res++;
  }while(intNextPermutation(d,n));

  return res;
}


int main(){
  int i,j,k,l,m,n,fg;
  int a, b, aa, bb, x, y, va, vb;
  int dist, mov;
  ll res, tmp;
  static int in[101000];

  inv[1] = 1; 
  for(i=2;i<200010;i++) inv[i] = M - ((M/i)*inv[M%i]%M);

  fact[0] = fact_inv[0] = 1;
  REP(i,1,200010) fact[i] = (fact[i-1] * i)%M;
  REP(i,1,200010) fact_inv[i] = (fact_inv[i-1] * inv[i])%M;

  n = reader_nonneg_int();
  rep(i,n) in[i] = reader_nonneg_int() - 1;

/*  printf("%d (brute)\n",solve_brute(n,in));*/

  k = -1;
  m = 1000000;
  rep(i,n) if(in[i] >= 0){
    if(m > in[i]) m = in[i], k = i;
  }

  if(k==-1){
    res = pw(2,n-1,M);
    writer_nonneg_int_char(res, '\n');
  } else {

    res = 0;
    rep(fg,2){
      if(fg==1 && in[k]==0) continue;

      tmp = 1;
      a = b = k;

      if(fg==0){
        rep(i,in[k]){
          a--;
          if(a < 0){ tmp = 0; break; }
          if(in[a] != -1){ tmp = 0; break; }
        }
      }else{
        rep(i,in[k]){
          b++;
          if(b >= n){ tmp = 0; break; }
          if(in[b] != -1){ tmp = 0; break; }
        }
      }
      if(tmp==0) continue;
      if(in[k]>=2) tmp = (tmp * pw(2, in[k]-1, M)) % M;

      aa = a-1;
      bb = b+1;
      while(aa >= 0 && in[aa] == -1) aa--;
      while(bb <  n && in[bb] == -1) bb++;

      for(;;){
/*        printf("a b %d %d\n",a,b);
        printf("aa %d, bb %d\n",aa,bb);
        printf("tmp %d\n",(int)tmp);*/
        
        if(aa < 0 && bb >= n){
          x = a; y = n-b-1;
          tmp = (tmp * comb(x+y,x)) % M;
          break;
        }

        if(aa <  0) va = n+1; else va = in[aa];
        if(bb >= n) vb = n+1; else vb = in[bb];
        
        if(va < vb){
          dist = a - aa;
          mov  = va - (b-a);
/*          printf("go left: dist %d, mov %d\n",dist,mov);*/
          tmp = (tmp * comb(mov-1, dist-1)) % M;
          if(bb <= b+mov-dist){ tmp=0; break; }
          a -= dist;
          b += mov - dist;
          aa = a-1;
          while(aa >= 0 && in[aa] == -1) aa--;
        } else {
          dist = bb - b;
          mov  = vb - (b-a);
/*          printf("go right: dist %d, mov %d\n",dist,mov);*/
          tmp = (tmp * comb(mov-1, dist-1)) % M;
          if(aa >= a-(mov-dist)){ tmp=0; break; }
          a -= mov - dist;
          b += dist;
          bb = b+1;
          while(bb <  n && in[bb] == -1) bb++;
        }
      }

      res = (res + tmp) % M;
    }

    writer_nonneg_int_char(res, '\n');
  }

  writer_flush();
  return 0;
}