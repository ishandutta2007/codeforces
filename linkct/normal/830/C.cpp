#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long int LL;
typedef pair <LL, int> pii;
const int MAXN = 105;

int n, a[MAXN], last[MAXN]; LL k;
vector <pii> num; vector <int> val[MAXN];

int main(){
	int i, j, border; LL sum = 0LL, ans = 0LL;
	cin >> n >> k;
	for(i = 1; i <= n; ++ i){
		cin >> a[i]; k += a[i], sum += a[i];
		for(j = 1; j < a[i]; j = border + 1){
			val[i].push_back((a[i] + j - 1) / j);
			border = (a[i] - 1) / (val[i].back() - 1);
			num.push_back(pii(border + 1, i));
		} val[i].push_back(1);
		//reverse(val[i].begin(), val[i].end());
	} sort(num.begin(), num.end());
	num.push_back(pii(1e13 + 1, 0));
	if(sum <= k) ans = min(k / sum, num[0].fi - 1);
	for(i = 0; i < int(num.size()) - 1; i = j){
		for(j = i; num[j].fi == num[i].fi; ++ j){
			sum -= val[num[j].se][last[num[j].se]];
			sum += val[num[j].se][++ last[num[j].se]];
		} if(sum * num[i].fi > k) continue;
		ans = max(ans, min(k / sum, num[j].fi - 1));
	} cout << ans << endl;
	return 0;
}