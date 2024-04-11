#include <stdio.h> 
#include <iostream> 
#include <vector> 
#include <cstdlib> 
#include <map> 
#include <time.h> 
#include <string> 
#include <algorithm> 
#include <queue> 
#include <assert.h> 
#include <math.h> 
#include <complex> 

#pragma warning(disable:4996) 

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++) 
#define FOR(i,a,b) for(int i=(a);i<(b);i++) 
#define pb push_back 
#define mp make_pair 
#define x first 
#define y second 
#define all(v) (v).begin(),(v).end() 

typedef long long int ll;
typedef vector<ll> lll;
typedef complex<double> point;

const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-4;
const double PI=3.1415926535897932384626433832795;

void solve(){
	ll ans=1;
	int a,t=0,s=0,n;
	scanf("%d",&n);
	For(i,n){
		scanf("%d",&a);
		if(a==1){
			if(t==1) ans*=s;
			s=1;
			t=1;
		}
		else s++;
	}
	ans*=t;
	printf("%I64d",ans);
}

int main(){
#pragma comment(linker,"/STACK:268435456") 
#ifdef _DEBUG 
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
#endif
	solve();
	return 0;
}