#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define R(I,N) for(int I=0;I<N;I++)
#define F(I,A,B) for(int I=A;I<B;I++)
#define FD(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%d",&A)
#define make2(A,B) scanf("%d%d",&A,&B)
#define db if(1)printf
template<typename C> void ma(C& a,C b){if(a<b)a=b;}
template<typename C> void mi(C& a,C b){if(a>b)a=b;}
#define MAX 200100
int n,q,v[MAX][4],odl[MAX][4][4];
vector<int> d[MAX];
int gl[MAX],f[MAX];
vector<pair<int,int*> > zap[MAX];
bool cz[MAX];
void add_q(int a,int b,int* c){
  zap[a].PB(MP(b,c));
  zap[b].PB(MP(a,c));
}
int find(int a){
  return f[a]==a?a:f[a]=find(f[a]);
}
void dfs(int nr,int oj,int g){
  gl[nr] = g++;
  cz[nr] = 1;
  R(i,zap[nr].size()){
    int ak = zap[nr][i].FI;
    if(cz[ak]){
      *(zap[nr][i].SE) = gl[nr] + gl[ak] - 2 * gl[find(ak)];
    }
  }
  R(i,d[nr].size()){
    if(d[nr][i] == oj)continue;
    dfs(d[nr][i],nr,g);
    f[d[nr][i]] = nr;
  }
}
LL gcd(LL a,LL b,LL& x,LL& y){
  if(a<b)return gcd(b,a,y,x);
  if(b==0){
    x=1;
    y=0;
    return a;
  }
  LL xp;
  LL pom=gcd(b,a%b,xp,x);
  y=xp-x*(a/b);
  return pom;
}
LL d1,d2,q1,q2,c,cd,wyn,mod;
void licz(LL x,LL y){
  if(x%cd != y%cd)return;
  LL res = x * d2/cd * q2 + y * d1/cd * q1;
  res %= mod;
  if(res < 0)res += mod;
  if(wyn == -1 || res < wyn)wyn = res;
}
void licz2(LL x,LL y,LL c){
  LL diff = (y-x)%cd;
  if(diff < 0)diff += cd;
  if(diff&1)return;
  diff/=2;
  x+=diff;
  y-=diff;
  c-=diff;
  if(c < 0)return;
  LL krok = cd/2;
  c /= krok;
  
  LL res = x * d2/cd * q2 + y * d1/cd * q1;
  res %= mod;
  if(res < 0)res += mod;
  LL b = krok * d2/cd * q2 - krok * d1/cd * q1;
  
  b %= mod;
  if(b < 0)b += mod;
  LL a = mod - b;
  LL ca = 1;
  LL cb = 1;
  if(wyn == -1 || res < wyn)wyn = res;
  while(a!=0 && b!=0){
    LL pom = max(0ll,min(c/cb,(a+b-res-1)/b));
    c -= cb * pom;
    res += b * pom;
    
    pom = min(c/ca,res/a);
    c -= ca * pom;
    res -= a * pom;
    if(wyn == -1 || res < wyn)wyn = res;
    if(a > b){
      ca += a/b * cb;
      a %= b;
    }else{
      cb += b/a * ca;
      b %= a;
    }
  }
}
main(){
  make(n);
  R(i,n-1){
    int a,b;make2(a,b);a--;b--;
    d[a].PB(b);
    d[b].PB(a);
  }
  R(i,n)f[i] = i;
  make(q);
  R(i,q){
    R(j,4){
      make(v[i][j]);
      v[i][j]--;
    }
    R(j,4)F(k,j+1,4)
      add_q(v[i][j],v[i][k],&odl[i][j][k]);
  }
  dfs(0,-1,0);
  R(i,q){
    int (&od)[4][4] = odl[i];
    int t1 = od[0][1] + od[2][3] - od[0][2] - od[1][3];
    if(t1 < 0){
      puts("-1");
      continue;
    }
    d1 = od[0][1]*2;
    d2 = od[2][3]*2;
    cd = gcd(d1,d2,q1,q2);
    mod = d1/cd*d2;
    int t2 = od[0][1] + od[2][3] - od[0][3] - od[1][2];
    LL x = (od[0][2] + od[0][3] - od[2][3])/2;
    LL y = (od[0][2] + od[2][3] - od[0][3])/2;
    wyn = -1;
    if(t2 == 0){
      c = t1/2;
      licz(x,y);
      licz(d1-x-c,d2-y-c);
      licz2(x,d2-y,c);
      licz2(d1-x-c,y+c,c);
    }else{
      c = t2/2;
      licz(x,d2-y);
      licz(d1-x-c,y-c);
      licz2(x,y,c);
      licz2(d1-x-c,d2-y+c,c);
    }
    printf("%lld\n",wyn);
  }
}