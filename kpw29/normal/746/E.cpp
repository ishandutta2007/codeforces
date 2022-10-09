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
#define maxn 1001000
int arr[maxn];
map<int, int> M;
bool toex[maxn];
set <int> odd, even;
int endd[maxn];
int main() {
	boost;
	cin >> n >> m;
	m = min(m, 2 * n + 3);
	FOR(i, 1, n) {
		cin >> arr[i];
		endd[i] = arr[i];
		if (M[arr[i]] > 0) toex[i] = 1;
		M[arr[i]]++;
	}
	
	FOR(i, 1, m)
	 if (M[i] == 0) {
		 if (i & 1) odd.insert(i);
		 else even.insert(i);
	 }
	
	int licz = 0;
	FOR(i, 1, n) {
		if (!toex[i] && arr[i] % 2 == 1) ++licz;
		if (!toex[i] && arr[i] % 2 == 0) --licz;
	}

	FOR(i, 1, n) {
		if (toex[i]) {
			if (licz < 0 && !odd.empty()) {
				arr[i] = *odd.begin();
				odd.erase(odd.begin());
				++licz;
			}
			else if (!even.empty()) {
				arr[i] = *(even.begin());
				even.erase(even.begin());
				--licz;
			}
			else if (odd.empty()) {cout << -1; exit(0); }
			else {
				arr[i] = *odd.begin();
				odd.erase(odd.begin());
				++licz;
			}
		}
	}
		
	FOR(i, 1, n) {
		if (licz > 0) {
		  if (!toex[i] && arr[i] % 2 == 1) {
			 if (!even.empty()) {
				arr[i] = *(even.begin());
				even.erase(even.begin());
				licz -= 2;
			 }
		  }
	  }
	  else if (licz < 0) {
		  if (!toex[i] && arr[i] %2 == 0) {
			  if (!odd.empty()) {
				arr[i] = *odd.begin();
				odd.erase(odd.begin());
				licz += 2;
			}
		  }
	  }
	}

	if (licz != 0) OUT(-1);
	
	int ww = 0;
	FOR(i, 1, n)
	  if (arr[i] != endd[i]) ++ww;
	
	cout << ww << endl;
	FOR(i, 1, n) cout << arr[i] << ' ';
}