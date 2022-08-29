#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
#include<iostream>
#include<cmath>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define READER_BUF_SIZE 1048576
#define myIsDigit(x) ('0'<=(x) && (x)<='9')
#define myIsSpace(x) ((x)==' ' || (x)=='\t' || (x)=='\n' || (x)=='\r')

int reader_pt = READER_BUF_SIZE, reader_last;
char reader_buf[READER_BUF_SIZE];

int reader_nonneg_int(){
  int r;

  for(;;){
    if(reader_pt==READER_BUF_SIZE) reader_pt = 0, reader_last = fread(reader_buf, sizeof(char), READER_BUF_SIZE, stdin);
    if(myIsDigit(reader_buf[reader_pt])) break;
    reader_pt++;
  }
  r = reader_buf[reader_pt++] - '0';
  for(;;){
    if(reader_pt==READER_BUF_SIZE) reader_pt = 0, reader_last = fread(reader_buf, sizeof(char), READER_BUF_SIZE, stdin);
    if(!myIsDigit(reader_buf[reader_pt])) break;
    r = r*10 + (reader_buf[reader_pt++]-'0');
  }
  reader_pt++;

  return r;
}


double solve_brute(int n, int in[]){
  int i, j, k, s;
  int arr[100];
  double res = 0, tmp;

  rep(i,n) REP(j,i,n){
    s = 0;
    REP(k,i,j+1) arr[s++] = in[k];

    tmp = 0;
    sort(arr,arr+s);
    rep(k,s) tmp = (tmp + arr[k]) / 2;

    res += tmp;
  }

  res /= n;
  res /= n;
  return res;
}


#define D 25

int main(){
  int i,j,k,kk,l,m,n,x,y;
  static int a[500000];
  static pair<int,int> srt[500000];
  set<int> ind;
  set<int>::iterator it, it1, it2;
  int ss[D], ls[D];
  double pw[100], res;

  pw[0] = 1;
  REP(i,1,100) pw[i] = pw[i-1] * 0.5;

  n = reader_nonneg_int();
  rep(i,n) a[i] = reader_nonneg_int();
  rep(i,n) srt[i] = make_pair(a[i], i);
  sort(srt, srt+n);

/*  printf("%.15f (brute)\n", solve_brute(n,a));*/

  res = 0;
  ind.clear();
  ind.insert(-1);
  ind.insert(n);
  for(kk=n-1;kk>=0;kk--){
    k = srt[kk].second;
    ind.insert(k);
    it = ind.lower_bound(k);
    it1 = it2 = it;

    rep(i,D) ss[i] = ls[i] = 0;
    x = 0;
    rep(i,D){
      it1--;
      y = ss[i] = k - (*it1);
      ss[i] -= x;
      x = y;
      if( (*it1)==-1 ) break;
    }
    x = 0;
    rep(i,D){
      it2++;
      y = ls[i] = (*it2) - k;
      ls[i] -= x;
      x = y;
      if( (*it2)==n ) break;
    }

    rep(i,D) if(ss[i]) rep(j,D) if(ls[j]){
      res += pw[i+j+1] * a[k] * ss[i] * ls[j];
/*      printf("reduce %d+%d+1, val %d (%d), num %d*%d : %f\n",i,j,a[k],k,ss[i],ls[j],res/n/n);*/
    }
    
  }

  res /= n;
  res /= n;
  printf("%.15f\n",res);

  return 0;
}