#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int dist[900000];
double p[900000];
double gain[900000], sum[900000];

double mn[900000], mx[900000], sa[900000];

void seg_tree_set(int left, int right, int n){
  int n1, n2;
  int sz = right - left;

  if(sz==1){
    mn[n] = mx[n] = sum[left];
    sa[n] = 0;
    return;
  }

  n1 = n * 2 + 1;
  n2 = n * 2 + 2;
  seg_tree_set(left, left+sz/2, n1);
  seg_tree_set(left+sz/2, right, n2);

  mn[n] = mn[n1]; if(mn[n] > mn[n2]) mn[n] = mn[n2];
  mx[n] = mx[n1]; if(mx[n] < mx[n2]) mx[n] = mx[n2];
  sa[n] = sa[n1]; if(sa[n] < sa[n2]) sa[n] = sa[n2];
  if(sa[n] < mx[n2] - mn[n1]) sa[n] = mx[n2] - mn[n1];
}

void seg_tree_calc(int a, int b, int left, int right, int n, double *mn3, double *mx3, double *sa3){
  int n1, n2;
  int sz = right - left;
  double mn1, mn2, mx1, mx2, sa1, sa2;

  if(a < left) a = left;
  if(b > right) b = right;
  if(b-a <= 0){
    *mn3 = 1e100;
    *mx3 = -1e100;
    *sa3 = -1e100;
    return;
  }

  if(a==left && b==right){
    *mn3 = mn[n];
    *mx3 = mx[n];
    *sa3 = sa[n];
    return;
  }

  n1 = n * 2 + 1;
  n2 = n * 2 + 2;
  seg_tree_calc(a, b, left, left+sz/2,  n1, &mn1, &mx1, &sa1);
  seg_tree_calc(a, b, left+sz/2, right, n2, &mn2, &mx2, &sa2);

  *mn3 = mn1; if(*mn3 > mn2) *mn3 = mn2;
  *mx3 = mx1; if(*mx3 < mx2) *mx3 = mx2;
  *sa3 = sa1; if(*sa3 < sa2) *sa3 = sa2;
  if(*sa3 < mx2 - mn1) *sa3 = mx2 - mn1;
}

int main(){
  int i,j,k,l,m,n,c;
  int a, b;
  int num, node;
  double res, mn, mx, sa;

  while(scanf("%d%d%d",&n,&m,&c)==3){
    res = 0;
    rep(i,n) scanf("%d",dist+i);
    rep(i,n-1) scanf("%d",&k), p[i] = k / 100.0;

    num = 1;
    while(num < n+1) num *= 2;
    node = num * 2 - 1;

    rep(i,num) gain[i] = 0;
    rep(i,n-1) gain[i] = dist[i+1] - dist[i] - p[i]*c*2;

    sum[0] = 0;
    rep(i,num) sum[i+1] = sum[i] + gain[i];

    seg_tree_set(0, num, 0);

    while(m--){
      scanf("%d%d",&a,&b);
      seg_tree_calc(a-1, b, 0, num, 0, &mn, &mx, &sa);
      res += sa;
    }

    res /= 2;
    printf("%.10f\n",res);
  }

  return 0;
}