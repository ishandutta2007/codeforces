/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int MAXN = 100000+10;

int n,k,L,R;
int l[MAXN],r[MAXN],pos[MAXN],cost[MAXN];
int sum[MAXN][30];
string s;
pii range[MAXN];

int main(){
	cin >> s;
	cin >> k >> L >> R;
	for (int i=1; i<=k; i++){
		char ch;
		cin >> ch >> l[i] >> r[i];
		pos[i] = ch-'a';
		range[i]=pii(0,0);
	}
	n = (int)s.size(); 
	for (int i=1; i<=n; i++)
		for (int j=0; j<26; j++)
			sum[i][j] = sum[i-1][j] + ((s[i-1]-'a')==j);
	int cur = (L==0) * n;
	ll  ans = 0;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=k; j++){
			while (range[j].first<i)
				range[j].first++;
			range[j].first = max(range[j].first,i);
			range[j].second= max(range[j].second,i-1);
			while (range[j].first<=n && sum[range[j].first][pos[j]]-sum[i-1][pos[j]] < l[j]){
				cost[range[j].first]--;
				if (cost[range[j].first]==R) cur++;
				if (cost[range[j].first]==L-1) cur--;
				range[j].first++;
			}
			range[j].second++;
			while (range[j].second<=n && sum[range[j].second][pos[j]]-sum[i-1][pos[j]]<=r[j]){
				cost[range[j].second]++;
				if (cost[range[j].second]==L) cur++;
				if (cost[range[j].second]==R+1) cur--;
				range[j].second++;
			}
			range[j].second--;
		}
		ans+=cur;
		if (L<=cost[i] && cost[i]<=R)
			cur--;
	}
	cout << ans << endl;
	return 0;
}