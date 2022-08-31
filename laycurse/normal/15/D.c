#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

void intIntSort(ll d[],int m[],int s){
  ll i=-1,j=s,k,t;
  if(s<=1)return;k=(d[0]+d[s-1])/2;
  for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;
    t=d[i];d[i]=d[j];d[j]=t;
    t=m[i];m[i]=m[j];m[j]=t;
  }
  intIntSort(d,m,i);intIntSort(d+j+1,m+j+1,s-j-1);
}

void intSort(int d[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}intSort(d,i);intSort(d+j+1,s-j-1);}

int in[1100][1100];
ll sum[1100][1100], tmp[1100][1100], mn[1100][1100];

ll d[1000100]; int ind[1000100];

int res1[1000100],res2[1000100]; ll resd[1000100]; int res_size;

int main(){
  int i,j,k,l,m,n;
  int x,y,sx,sy,xy;
  int a,b;
  ll t;

  scanf("%d%d%d%d",&x,&y,&sx,&sy);
  rep(i,x) rep(j,y) scanf("%d",in[i]+j);

  rep(i,x){
    t=0;
    rep(j,sy) t += in[i][j];
    tmp[i][0]=t;
    REP(j,sy,y){
      t += in[i][j] - in[i][j-sy];
      tmp[i][j-sy+1] = t;
    }
  }

  rep(j,y-sy+1){
    t=0;
    rep(i,sx) t += tmp[i][j];
    sum[0][j]=t;
    REP(i,sx,x){
      t += tmp[i][j] - tmp[i-sx][j];
      sum[i-sx+1][j] = t;
    }
  }

  rep(i,x){
    rep(j,y-sy+1){
      t = in[i][j];
      REP(k,1,sy) if(t > in[i][j+k]) t = in[i][j+k];
      tmp[i][j]=t;
    }
  }

  rep(j,y-sy+1){
    rep(i,x-sx+1){
      t=tmp[i][j];
      REP(k,1,sx) if(t > tmp[i+k][j]) t = tmp[i+k][j];
      mn[i][j]=t;
    }
  }
  x = x-sx+1; y = y-sy+1; xy = x*y;
  rep(i,x) rep(j,y) d[i*y+j] = sum[i][j]-mn[i][j]*sx*sy;

  rep(i,xy) ind[i]=i;
  intIntSort(d,ind,xy);
  for(a=0;a<xy;){
    b=a+1; while(b<xy && d[a]==d[b]) b++;
    intSort(ind+a,b-a);
    a=b;
  }

  rep(i,x) rep(j,y) d[i*y+j] = sum[i][j]-mn[i][j]*sx*sy;

  res_size=0;
  rep(l,xy){
    k=ind[l]; if(d[k]<0) continue;
    i=k/y; j=k%y;
    res1[res_size]=i; res2[res_size]=j; resd[res_size++]=d[k];

    REP(a,i-sx+1,i+sx) if(0<=a&&a<x) REP(b,j-sy+1,j+sy) if(0<=b&&b<y) d[a*y+b]=-1;
  }

  printf("%d\n",res_size);
  rep(i,res_size) printf("%d %d %I64lld\n",res1[i]+1,res2[i]+1,resd[i]);
  
  return 0;
}