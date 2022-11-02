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

const int inft = 100000008;
const int MAXN = 3100;

int n;
vi V[MAXN], B1, B2, C1, C2;

void bfs(int s, vi &B) {
	B.resize(n);
	fru(i,n) B[i] = inft;
	B[s] = 0;
	queue<int> Q;
	Q.push(s);
	while(!Q.empty()) {
		s = Q.front();
		Q.pop();
		int d = B[s];
		tr(it,V[s]) if(B[*it] == inft) {
			B[*it] = d+1;
			Q.push(*it);
		}
	}
//	fru(i,n) printf("%d ",B[i]); puts("");
}

int bfs2(int s1, int t1, int l1, int s2, int t2, int l2) {
	vi BB;
	int ans = inft;
	assert(B1[t1] == C1[s1]);
	assert(B2[t2] == C2[s2]);
	if(B1[t1]<=l1 && B2[t2]<=l2) ans = min(ans, B1[t1]+B2[t2]);
	fru(s,n) {
		bfs(s, BB);
		fru(j,n) if(B1[s]+BB[j]+C1[j]<=l1 && B2[s]+BB[j]+C2[j]<=l2) {
//			printf("for %d -> %d got %d\n", s, j, B1[s]+B2[s]+BB[j]+C1[j]+C2[j]);
			ans = min(ans, B1[s]+B2[s]+BB[j]+C1[j]+C2[j]);
		}
	}
	return ans;
}

void solve() {
	int m;
	scanf("%d%d",&n,&m);
	fru(j,m) {
		int a,b;
		scanf("%d%d",&a,&b);
		a--; b--;
		V[a].pb(b);
		V[b].pb(a);
	}
	int s1,t1,l1,s2,t2,l2;
	scanf("%d%d%d",&s1,&t1,&l1);
	scanf("%d%d%d",&s2,&t2,&l2);
	s1--; s2--; t1--; t2--;
	bfs(s1,B1);
	bfs(s2,B2);
	bfs(t1,C1);
	bfs(t2,C2);
	int ans1 = bfs2(s1,t1,l1,s2,t2,l2);
	swap(B2,C2);
	int ans2 = bfs2(s1,t1,l1,t2,s2,l2);
	int ans = min(ans1,ans2);
	if(ans >= inft) ans = m+1;
	printf("%d\n", m-ans);
}

int main() {
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int t=1;
//	scanf("%d",&t);
	fru(i,t) solve();
	return 0;
}