#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define EPS 1e-10
void doubleIntSort(double d[],int m[],int s){int i,j,r;double k1,k2,t;if(s<=1)return;k1=(d[0]+d[s-1])/2.0;k2=k1+EPS;k1-=EPS;i=-1;j=s;for(;;){while(d[++i]<k1);while(d[--j]>k2);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;r=m[i];m[i]=m[j];m[j]=r;}doubleIntSort(d,m,i);doubleIntSort(d+j+1,m+j+1,s-j-1);}

int n;
int nf, ne, ns;
int rf, re, rs; double Rf, Re, Rs;
int df, de;
int h[21];
double res;

double x[100]; int ev[100];
int F, E, S;

void calc(void){
  int i,j,k;
  double w, tmp;

  if(n%2==0){
    i = h[0] + h[1]*10;
    j = h[n-2] + h[n-1]*10;
    if(i>j) return;
  }
  
  F = E = S = 0;
  rep(i,n){
    if(h[i]==0){
      x[2*i  ] = (i/2) - Rf;
      x[2*i+1] = (i/2) + Rf;
      ev[2*i  ] = 1;
      ev[2*i+1] = -1;
    }
    if(h[i]==1){
      x[2*i  ] = (i/2) - Re;
      x[2*i+1] = (i/2) + Re;
      ev[2*i  ] = 2;
      ev[2*i+1] = -2;
    }
    if(h[i]==2){
      x[2*i  ] = (i/2) - Rs;
      x[2*i+1] = (i/2) + Rs;
      ev[2*i  ] = 3;
      ev[2*i+1] = -3;
    }
  }
  doubleIntSort(x, ev, 2*n);

  tmp = 0;
  rep(i,2*n-1){
    w = x[i+1] - x[i];
    if(ev[i]==1) F++; if(ev[i]==-1) F--;
    if(ev[i]==2) E++; if(ev[i]==-2) E--;
    if(ev[i]==3) S++; if(ev[i]==-3) S--;
    tmp += (F*df + E*de) * (w * (S+1));
  }
  if(res < tmp) res = tmp;
}

void brute(int depth){
  if(depth==n) calc();
  
  if(nf > 0){
    h[depth] = 0;
    nf--;
    if(depth%2==0 || h[depth-1] <= h[depth]) brute(depth+1);
    nf++;
  }
  if(ne > 0){
    h[depth] = 1;
    ne--;
    if(depth%2==0 || h[depth-1] <= h[depth]) brute(depth+1);
    ne++;
  }
  if(ns > 0){
    h[depth] = 2;
    ns--;
    if(depth%2==0 || h[depth-1] <= h[depth]) brute(depth+1);
    ns++;
  }
}

int main(){
  int i,j,k,l,m;

  res = 0;

  scanf("%d%d%d",&nf,&ne,&ns);
  n = nf + ne + ns;
  scanf("%d%d%d",&rf,&re,&rs);
  scanf("%d%d",&df,&de);

  Rf = sqrt(rf*rf-1); if(rf==1) Rf = 0;
  Re = sqrt(re*re-1); if(re==1) Re = 0;
  Rs = sqrt(rs*rs-1); if(rs==1) Rs = 0;
  
  brute(0);

  printf("%.15f\n",res);

  return 0;
}