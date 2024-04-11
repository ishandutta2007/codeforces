#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

string s;
int n;
int main() {
	cin>>s;
	if (SZ(s)%2==0) {
		bool sm=1;
		rep(i,0,SZ(s)) sm&=(s[i]==s[0]);
		if (sm) {
			puts("Impossible");
			return 0;
		}
	} else {
		bool sm=1;
		rep(i,0,SZ(s)) {
			if (2*i==SZ(s)-1) continue;
			sm&=(s[i]==s[0]);
		}
		if (sm) {
			puts("Impossible");
			return 0;
		}		
	}
	n=SZ(s);
	rep(i,1,SZ(s)) {
		string l=s.substr(0,i),r=s.substr(i);
		string t=r+l;
		string t2=t; reverse(all(t));
		if (t!=s&&t==t2) {
			puts("1");
			return 0;
		}
	}
	puts("2");
}