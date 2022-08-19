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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int tot;
string s;
vector<string> lst,tsl,ttsl[101000];
map<string,int> faq;

int main() {
	while (cin>>s) {
		if (s=="\\begin{thebibliography}{99}") {
			break;
		}
		if (s.substr(0,6)=="\\cite{") {
			string name;
			rep(j,6,SZ(s)) {
				if (s[j]!='}') {
					name.pb(s[j]);
				} else {
					break;
				}
			}
			lst.pb(name);
		}
	}
	int tot=-1;
	while (cin>>s) {
		if (s=="\\end{thebibliography}") break;
		if (s.substr(0,9)=="\\bibitem{") {
			++tot;
			string name;
			rep(j,9,SZ(s)) {
				if (s[j]!='}') {
					name.pb(s[j]);
				} else {
					break;
				}
			}
			faq[name]=tot;
			tsl.pb(name);
		}
		ttsl[tot].pb(s);
	}
	if (lst==tsl) {
		puts("Correct");
		return 0;
	}
	puts("Incorrect");
	puts("\\begin{thebibliography}{99}");
	for (auto p:lst) {
		int id=faq[p];
		rep(j,0,SZ(ttsl[id])) printf("%s%c",ttsl[id][j].c_str()," \n"[j==SZ(ttsl[id])-1]);
	}
	puts("\\end{thebibliography}");

}