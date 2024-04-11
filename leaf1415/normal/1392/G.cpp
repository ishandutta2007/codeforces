#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint n, m, k;
string s, t;
llint a[1000005], b[1000005];

llint p[25];
llint q[1000005];
int pop[1<<20];
int x[1<<20], dp[21][1<<20];

void zeta_transform(int a[], int n)
{
	int S = 1<<n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < S; j++){
			if(j&(1<<i)) a[j] = max(a[j], a[j^(1<<i)]);
		}
	}
}
void zeta_transform2(int a[], int n)
{
	int S = 1<<n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < S; j++){
			if(!(j&(1<<i))) a[j] = max(a[j], a[j^(1<<i)]);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	cin >> s >> t;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
	}
	
	llint K = 1<<k;
	for(int i = 0; i < k; i++) p[i] = i;
	for(int i = 1; i < K; i++) pop[i] = pop[i&(i-1)] + 1;
	
	for(int i = n; i >= 1; i--){
		llint mask = 0;
		for(int j = 0; j < k; j++) mask |= (t[j]%2) << p[j];
		x[mask] = max(x[mask], i);
		swap(p[a[i]], p[b[i]]);
		for(int j = 0; j < k; j++) q[i] |= (s[j]%2) << p[j];
	}
	zeta_transform2(x, k);
	for(int i = 0; i < K; i++) dp[pop[i]][i] = x[i];
	for(int i = 0; i <= k; i++) zeta_transform(dp[i], k);
	
	llint ans = -1, l, r;
	for(int i = 1; i <= n; i++){
		for(int j = k; j >= ans+1; j--){
			if(dp[j][q[i]] - i + 1 >= m){
				ans = j;
				l = i, r = dp[j][q[i]];
				break;
			}
		}
	}
	for(int i = l; i <= r; i++) swap(s[a[i]], s[b[i]]);
	
	ans = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == t[i]) ans++;
	}
	cout << ans << endl;
	cout << l << " " << r << endl;
	
	return 0;
}