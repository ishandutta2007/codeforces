#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
void llIntSort(ll d[],int m[],int s){int i,j,a;ll k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;i=-1;j=s;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;a=m[i];m[i]=m[j];m[j]=a;}llIntSort(d,m,i);llIntSort(d+j+1,m+j+1,s-j-1);}

void charCreateSuffixArray(char t[], int n, int res[], void *WorkMemory) {
  int i, h, *g, *b; ll *d;

  g = (int*)WorkMemory; WorkMemory = (void*)(g+n+1);
  b = (int*)WorkMemory; WorkMemory = (void*)(b+n+1);
  d = (ll*) WorkMemory;
  
  rep(i,n+1) res[i] = i, d[i] = g[i] = t[i];
  b[0] = 0; b[n] = 0;

  llIntSort(d,res,n+1);
  for(h=1;b[n]!=n;h*=2){
    rep(i,n+1){
      d[i] = g[res[i]] * (1LL<<32);
      if(res[i]+h<n+1) d[i] += g[res[i]+h];
    }
    llIntSort(d,res,n+1);
    rep(i,n){ b[i+1]=b[i]; if(g[res[i]]!=g[res[i+1]]||g[res[i]+h]!=g[res[i+1]+h]) b[i+1]++; }
    rep(i,n+1) g[res[i]]=b[i];
  }
}

/* Kasai-Lee-Arimura-Arikawa-Park: O(n) */
void charCreateLCPFromSA(char *t, int n, int *SA, int *res, void *WorkMemory) {
  int i, j, h=0, *b;

  b = (int*)WorkMemory;

  rep(i,n+1) b[SA[i]]=i;
  rep(i,n+1){
    if(b[i]){
      for(j=SA[b[i]-1];j+h<n&&i+h<n&&t[j+h]==t[i+h];h++);
      res[b[i]]=h;
    }else res[b[i]] = -1;
    if(h>0)h--;
  }
}

void intIntSort(int d[],int m[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;t=m[i];m[i]=m[j];m[j]=t;}intIntSort(d,m,i);intIntSort(d+j+1,m+j+1,s-j-1);}

void unionInit(int d[],int val[],int s){
  int i;
  rep(i,s) d[i]=i, val[i]=0;
}

int unionGet(int d[],int val[],int n){
  int t=n,k;
  while(d[t]!=t)t=d[t];
  while(d[n]!=n)k=d[n],d[n]=t,n=k;
  return n;
}

int unionConnect(int d[],int val[],int a,int b){
  a=unionGet(d,val,a);
  b=unionGet(d,val,b);
  if(a==b)return 0;
  d[a]=b; val[b]+=val[a];
  return 1;
}

void intReverse(int d[],int size){int a=0,b=size-1,t;while(a<b)t=d[a],d[a]=d[b],d[b]=t,a++,b--;}

char in[110000];
int SA[110000], LCP[110000];

int a[110000], b[110000];

int ind[220000], val[220000];

int main(){
  int i,j,k,l,m,n,st,ed;
  int up, down;
  ll res;
  void *mem = malloc(10000000);

  while(scanf("%s",in)==1){
    n = strlen(in);
    charCreateSuffixArray(in, n, SA, mem);
    charCreateLCPFromSA(in, n, SA, LCP, mem);

    res = n;
    res = (res*(res+1))/2;

/*    rep(i,n+1) printf("%d %d\n",i,LCP[i]);*/

    unionInit(ind, val, 2*n+10);
    rep(i,n+1) val[i*2] = 1;

    rep(i,n) a[i] = i+1, b[i] = LCP[i+1];
    intIntSort(b,a,n);
    rep(i,n){
      st = i; ed = i;
      while(ed < n && b[st]==b[ed]) ed++;
      intIntSort(a+st,b+st,ed-st);
      intReverse(a+st,ed-st);
      i = ed-1;
    }
/*    rep(i,n) printf("%d %d\n",a[i],b[i]); puts("");*/
    for(i=n-1;i>=0;i--){
      unionConnect(ind,val,2*a[i],2*a[i]-1);
      down = val[unionGet(ind,val,2*a[i])];
      unionConnect(ind,val,2*a[i],2*a[i]+1);
      up   = val[unionGet(ind,val,2*a[i])];
      up = up - down;

      res += (ll)down * b[i];
      res += (ll)up*down * b[i];
/*      printf("%d %d %d\n",up,down,b[i]);*/
    }

    printf("%I64d\n",res);
  }

  return 0;
}