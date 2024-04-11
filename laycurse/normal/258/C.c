#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define M 1000000007

ll pw(ll a,ll b){
  ll r;
  if(!b) return 1;
  r = pw(a,b/2);
  r = (r*r)%M;
  if(b%2) r = (r*a)%M;
  return r;
}


void intSort(int d[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}intSort(d,i);intSort(d+j+1,s-j-1);}

int in[100001];
int f[100001];
ll ans[100001];

int yaku[1001], yaku_size;

int main(){
  int i,j,k,l,m,n;
  ll res, mus;

  scanf("%d",&n);
  rep(i,n) scanf("%d",in+i);

  rep(i,100001) f[i] = 0;
  rep(i,n) f[in[i]]++;
  for(i=100000-1;i>=0;i--) f[i] += f[i+1];

  REP(i,1,100001){
    ans[i] = 1;
    yaku_size = 0;
    for(k=1;k*k<=i;k++) if(i%k==0){
      yaku[yaku_size++] = k;
      if(k*k!=i) yaku[yaku_size++] = i/k;
    }
    intSort(yaku,yaku_size);

    rep(k,yaku_size){
      j = f[yaku[k]];
      if(k+1 < yaku_size) j -= f[yaku[k+1]];
      ans[i] *= pw(k+1, j);
      ans[i] %= M;
    }

    if(i==1) continue;

    mus = 1;
    rep(k,yaku_size-1){
      j = f[yaku[k]];
      if(k+1 < yaku_size-1) j -= f[yaku[k+1]];
      mus *= pw(k+1, j);
      mus %= M;
    }

    ans[i] -= mus;
    ans[i] %= M;
    if(ans[i] < 0) ans[i] += M;
  }

  res = 0;
  REP(i,1,100001) res += ans[i];
  res %= M;
  if(res < 0) res += M;
  printf("%d\n",(int)res);

  return 0;
}