#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <int, int> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf =1e9+9;
const ll mod = 1e9+9;
const ll MOD = 1e9+696969;
int n, m, k, a, b,maks, DL = 0, CC = 0, T;
#define maxn 200100
int parent[maxn], l;
int partial[maxn], arr[maxn];
bool odw[maxn];
int zlicz[maxn];

int LeafCount() {
	FOR(i, 1, n) odw[i] = 0;
	FOR(i, 1, n) odw[parent[i]] = 1;
	int cnt = 0;
	FOR(i, 2, n)
	  if (!odw[i]) ++cnt;
	return cnt;
}

void przepnij(int x, int y) {
	zlicz[parent[x]]--;
	parent[x] = y;
	zlicz[parent[x]]++;
	l--;
}
set <int> dobre[maxn];
int layer[maxn];
int main() 
{
	boost;
	cin >> n >> maks >> k;
	partial[0] = 1;
	int M = 0;
	FOR(i, 1, maks) {
		cin >> arr[i];
		M = max(M, arr[i]);
		partial[i] = partial[i-1] + arr[i];
	}
	
	int wsk = 2;
	FOR(i, 1, maks){ 
		while (wsk <= partial[i]) {
			parent[wsk] = partial[i - 1];
			layer[wsk] = i;
			++wsk;
		}
	}
	
	l = LeafCount();

	if (k > l) OUT(-1);
	
	FOR(i, 1, n) {
		zlicz[parent[i]]++;
		if (zlicz[parent[i]] > 1) dobre[layer[i]].insert(i);
	}

	FOR(i, 2, n) {
		if (!zlicz[i] && l > k) {
			int lay = layer[i];
			if (dobre[lay + 1].empty()) continue;
			else {
				int w = *dobre[lay + 1].begin();
				dobre[lay + 1].erase(w);
				przepnij(w, i);
			}
		}
	}
	
	if (LeafCount() != k) OUT(-1);
	cout << n << endl;
	FOR(i, 2, n) cout << parent[i] << ' ' << i << "\n";
}