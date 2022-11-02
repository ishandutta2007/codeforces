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

void makemove(set<int> &S, multiset<int> &M, int x) {
	set<int>::iterator it1 = S.lower_bound(x);
	set<int>::iterator it2 = it1--;
	int x1=*it1, x2=*it2;
	M.erase(M.find(x2-x1));
	M.insert(x-x1);
	M.insert(x2-x);
	S.insert(x);
}

void solve() {
	int w,h,n;
	scanf("%d%d%d",&w,&h,&n);
	set<int> S[2];
	S[0].insert(0); S[0].insert(w);
	S[1].insert(0); S[1].insert(h);
	multiset<int> M[2];
	M[0].insert(w); M[1].insert(h);
	fru(_,n) {
		char c; int x;
		scanf(" %c %d",&c,&x);
		if(c=='V') makemove(S[0],M[0],x);
		if(c=='H') makemove(S[1],M[1],x);
		printf("%lld\n", 1LL*(*M[0].rbegin())*(*M[1].rbegin()));
	}
}

int main() {
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int t=1;
//	scanf("%d",&t);
	fru(i,t) solve();
	return 0;
}