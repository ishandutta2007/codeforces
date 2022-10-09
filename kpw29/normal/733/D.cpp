#include <bits/stdc++.h>
#include <string>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned int ull;
typedef pair <int, int> PII;
typedef pair <PII, int> PPI;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
typedef unsigned int ui;
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;

int n,m,k,a,b,c;
#define maxn 1000100
int t[maxn], A[maxn], B[maxn], C[maxn];
vector <PP> some;

int main()
{
	boost;
	cin >> n;
	if (n == 1) OUT("1\n1");
	FOR(i, 1, n) cin >> A[i] >> B[i] >> C[i];
	FOR(i, 1, n) 
	{
		if (A[i] > B[i]) swap(A[i], B[i]);
		if (A[i] > C[i]) swap(A[i], C[i]);
		if (B[i] > C[i]) swap(B[i], C[i]);
		//quasi sort
		
		some.pb({mp(A[i], B[i]), mp(C[i], i)});
		if (A[i] != C[i]) some.pb({mp(A[i], C[i]), mp(B[i], i)});
		if (A[i] != C[i]) some.pb({mp(B[i], C[i]), mp(A[i], i)});
	}
	
	ll wyn = 0;
	PII res = {0, 0};
	
	sort(some.begin(), some.end());
	int sz = some.size();
	FOR(i, 1, sz-1)
		if (some[i].e1.e1 == some[i-1].e1.e1 && some[i].e1.e2 == some[i-1].e1.e2) {
			ll w = min(some[i].e1.e1, some[i].e1.e2);
			w = min(w, (ll)some[i].e2.e1 + some[i-1].e2.e1);
			if (w > wyn) wyn = w, res = {some[i-1].e2.e2, some[i].e2.e2};
		}
	
	ll ww = 0;
	
	int wyp = 0;
	FOR(i, 0, sz-1) {
		int w = min(some[i].e1.e1, some[i].e1.e2);
		w = min(w, some[i].e2.e1);
		if (w > ww) wyp = some[i].e2.e2, ww = w;
	}
	if (wyn > ww) {
		cout << 2 << endl;
		cout << res.e1 << ' ' << res.e2;
		exit(0);
	}
	
	cout << 1 << endl;
	cout << wyp;
}