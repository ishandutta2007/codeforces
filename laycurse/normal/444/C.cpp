#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

#define READER_BUF_SIZE 1048576
#define WRITER_BUF_SIZE 1048576
int reader_pt=READER_BUF_SIZE,reader_last;char reader_buf[READER_BUF_SIZE];
int writer_pt=0;char writer_buf[WRITER_BUF_SIZE];
#define mygc(c) {if(reader_pt==READER_BUF_SIZE)reader_pt=0,reader_last=fread(reader_buf,sizeof(char),READER_BUF_SIZE,stdin);(c)=reader_buf[reader_pt++];}
#define mypc(c) {if(writer_pt==WRITER_BUF_SIZE)writer_pt=0,fwrite(writer_buf,sizeof(char),WRITER_BUF_SIZE,stdout);writer_buf[writer_pt++]=(c);}
#define myed {fwrite(writer_buf,sizeof(char),writer_pt,stdout);writer_pt=0;}

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(int *x, int *y){reader(x);reader(y);}
void reader(int *x, int *y, int *z){reader(x);reader(y);reader(z);}
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}return s;}

void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}
void writer(ll x, char c){int i,sz=0,m=0;char buf[20];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}


int val[1000000] = {};
int flat_val[1000000] = {};
ll sum[1000000] = {}, add[1000000] = {};

ll ab(ll x){
  if(x < 0) return -x;
  return x;
}

void change(int node, int left, int right, int a, int b, int v){
  int n1 = node*2 + 1, n2 = n1 + 1, sz = right- left;

  a = max(a, left);
  b = min(b, right);
  if(a >= b) return;

  if(sz==1){
    if(flat_val[node]) val[left] = flat_val[node];
    sum[node] += ab(val[left] - v);
    flat_val[node] = v;
    return;
  }

  if(a==left && b==right){
    if(flat_val[node]){
      add[node] += ab(flat_val[node] - v);
      sum[node] += ab(flat_val[node] - v) * (right-left);
      flat_val[node] = v;
      return;
    } else {
      change(n1, left, left+sz/2, a, b, v);
      change(n2, left+sz/2, right, a, b, v);
      flat_val[node] = v;
      sum[node] = sum[n1] + sum[n2];
      return;
    }
  }

  if(add[node]){
    flat_val[n1] = flat_val[n2] = flat_val[node];
    add[n1] += add[node];
    add[n2] += add[node];
    sum[n1] += add[node] * ((left+sz/2) - left);
    sum[n2] += add[node] * (right - (left+sz/2));
    add[node] = 0;
  }

  flat_val[node] = 0;
  change(n1, left, left+sz/2, a, b, v);
  change(n2, left+sz/2, right, a, b, v);
  sum[node] = sum[n1] + sum[n2];
}

ll get(int node, int left, int right, int a, int b){
  int n1 = node*2 + 1, n2 = n1 + 1, sz = right- left;
  ll res = 0;

  a = max(a, left);
  b = min(b, right);
  if(a >= b) return 0;

  if(add[node]){
    flat_val[n1] = flat_val[n2] = flat_val[node];
    add[n1] += add[node];
    add[n2] += add[node];
    sum[n1] += add[node] * ((left+sz/2) - left);
    sum[n2] += add[node] * (right - (left+sz/2));
    add[node] = 0;
  }

  if(left==a && right==b) return sum[node];
  return get(n1, left, left+sz/2, a, b) + get(n2, left+sz/2, right, a, b);
}


int N, M;
int T, L, R, X;

int main(){
  int i, j, k;
  ll res;

  reader(&N,&M);
  rep(i,N) val[i] = i+1;
  
  while(M--){
    reader(&T);
    if(T==1){
      reader(&L,&R,&X); L--;
      change(0, 0, N, L, R, X);
    } else {
      reader(&L,&R); L--;
      res = get(0, 0, N, L, R);
      writer(res,'\n');
    }
  }

  myed;
  return 0;
}