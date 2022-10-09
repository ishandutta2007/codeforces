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
int A[maxn], B[maxn];

int main()
{
	boost;
	cin >> n;
	int result = 0;
	int wyn = 0;
	FOR(i, 1, n) {
		cin >> A[i] >> B[i];
		wyn += A[i]; wyn -= B[i];
	}
	

	result = abs(wyn);
	int col = 0;
	
	FOR(i, 1, n) {
		int temp = wyn - A[i] + B[i] + B[i] - A[i];
		if (abs(temp) > result) {
			col = i;
			result = abs(temp);
		}
	}
	cout << col;
}