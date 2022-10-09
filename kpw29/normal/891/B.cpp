#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define e1 first
#define e2 second
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define boost ios_base::sync_with_stdio(0); cin.tie(0)
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <int, PII> PIP;
typedef pair <PII, int> PPI;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 4e18 + 3;
const int maxn = 25;
int B[maxn], n;
PII A[maxn];
int t[maxn];
map <ll, int> M;

bool check() {
	M.clear();
	FOR(i, 1, n) {
		t[i] = A[i].e1 - B[i];
		if (t[i] == 0) return 0;
	}
	
	int half = (n / 2);
	int pow = (1 << half);
	for (int i=1; i < pow; ++i) {
		ll sum = 0;
		for (int j = 0; j < half; ++j)
			if (i & (1 << j)) sum += t[1 + j];
		
		if (sum == 0) return 0;
		M[sum]++;
	}
	
	int st = half + 1; half = n - half;
	pow = (1 << half);
	ll overall = 0;
	for (int i=1; i < pow; ++i) {
		ll sum = 0;
		for (int j = 0; j < half; ++j)
			if (i & (1 << j)) sum += t[st + j];
		if (sum == 0) return 0;
		overall += M[-sum];
		if (overall > 1) return 0;
	}
	return 1;
}

int wynik[maxn];
bool cmp(PII a, PII b) {
	return a.e2 < b.e2;
}

void reprint() {
	FOR(i, 1, n) wynik[A[i].e2] = B[i];
	sort(A + 1, A + n + 1, cmp);
	FOR(i, 1, n) B[i] = wynik[i];
	assert(check());
	FOR(i, 1, n) cout << wynik[i] << ' ';
	exit(0);
}

int main()
{
	cin >> n;
	FOR(i, 1, n) {
		cin >> A[i].e1;
		B[i] = A[i].e1;
		A[i].e2 = i;
	}
	if(n==1) OUT(B[1]);
	sort(A+1, A+n+1);
	sort(B+1, B+n+1);
	int maks = 0, ile = 0;
	FOR(i, 1, n) {
		if (B[i] == B[i-1]) ++ile;
		else ile = 1;
		maks = max(maks, ile);
	}
	if (2 * maks > n) OUT(-1);
	FOR(i, 1, n) B[i] = A[i].e1;
	FOR(p, 1, n) {
		//shift();
		for (int i=n+1; i>=0; --i) B[i] = B[i-1];
		B[1] = B[n+1];
		if (check()) {
			reprint();
		}
	}
	OUT(-1);
}