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

const int N=501000;
char s[N];
string t;
int n,cur;
VI bra;
int main() {
	scanf("%s",s);
	n=strlen(s);
	rep(i,0,n) if (s[i]=='#') {
		bra.pb(i);
		cur--;
	} else if (s[i]=='(') cur++; else cur--;
	if (cur!=0&&bra.empty()) {
		puts("-1");
		return 0;
	}
	if (cur<0) {
		puts("-1");
		return 0;
	}
	rep(i,0,n) if (s[i]=='(') t.pb('(');
	else if (s[i]==')') t.pb(')');
	else if (s[i]=='#') {
		t.pb(')');
		if (i==bra.back()) rep(j,0,cur) t.pb(')');
	}
	int cnt=0;
	rep(i,0,SZ(t)) {
		if (t[i]=='(') cnt++; else cnt--;
		if (cnt<0) {
			puts("-1");
			return 0;
		}
	}
	if (SZ(bra)) {
		rep(i,0,SZ(bra)-1) {
			puts("1");
		}
		printf("%d\n",1+cur);
	}
}