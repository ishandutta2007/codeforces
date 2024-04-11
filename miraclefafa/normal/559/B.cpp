#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

string s,t;
string gao(string a) {
	if (SZ(a)%2==1) return a;
	else {
		string a1="";
		rep(i,0,SZ(a)/2) a1.pb(a[i]);
		string s1=gao(a1);
		a1.clear();
		rep(i,SZ(a)/2,SZ(a)) a1.pb(a[i]);
		string s2=gao(a1);
		if (s1<s2) return s1+s2; else return s2+s1;
	}
}
int main() {
	cin>>s>>t;
	puts(gao(s)==gao(t)?"YES":"NO");
}