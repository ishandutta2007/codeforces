#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

void intReverse(int d[],int size){int a=0,b=size-1,t;while(a<b)t=d[a],d[a]=d[b],d[b]=t,a++,b--;}
int intNextPermutation(int d[],int size){int i,j,k;for(k=size-2;k>=0;k--)if(d[k]<d[k+1])break;if(k<0){intReverse(d,size);return 0;}for(i=size-1;;i--)if(d[i]>d[k])break;j=d[i],d[i]=d[k],d[k]=j;intReverse(d+k+1,size-k-1);return 1;}

int main(){
  int i,j,k,l,m,n,loop;
  char in[10011];
  int d[4]={0,1,2,3};
  int now[4], ok[4];
  char *out[4] = {"Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"};

  while(scanf("%d%s",&n,in)==2){
    rep(i,n){
           if(in[i]=='?') in[i]=-1;
      else if(in[i]=='G') in[i]=0;
      else if(in[i]=='H') in[i]=1;
      else if(in[i]=='R') in[i]=2;
      else if(in[i]=='S') in[i]=3;
    }

    rep(i,4) ok[i]=0;
    do{
      rep(i,4) now[i]=0;
      rep(k,n){
        if(in[k]>=0){ now[in[k]]++; continue; }
        m = now[0]; rep(i,4) if(m > now[i]) m = now[i];
        rep(i,4) if(now[d[i]]==m){ now[d[i]]++; break; }
      }
      m = now[0]; rep(i,4) if(m > now[i]) m = now[i];
      rep(i,4) if(now[i]==m) ok[i]=1;
    }while(intNextPermutation(d,4));

    rep(i,4) if(ok[i]) puts(out[i]);
  }

  return 0;
}