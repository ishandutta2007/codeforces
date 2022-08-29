#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

void intSort(int d[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}intSort(d,i);intSort(d+j+1,s-j-1);}

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


int stops[200000], stops_size;
intVector student[20000];
int res[200000];

int main(){
  int i,j,k,l,m,n;
  int now_tm, place;

  rep(i,20000) student[i] = intVectorNull(), student[i].size = 0;

  scanf("%d%d",&n,&m);
  stops_size = 0; now_tm = 0;
  rep(k,n){
    scanf("%d%d",&i,&j);
    stops[stops_size++] = j;
    intVectorPushBack(student+j, k);
    if(now_tm < i) now_tm = i;
    if(k==n-1 || stops_size==m){
      intSort(stops, stops_size);
      place = 0;
      rep(l,stops_size){
        i = stops[l];
        if(student[i].size == 0) continue;
        now_tm += i - place; place = i;
        rep(j,student[i].size) res[student[i].d[j]] = now_tm;
        now_tm += 1 + student[i].size / 2;
        student[i].size = 0;
      }
      now_tm += place;
      stops_size = 0;
    }
  }

  rep(i,n){
    if(i) putchar(' ');
    printf("%d",res[i]);
  }
  puts("");

  return 0;
}