#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

typedef struct struct_vector_int{ int size,mem; int *d; }intVector;
intVector intVectorNull(){ intVector v; v.size=v.mem=0; return v; }

void intVectorMemoryExpand(intVector *v){
  int i, *t, m;
  m=v->mem*2; if(m<5) m=5;
  t=(int*)malloc(m*sizeof(int));
  rep(i,v->size) t[i]=v->d[i];
  if(v->mem) free(v->d);
  v->d=t; v->mem=m;
}

void intVectorPushBack(intVector *v,int add){
  if(v->mem==v->size) intVectorMemoryExpand(v);
  v->d[(v->size)++] = add;
}

void intSort(int d[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}intSort(d,i);intSort(d+j+1,s-j-1);}

intVector waste[50001];
int sum[50001];

int main(){
  int i,j,k,l,m,n,t,q;
  int x,y;
  int a,b,res;
  char *out[]={"Carrots","Kiwis","Grapes","Waste"};

  rep(i,50001) waste[i] = intVectorNull();

  while(scanf("%d%d%d%d",&x,&y,&t,&q)==4){
    rep(i,x) waste[i].size = 0;
    while(t--){
      scanf("%d%d",&i,&j); i--; j--;
      intVectorPushBack(waste+i,j);
    }
    rep(i,x) intSort(waste[i].d, waste[i].size);

    sum[0]=0;
    rep(i,x) sum[i+1] = sum[i]+waste[i].size;

    while(q--){
      scanf("%d%d",&a,&b); a--; b--;
      res = (y*a-sum[a])%3;
      res = (res+b)%3;
      rep(i,waste[a].size){
        k = waste[a].d[i];
        if(k==b){ res=3; break; }
        if(k>b) break;
        res = (res+2)%3;
      }
      puts(out[res]);
    }
  }


  return 0;
}