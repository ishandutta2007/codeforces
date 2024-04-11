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
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;

int n,m,k,a,b,c;
#define maxn 1000100
int t[maxn], A[maxn];

PII przedzial[maxn];

int main()
{
	boost;
	cin >> n;
	int s1 = 0, sum = 0;
	FOR(i, 1, n) {
		cin >> A[i];
		s1 += A[i];
	}
	
	cin >> k;
	FOR(i, 1, k) {
		cin >> t[i];
		sum += t[i];
	}
	if (sum != s1) OUT("NO");
	sum = 0;

	przedzial[0] = mp(0, 0);
	FOR(i, 1, k) {
		int x = przedzial[i-1].e2 + 1;
		sum = A[x];
		while (sum < t[i]) {
			++x;
			sum += A[x];
		}
		if (sum != t[i]) OUT("NO");
		przedzial[i] = mp(przedzial[i-1].e2 + 1, x);
	}
	
	bool answer = 1;
	FOR(i, 1, k) {
		bool ans = 0;
		int value = A[przedzial[i].e1];
		if (przedzial[i].e1 == przedzial[i].e2) continue;
		FOR(j, przedzial[i].e1, przedzial[i].e2)
		  if (value != A[j]) ans = 1;
		
		answer &= ans;
	}
	if (!answer) OUT("NO");
	//it's always possible
	cout << "YES\n";
	FOR(i, 1, k) {
		int start = i - 1;
		int x = przedzial[i].e1, y = przedzial[i].e2;
		int mx = A[x];
		FOR(j, x, y)
		  mx = max(mx, A[j]);
		int place = x;
		
		FOR(j, x+1, y)
		  if (mx == A[j] && A[j-1] < mx) {
			  place = j;
			  break;
		  }
		
		FOR(j, x, y-1)
		  if (mx == A[j] && A[j + 1] < mx) {
			  place = -j;
			  break;
		  }
		
		if (place < 0) {
			place = -place;
			int ktore = place - (x - 1);
			//starting from right eating
			
			FOR(j, place+1, y) cout << start + ktore << " R\n";
			int rem = 0;
			for (int j=place-1; j>=x; --j) {
				++rem;
				cout << start + ktore - rem + 1 << " L\n";
			}
		}
		else {
			int ktore = place - (x - 1);
			//left eating first
			int rem = 0;
			for (int j=place-1; j>=x; --j) {
				++rem;
				cout << start + ktore - rem + 1 << " L\n";
			}
			FOR(j, place+1, y) cout << i << " R\n";
		}
	}
}