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

const int INF=1e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-4;
const double PI=3.1415926535897932384626433832795;

int a[26];

int gcd(int a,int b){
	while(a>0&&b>0){
		if(a>b) a%=b;
		else b%=a;
	}
	return a+b;
}

void solve(){
	int n,odd=0,d=0,oddi;
	scanf("%d",&n);
	For(i,n){
		scanf("%d",&a[i]);
		odd+=a[i]%2;
		if(a[i]%2) oddi=i;
	}
	if(odd>1){
		printf("0\n");
		For(i,n){
			For(j,a[i]) printf("%c",i+'a');
		}
		return;
	}
	For(i,n) d=gcd(d,a[i]);
	printf("%d\n",d);
	if(odd==1){
		For(i,d){
			For(j,a[oddi]/d) printf("%c",oddi+'a');
			For(j,n){
				if(j!=oddi){
					For(c,a[j]/d/2) printf("%c",j+'a');
				}
			}
			for(int j=n-1;j>=0;j--){
				if(j!=oddi){
					For(c,a[j]/d/2) printf("%c",j+'a');
				}
			}
		}
	}
	else{
		For(i,d/2){
			For(j,n){
				For(c,a[j]/d) printf("%c",j+'a');
			}
			for(int j=n-1;j>=0;j--){
				For(c,a[j]/d) printf("%c",j+'a');
			}
		}
	}
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