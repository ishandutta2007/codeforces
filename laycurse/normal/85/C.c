#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

void intIntSort(int d[],int m[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;t=m[i];m[i]=m[j];m[j]=t;}intIntSort(d,m,i);intIntSort(d+j+1,m+j+1,s-j-1);}

#define N 200000

int n, qs;
int q[N], q_ind[N];
int root;
int left[N], right[N], up[N], num[N];
double sum[N], per[N]; int mi[N], mx[N];
int mx_node[N], mn_node[N];

int res_size;
double res[N];

void pre_cal(int node){
  if(left[node]==-1){
    mx_node[node] = mn_node[node] = num[node];
    return;
  }

  pre_cal( left[node]);
  pre_cal(right[node]);
  mn_node[node] = mn_node[ left[node]];
  mx_node[node] = mx_node[right[node]];
}

void solve(int node){
  int i,j,k;
  int nx;

  if(left[node]==-1){
    while(res_size < qs && mi[node]<=q[res_size]&&q[res_size]<=mx[node]){
      res[q_ind[res_size]] = sum[node] / per[node];
      res_size++;
    }
    return;
  }

  nx = left[node];
  mi[nx] = mi[node]; mx[nx] = num[node]-1;
  sum[nx] = sum[node] + mn_node[right[node]];
  per[nx] = per[node] + 1;
  solve(nx);

  nx = right[node];
  mi[nx] = num[node]+1; mx[nx] = mx[node];
  sum[nx] = sum[node] + mx_node[left[node]];
  per[nx] = per[node] + 1;
  solve(nx);
}

int main(){
  int i,j,k,l,m;

  while(scanf("%d",&n)==1){
    rep(i,n) scanf("%d%d",up+i,num+i), up[i]--;
    scanf("%d",&qs);
    rep(i,qs) scanf("%d",q+i);

    rep(i,n) left[i] = right[i] = -1;
    rep(i,n){
      if(up[i]<0){ root = i; continue; }
      if(num[i] < num[up[i]])  left[up[i]] = i;
      if(num[i] > num[up[i]]) right[up[i]] = i;
    }

    rep(i,qs) q_ind[i] = i;
    intIntSort(q,q_ind,qs);
    pre_cal(root);

    res_size = 0;
    mi[root] = -2000000000; mx[root] = 2000000000;
    solve(root);

    rep(i,qs) printf("%.10lf\n",res[i]);
  }

  return 0;
}