#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

void intSort(int d[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}intSort(d,i);intSort(d+j+1,s-j-1);}
void intIntSort(int d[],int m[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;t=m[i];m[i]=m[j];m[j]=t;}intIntSort(d,m,i);intIntSort(d+j+1,m+j+1,s-j-1);}

int ind[1000000], val[1000000];
int used[1000000];

int res_max, res[1000000], res_size;

int main(){
  int n;
  static int in[1000000];

  int i, j, k;
  int a, b, mn;

  res_max = -1; res_size = 0;

  scanf("%d",&n);
  rep(i,n) scanf("%d",in+i);

  rep(i,n) ind[i] = i, val[i] = in[i];
  intIntSort(val, ind, n);
  rep(i,n) used[i] = 0;

  rep(k,n){
    i = ind[k];
    if(used[i]) continue;
    mn = in[i];
    a = b = i;
    used[i] = 1;
    
    for(;;){
      if(a-1 < 0) break;
      if(in[a-1]%mn) break;
      a--; used[a] = 1;
    }

    for(;;){
      if(b+1 >= n) break;
      if(in[b+1]%mn) break;
      b++; used[b] = 1;
    }

    if(b-a > res_max){
      res_max = b-a;
      res_size = 0;
    }

    if(b-a == res_max){
      res[res_size++] = a+1;
    }
  }

  intSort(res,res_size);
  printf("%d %d\n",res_size,res_max);
  rep(i,res_size){
    if(i) putchar(' ');
    printf("%d",res[i]);
  }
  puts("");

  return 0;
}