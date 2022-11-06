#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
int main() {
	ios_base::sync_with_stdio(false);
	ll n,a,b; cin>>n>>a>>b;
	a--;
	a=(a+b+n)%n;
	while(a<0) a+=n;
	a++;
	cout<<a<<endl;
}