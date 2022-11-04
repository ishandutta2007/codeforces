#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

ll n, a[100'005], x, dp[100'005];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
 	cin >> n;
 	for (int i = 0; i < n; i++) {
 		cin >> x;
 		a[x]++;
 	}

 	dp[0] = 0;
 	dp[1] = a[1];
 	dp[2] = a[2] * 2;

 	for (int i = 3; i <= 100'000; i++)
 		dp[i] = a[i] * i + max(dp[i-2], dp[i-3]);

 	cout << max(dp[100'000], dp[99'999]) << endl;

    return 0;
}