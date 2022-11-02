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

const int M1 = 1000000009;
const int M2 = 578349841;

const pii W = pii(1423423,8987347);
const pii W2 = pii(218472383,21093891);

map<string,int> ms;
map<pii,int> mp;

int hash(const string &s, int a, int b) {
	if((b-a)%2) {
		string ss = s.substr(a,b-a);
		if(ms.find(ss)==ms.end()) {
			int v = ms.size();
			ms[ss] = v;
		}
		return ms.find(ss)->y;
	} else {
		int mid = a+(b-a)/2;
		int h1 = hash(s, a, mid);
		int h2 = hash(s, mid, b);
		if(h2<h1) swap(h1,h2);
		pii h = pii(h1,h2);
		if(mp.find(h)==mp.end()) {
			int v = mp.size()+inft;
			mp[h]=v;
		}
		return mp.find(h)->y;
	}
}


void solve() {
	string s1,s2;
	cin>>s1>>s2;
	if(hash(s1,0,s1.size())==hash(s2,0,s2.size())) puts("YES");
	else puts("NO");
}

int main() {
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int t=1;
//	scanf("%d",&t);
	fru(i,t) solve();
	return 0;
}