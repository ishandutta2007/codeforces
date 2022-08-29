#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
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
#define makel(A) scanf("%I64d",&A)
#define pl(A) printf("%I64d ",A)
#define C 50000000
#define C2 49999500
#define MAX 201
#define PI (acos(-1.))
int n,m;
int xx[MAX],yy[MAX];
LL ilwek(LL x1,LL y1,LL x2,LL y2){
  return x1*y2-x2*y1;
}
LL pole(int a,int b,int c){
  return abs(ilwek(xx[a]-xx[c],yy[a]-yy[c],xx[b]-xx[c],yy[b]-yy[c]));
}
main(){
  make(n);make(m);
 // for(m=4;m<=100;m++){
  //  n=2*m;
  //  printf("m=%d\n",m);
  if(m==3&&n>=5){
    printf("-1\n");
    return 0;
  } 
  R(i,m){
    xx[i]=C*sin(2.*PI/m*i);
    yy[i]=C*cos(2.*PI/m*i);
 //   printf("%d %d\n",xx[i],yy[i]);
  }
  R(i,n-m){
    /*int px=xx[i];
    int py=yy[i];
    if(xx[i]>0){px-=100;py-=10;}
    else if(xx[i]<0){px+=100;py+=10;};
    swap(xx[i],yy[i]);swap(px,py);
    if(xx[i]>0){px-=100;py-=10;}
    else if(xx[i]<0){px+=100;py+=10;};
    swap(xx[i],yy[i]);swap(px,py);
    xx[i+m]=px;
    yy[i+m]=py;*/
 //   printf("%d %d\n",px,py);
   xx[i+m]=C2*sin(2.*PI/m*i+0.000001);
    yy[i+m]=C2*cos(2.*PI/m*i+0.000001);
  }
  R(i,n)printf("%d %d\n",xx[i],yy[i]);
 /* R(i,m)R(j,m)R(k,m){
    if(i==j||i==k||j==k)continue;
    if(ilwek(xx[i]-xx[k],yy[i]-yy[k],xx[j]-xx[k],yy[j]-yy[k])==0)printf("wspol\n");
  }
  R(i,m){
    int a=i;
    int b=(i+1)%m;
    int c=(i-1+m)%m;
    int d=i+m;
    if(pole(a,b,d)+pole(a,c,d)+pole(b,c,d)!=pole(a,b,c))printf("zle\n");
  }
  }*/
}