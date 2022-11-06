#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
bool cmp(string a, string b) {
	return a+b < b+a;
}
int main() {
	ios_base::sync_with_stdio(false);
	ll n; cin>>n;
	vector<string> v;
	for (ll i=0;i<n;i++) {
		string s; cin>>s;
		v.PB(s);
	}
	sort(v.begin(),v.end(), cmp);
	for (ll i=0;i<n;i++) {
		cout<<v[i];
	}
	cout<<endl;
}