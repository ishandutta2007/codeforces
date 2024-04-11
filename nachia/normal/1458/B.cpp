#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ULL=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

void chmax(int& a,int b){ a=max(a,b); }

struct Cup{ int a,b; };

int N;
Cup A[100];
Cup sum;

const int xNA=10000;
int nap[101][xNA+1];

int main(){
	cin>>N;
  rep(i,N) cin>>A[i].a>>A[i].b;
  sum={0,0}; rep(i,N){ sum.a+=A[i].a; sum.b+=A[i].b; }

  rep(i,N+1) rep(x,xNA+1) nap[i][x]=-1000000000;
  nap[0][0]=0;
  rep(i,N){
    for(int k=N-1; k>=0; k--){
      for(int x=A[i].a; x<=xNA; x++) chmax(nap[k+1][x],nap[k][x-A[i].a]+A[i].b);
    }
  }

  cout<<fixed<<setprecision(1);
  
  for(int k=1; k<=N; k++){
    int ans=-1000000000;
    rep(x,xNA+1) chmax(ans,min(nap[k][x]+sum.b,x*2));
    cout<<double(ans)/2<<endl;
  }

	return 0;
}