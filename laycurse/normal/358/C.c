#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

void intIntSort(int d[],int m[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;t=m[i];m[i]=m[j];m[j]=t;}intIntSort(d,m,i);intIntSort(d+j+1,m+j+1,s-j-1);}

int main(){
  int n;
  static int a[100000];
  static int val[100000], ind[100000];

  int i, j, k;
  int st, ed;

  scanf("%d",&n);
  rep(i,n) scanf("%d",a+i);

  st = 0;
  while(st < n){
    ed = st;
    while(ed < n && a[ed] != 0) ed++;

    if(ed==n){
      while(st < n){
        puts("pushStack");
        st++;
      }
      break;
    }

    if(ed-st == 0){
      puts("0");
    } else if(ed-st == 1){
      puts("pushStack");
      puts("1 popStack");
    } else if(ed-st == 2){
      puts("pushStack");
      puts("pushQueue");
      puts("2 popStack popQueue");
    } else {
      rep(i,ed-st) val[i] = -a[st+i], ind[i] = i;
      intIntSort(val, ind, ed-st);

      rep(i,ed-st){
        if(ind[0]==i){
          puts("pushStack");
        } else if(ind[1]==i){
          puts("pushQueue");
        } else if(ind[2]==i){
          puts("pushFront");
        } else {
          puts("pushBack");
        }
      }

      puts("3 popStack popQueue popFront");
    }
    st = ed + 1;
  }

  return 0;
}