#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define R(I,N) for(int I=0;I<N;I++)
#define F(I,A,B) for(int I=A;I<B;I++)
#define FD(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%d",&A)
#define make2(A,B) scanf("%d%d",&A,&B)
#define ALL(x) (x).begin(), (x).end()
#define db if(1)printf
template<typename C> void MA(C& a,C b){if(a<b)a=b;}
template<typename C> void MI(C& a,C b){if(a>b)a=b;}
#define MAX 100101
int n;
char t[MAX],s[MAX];
main(){
  make(n);
  scanf("%s%s",t,s);
  int a = 0;
  while(t[a] == s[a])a++;
  int b = 0;
  while(t[n-b-1] == s[n-b-1])b++;
  int wyn = 0;
  int il = n-a-b-1;
  bool cz = 1;
  R(i,il)if(t[a+i] != s[a+i+1])cz = 0;
  if(cz)wyn ++;
  cz = 1;
  R(i,il)if(t[a+i+1] != s[a+i])cz = 0;
  if(cz)wyn ++;
  printf("%d\n",wyn);
}