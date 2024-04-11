#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int SixSidedDieState[24][3]={
  0,1,2,  0,2,4,  0,4,3,  0,3,1,
  1,5,2,  1,2,0,  1,0,3,  1,3,5,
  2,1,5,  2,5,4,  2,4,0,  2,0,1,
  3,1,0,  3,0,4,  3,4,5,  3,5,1,
  4,0,2,  4,2,5,  4,5,3,  4,3,0,
  5,3,4,  5,4,2,  5,2,1,  5,1,3
};

int SixSidedDieRotateCenter[24]={
   1, 2, 3, 0,
   5, 6, 7, 4,
   9,10,11, 8,
  13,14,15,12,
  17,18,19,16,
  21,22,23,20
};

int SixSidedDieRotateRight[24]={
  12, 5,10,19,
  15,22,11, 3,
   0, 4,21,16,
  23, 6, 2,18,
  13, 1, 9,20,
   7,14,17, 8
};

int SixSidedDieRotateLeft[24]={
  16,13, 6,11,
   0,12,23, 8,
  17, 1, 5,22,
  19,20, 7, 3,
  21,14, 2,10,
   9, 4,15,18
};


int die[24][6],center[24],right[24],left[24],center3[24],right3[24],left3[24];
void dieInit(){
  int i,j;
  rep(i,24){
    rep(j,3) die[i][j] = SixSidedDieState[i][j];
    REP(j,3,6) die[i][j] = 5-SixSidedDieState[i][5-j];
    center[i] = SixSidedDieRotateCenter[i];
    right[i]  = SixSidedDieRotateRight[i];
    left[i]   = SixSidedDieRotateLeft[i];
  }
  rep(i,24){
    center3[i]= center[center[center[i]]];
    right3[i] = right[right[right[i]]];
    left3[i]  = left[left[left[i]]];
  }
}

#define ll long long
#define ull unsigned ll

#define ULL_HASH_SIZE 2000
ull ull_hash_n[ULL_HASH_SIZE]; int ull_hash_d[ULL_HASH_SIZE];

void ullHashClear(void){ memset(ull_hash_d,0,ULL_HASH_SIZE*sizeof(int)); }
int ullHashFunction(ull a){ return (a*1007)%ULL_HASH_SIZE; }

int ullHashGet(ull a){
  int i=ullHashFunction(a);
  for(;;){
    if(ull_hash_n[i]==a && ull_hash_d[i]) break;
    if(!ull_hash_d[i]) break;
    i++; if(i==ULL_HASH_SIZE) i=0;
  }
  if(ull_hash_n[i]!=a) return 0; return ull_hash_d[i];
}

void ullHashSet(ull a,int n){
  int i=ullHashFunction(a);
  for(;;){
    if(ull_hash_n[i]==a && ull_hash_d[i]) break;
    if(!ull_hash_d[i]) break;
    i++; if(i==ULL_HASH_SIZE) i=0;
  }
  ull_hash_n[i]=a; ull_hash_d[i]=n;
}

int ullHashIncrease(ull a){
  int i=ullHashFunction(a);
  for(;;){
    if(ull_hash_n[i]==a && ull_hash_d[i]) break;
    if(!ull_hash_d[i]) break;
    i++; if(i==ULL_HASH_SIZE) i=0;
  }
  ull_hash_n[i]=a; return ++ull_hash_d[i];
}

void intSort(int d[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}intSort(d,i);intSort(d+j+1,s-j-1);}
void intReverse(int d[],int size){int a=0,b=size-1,t;while(a<b)t=d[a],d[a]=d[b],d[b]=t,a++,b--;}
int intNextPermutation(int d[],int size){int i,j,k;for(k=size-2;k>=0;k--)if(d[k]<d[k+1])break;if(k<0){intReverse(d,size);return 0;}for(i=size-1;;i--)if(d[i]>d[k])break;j=d[i],d[i]=d[k],d[k]=j;intReverse(d+k+1,size-k-1);return 1;}

int main(){
  int i,j,k,l,m,n;
  int res;
  char tmp[10];
  int in[10], go[10];
  ull hs, mx;

  dieInit();
  while(scanf("%s",tmp)==1){
    ullHashClear();
    res = 0;

    rep(i,6) in[i] = tmp[i];
    intSort(in,6);

    do{
      mx = 0;
      rep(i,24){
        rep(k,6) go[k] = in[die[i][k]];
        hs = 0;
        rep(k,6) hs = hs * 1007 + go[k];
        if(mx < hs) mx = hs;
      }
      if( ullHashIncrease(mx)==1 ) res++;
    }while(intNextPermutation(in,6));

    printf("%d\n",res);
  }

  return 0;
}