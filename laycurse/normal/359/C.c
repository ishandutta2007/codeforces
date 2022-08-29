#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define M 1000000007
void intSort(int d[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}intSort(d,i);intSort(d+j+1,s-j-1);}

ll pw(ll a,ll b, ll md){
  ll r;
  if(!b) return 1;
  r = pw(a,b/2,md);
  r = (r*r)%md;
  if(b%2) r = (r*a)%md;
  return r;
}

int main(){
  int n, x;
  static int in[1000000];
  ll res, cnt, now, dif, sum;
  int dame;

  int i, j;

  scanf("%d%d",&n,&x);
  n++; in[0]=0;
  REP(i,1,n) scanf("%d",in+i);
  intSort(in,n);

  res = sum = 0;
  rep(i,n) sum += in[i];
  res = sum - in[n-1];

  cnt = 0; now = in[n-1];
  for(i=n-1;i>=0;i--){
    if(in[i]==now){ cnt++; continue; }
    dif = now - in[i];
    dame = 0;
    for(;;){
      if(dif==0) break;
      if(cnt%x){ dame=1; break; }
      cnt /= x; dif--; res++;
    }
    if(dame) break;
    cnt++;
    now = in[i];
  }

  res = pw(x, res, M);
  printf("%d\n",(int)res);

  return 0;
}