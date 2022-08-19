#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <iostream>
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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

string p,q,s;
string input() {
	string t;
	cin>>s;
	if (s[0]!='X') t.pb(s[0]);
	if (s[1]!='X') t.pb(s[1]);
	cin>>s;
	if (s[1]!='X') t.pb(s[1]);
	if (s[0]!='X') t.pb(s[0]);
	return t;
}
int main() {
	p=input();
	q=input();
	rep(i,0,3) {
		bool ck=1;
		rep(j,0,3) ck&=(p[j]==q[(i+j)%3]);
		if (ck) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}