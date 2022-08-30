#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

void intSort(int d[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}intSort(d,i);intSort(d+j+1,s-j-1);}
void intIntSort(int d[],int m[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;t=m[i];m[i]=m[j];m[j]=t;}intIntSort(d,m,i);intIntSort(d+j+1,m+j+1,s-j-1);}
void intReverse(int d[],int size){int a=0,b=size-1,t;while(a<b)t=d[a],d[a]=d[b],d[b]=t,a++,b--;}

int main(){
  int i,j,k,l,m,n,v;
  int a[100000],a_ind[100000],b[100000],b_ind[100000],as,bs;
  int res_a,res_b,res;
  int na,nb,now,br=0;
  int pr[100000],ps=0;

  scanf("%d%d",&k,&n);
  as=bs=0;
  rep(m,k){
    scanf("%d%d",&i,&j);
    if(i==1) a[as]=j, a_ind[as++]=m+1;
    if(i==2) b[bs]=j, b_ind[bs++]=m+1;
  }

  intIntSort(a,a_ind,as); intReverse(a,as); intReverse(a_ind,as);
  intIntSort(b,b_ind,bs); intReverse(b,bs); intReverse(b_ind,bs);

  nb=n/2;    if(nb>bs) nb=bs;
  na=n-2*nb; if(na>as) na=as;

  res=0;
  rep(i,na) res+=a[i];
  rep(i,nb) res+=b[i];
  res_a=na; res_b=nb;
  now=res;
  
  while(nb){
    now -= b[--nb];
    if(na<as) now += a[na++];
    if(na<as) now += a[na++];

    if(now > res) res=now, res_a=na, res_b=nb;
  }

  printf("%d\n",res);
  rep(i,res_a) pr[ps++]=a_ind[i];
  rep(i,res_b) pr[ps++]=b_ind[i];
  intSort(pr,ps);
  rep(i,ps){
    if(i)putchar(' ');
    printf("%d",pr[i]);
  }
  puts("");

  return 0;
}