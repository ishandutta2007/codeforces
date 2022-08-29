#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define mygc(c) (c)=getchar()
#define mypc(c) putchar(c)


int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}c[s]='\0';return s;}

void writer(const char x[], char c){int i;for(i=0;x[i]!='\0';i++)mypc(x[i]);mypc(c);}
template<class T> void writerLn(T x){writer(x,'\n');}

int N;
char in[200000];

int main(){
  int i, j, k;

  N = reader(in);
  rep(i,N) if( (in[i]-'0')%2==0 ) break;
  if(i==N){ writerLn("-1"); return 0; }

  rep(i,N) if( (in[i]-'0')%2==0 && in[i]<in[N-1] ){
    swap(in[i], in[N-1]);
    break;
  }

  if(i==N){
    for(i=N-1;i>=0;i--) if( (in[i]-'0')%2==0 ){
      swap(in[i], in[N-1]);
      break;
    }
  }

  writerLn(in);

  return 0;
}