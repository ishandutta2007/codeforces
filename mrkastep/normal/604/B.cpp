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

const int INF=1e9; 
const int mod=1e9+7; 
const ll LONGINF=4e18; 
const double eps=1e-9; 
const double PI=3.1415926535897932384626433832795;

int s[100100];

multimap<int,int> m;

void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	For(i,n) scanf("%d",&s[i]);
	int l=0,r=2002000;
	while(r-l>1){
		int c=(l+r)/2;
		For(i,n) m.insert(mp(s[i],1));
		int ans=0;
		while(!m.empty()){
			ans++;
			int t=c-m.rbegin()->x;
			if(t<0) ans=INF;
			m.erase(prev(m.end()));
			if(!m.empty()){
				auto it=m.upper_bound(t);
				if(it!=m.begin()){
					m.erase(prev(it));
				}
			}
		}
		if(ans>k) l=c;
		else r=c;
	}
	printf("%d",r);



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