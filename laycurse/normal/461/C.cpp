#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define READER_BUF_SIZE 1048576
#define WRITER_BUF_SIZE 1048576
int reader_pt=READER_BUF_SIZE,reader_last;char reader_buf[READER_BUF_SIZE];
int writer_pt=0;char writer_buf[WRITER_BUF_SIZE];
#define mygc(c) {if(reader_pt==READER_BUF_SIZE)reader_pt=0,reader_last=fread(reader_buf,sizeof(char),READER_BUF_SIZE,stdin);(c)=reader_buf[reader_pt++];}
#define mypc(c) {if(writer_pt==WRITER_BUF_SIZE)writer_pt=0,fwrite(writer_buf,sizeof(char),WRITER_BUF_SIZE,stdout);writer_buf[writer_pt++]=(c);}
#define myed {fwrite(writer_buf,sizeof(char),writer_pt,stdout);writer_pt=0;}

#define ll long long

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(int *x, int *y){reader(x);reader(y);}
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

typedef struct struct_intfenwick{
  int size, memory;
  int *data;
}intFenwickTree;

intFenwickTree intFenwickTreeNew(int memory){
  intFenwickTree res;
  res.memory=memory; res.data=(int*)malloc(memory*sizeof(int));
  return res;
}

void intFenwickTreeDelete(intFenwickTree *t){free(t->data);}
void intFenwickTreeInit(intFenwickTree *t, int size){int i; t->size=size; rep(i,size) t->data[i]=0;}
void intFenwickTreeAdd(intFenwickTree *t,int k,int add){while(k<t->size)t->data[k]+=add, k|=k+1;}
int intFenwickTreeGet(intFenwickTree *t,int k){int res=0; while(k>=0)res+=t->data[k],k=(k&(k+1))-1; return res;}
int intFenwickTreeRange(intFenwickTree *t,int a,int b){return intFenwickTreeGet(t,b)-intFenwickTreeGet(t,a-1);}

int N, Q, TYPE;
int raw[1000000];

int main(){
  int i, j, k;
  int st, ed, rev;
  int P, L, R;
  int res;
  intFenwickTree t = intFenwickTreeNew(1000000);

  intFenwickTreeInit(&t, 1000000);
  reader(&N,&Q);

  st = 500000; ed = st + N - 1; rev = 0;
  rep(i,N){
    intFenwickTreeAdd(&t, st+i, 1);
    raw[st+i] = 1;
  }

  while(Q--){
    reader(&TYPE);
    if(TYPE==1){
      reader(&P);
      if(P > (ed-st+1)/2){
        rev ^= 1;
        P = (ed-st+1) - P;
      }

      if(rev==0){
        rep(i,P){
          intFenwickTreeAdd(&t, st+2*P-1-i, raw[st+i]);
          raw[st+2*P-1-i] += raw[st+i];
        }
        st += P;
      } else {
        rep(i,P){
          intFenwickTreeAdd(&t, ed-2*P+1+i, raw[ed-i]);
          raw[ed-2*P+1+i] += raw[ed-i];
        }
        ed -= P;
      }
    } else {
      reader(&L, &R); R--;
      if(rev==1){
        swap(L, R);
        L = (ed-st+1) - 1 - L;
        R = (ed-st+1) - 1 - R;
      }
      res = intFenwickTreeRange(&t, st+L, st+R);
      writer(res, '\n');
    }

//    printf("rev %d:", rev);
//    REP(i,st,ed+1) printf(" %d", raw[i]); puts("");
  }

  myed;
  return 0;
}