#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define READER_BUF_SIZE 65536
#define myIsDigit(x) ('0'<=(x) && (x)<='9')
#define myIsSpace(x) ((x)==' ' || (x)=='\t' || (x)=='\n' || (x)=='\r')

int reader_pt = READER_BUF_SIZE;
char reader_buf[READER_BUF_SIZE];

int reader_nonneg_int(){
  int r;

  for(;;){
    if(reader_pt==READER_BUF_SIZE) reader_pt = 0, fread(reader_buf, READER_BUF_SIZE, sizeof(char), stdin);
    if(myIsDigit(reader_buf[reader_pt])) break;
    reader_pt++;
  }
  r = reader_buf[reader_pt++] - '0';
  for(;;){
    if(reader_pt==READER_BUF_SIZE) reader_pt = 0, fread(reader_buf, READER_BUF_SIZE, sizeof(char), stdin);
    if(!myIsDigit(reader_buf[reader_pt])) break;
    r = r*10 + (reader_buf[reader_pt++]-'0');
  }
  reader_pt++;

  return r;
}

void intSort(int d[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}intSort(d,i);intSort(d+j+1,s-j-1);}

int main(){
  int i, j, n;
  int res;
  static int s[1000000];

  n = reader_nonneg_int();
  rep(i,n) s[i] = reader_nonneg_int();
  intSort(s, n);

  res = n;
  j = n / 2;

  rep(i,n/2){
	while(j < n && 2*s[i] > s[j]) j++;
    if(j < n) res--, j++;
	else      break;
  }

  printf("%d\n",res);

  return 0;
}