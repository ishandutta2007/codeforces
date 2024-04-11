#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
//#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

#if 1
	#define DEB printf
#else
	#define DEB(...)
#endif

typedef long long ll;
typedef long long LL;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inft = 1000000009;
const int mod = 1000000007;
const int MAXN = 2000006;

int n;
char s[MAXN];

inline void swc(char &c) {
	if(c=='N') c='S';
	else if(c=='S') c='N';
	else if(c=='E') c='W';
	else if(c=='W') c='E';
}

vi kmp(string P) {
	P="#"+P;//wzorzec musi byc przesuniety o 1
	vi pi(P.size());
	int m=P.size()-1,q=0;
	pi[0]=pi[1]=0;
	for(int i=2;i<=m;++i) {
		while(q && P[i]!=P[q+1]) q=pi[q];
		if(P[i]==P[q+1]) ++q;
		pi[i]=q;
	}
	return pi;
}


void solve() {
	scanf("%d",&n);
	n--;
	scanf("%s",s);
	s[n] = '-';
	scanf("%s",s+n+1);
	reverse(s,s+n);
	fru(i,n) swc(s[i]);
	vi kk = kmp(string(s));
//	puts(s); for(int a : kk) printf("%d ",a); puts("");
	puts(kk.back() ? "NO" : "YES");
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}