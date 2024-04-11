#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inft = 1000000009;
const int MAXN = 1000006;

vi V[26];
char s[110][110];

void imp() {
	puts("Impossible");
	exit(0);
}

void add(int a, int b) {
	int i;
	for(i=0;s[a][i] && s[b][i];i++) {
		if(s[a][i] != s[b][i]) {
			V[s[a][i]-'a'].pb(s[b][i]-'a');
			break;
		}
	}
	if(s[b][i] == 0 && s[a][i] != 0) imp();
}

void solve() {
	int n;
	scanf("%d",&n);
	fru(i,n) scanf("%s",s[i]);
	fru(i,n) if(i) add(i-1,i);
	vi st(26,0);
	fru(i,26) tr(it, V[i]) st[*it]++;
	queue<int> Q;
	fru(i,26) if(st[i]==0) Q.push(i);
	vi ans;
	while(!Q.empty()) {
		int a = Q.front();
		Q.pop();
		ans.pb(a);
		tr(it, V[a]) if((--st[*it])==0) Q.push(*it);
	}
	if(ans.size()!=26) imp();
	fru(i,26) putchar('a'+ans[i]);
	puts("");
}

int main() {
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int t=1;
//	scanf("%d",&t);
	fru(i,t) solve();
	return 0;
}