//Test
#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <climits>
#include <cassert>
#include <complex>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
 
using namespace std;
#define int long long
#define ld long double
#define F_OR(i,a,b,s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i,0,e,1)
#define F_OR2(i,e) F_OR(i,0,e,1)
#define F_OR3(i,b,e) F_OR(i,b,e,1)
#define F_OR4(i,b,e,s) F_OR(i,b,e,s)
#define GET5(a,b,c,d,e,...) e
#define F_ORC(...) GET5(__VA_ARGS__,F_OR4,F_OR3,F_OR2,F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x,a) for (auto& x: a)
 
//For integration with KACTL
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
 
 
//Reading
template<class A> void read(vector<A>& v);
template<class T> void read(T& x) {cin>>x;}
template<class H, class... T> void read(H& h, T&... t) {read(h);read(t...);}
template<class A> void read(vector<A>& x) {EACH(a, x)read(a);}
//Printing
template<class T> void write(T x){cout<<x<<" ";}
template<class A> void write(vector<A>& x) {EACH(a,x)write(a);}
template<class A> void print(vector<A>& v);
template<class T> void print(T x) {cout<<x<<"\n";}
void print(bool x){cout<<(x?"YES":"NO")<<"\n";}
void write(bool x){cout<<(x?"YES":"NO")<<" ";}
template<class H, class... T> void print(H h, T... t) {write(h);print(t...);}
template<class A> void print(vector<A>& x) {EACH(a,x)write(a);cout<<"\n";}
 
//Binary Search
//chk is a function that check if the answer is STRICTLY LESS THAN x.
 
template<class T>int bin_search(int left,int right,T chk){
   int mid;while(left<right){mid=(left+right+1)/2;if(chk(mid))right=mid-1;else left=mid;}return left;}
 
//---------------------------------------------//
//            Code begins here
//---------------------------------------------//
const int N = 1e5;
int dp[N+10][510];
void solve(){
	//write here
	int n; read(n);
	int a[n], pref[n+1];
	FOR(i,n) cin >> a[i];
	pref[0] = 0;
	FOR(i,n){
		pref[i+1] = pref[i] + a[i];
	}
	FOR(i,n){
		dp[i][0] = 0;
		dp[i][1] = a[i];
	}
	int t;
	for(t=2; t<500; t++){
		int mx = 0;
		for(int i=n-1; i>=0; i--){
			//mx = max(dp[i+t][t-1], dp[i+t+1][t-1], ..., dp[n-1][t-1])
			//take [i,i+t-1];
			if(i+t<=n && mx > pref[i+t] - pref[i]){
				dp[i][t] = pref[i+t] - pref[i];
			}
			else{
				dp[i][t] = 0;
			}
			if(i+t-1 < n && mx < dp[i+t-1][t-1]) mx = dp[i+t-1][t-1];
		}
		bool ok = false;
		FOR(i,n){
			if(dp[i][t] > 0) ok = true;
		}
		if(!ok) break;
	}
	cout << t-1 << "\n";
	//FOR(t,10){ FOR(i,n) cout << dp[i][t] << " "; cout << "\n";}
}
 
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
   	long tc=1;
   	cin >> tc; //COMMENT HERE IF A PROBLEM HAS ONLY ONE TEST CASE.
   	while(tc--){
      		solve();
 	}
	return 0;
}