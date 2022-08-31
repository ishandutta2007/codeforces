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

int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}return s;}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}

char S[1000], T[1000];
int SN, TN;

int SA[100], TA[100];

int main(){
  int i, j, k;

  SN = reader(S);
  TN = reader(T);

  rep(i,26) SA[i] = TA[i] = 0;
  rep(i,SN) SA[S[i]-'a']++;
  rep(i,TN) TA[T[i]-'a']++;

  rep(i,26) if(TA[i] > SA[i]) break;
  if(i < 26){ writer("need tree\n"); myed; return 0; }

  rep(i,26) if(TA[i]!=SA[i]) break;
  if(i==26){ writer("array\n"); myed; return 0; }

  k = 0;
  rep(i,TN){
    for(;;){
      if(T[i]!=S[k]) k++;
      else           break;
      if(k==SN){k=SN+1; break; }
    }
    k++;
  }
  if(k<=SN){ writer("automaton\n"); myed; return 0; }

  writer("both\n"); myed;
  return 0;
}