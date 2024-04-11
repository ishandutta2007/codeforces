#include <iostream>
#include <vector>
#define inf 1e9

using namespace std;

int n, m;
int a[100005];
int l[305], r[305];
int dif[100005], g[100005];
int mx[605], mn[605];

int main(void)
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> l[i] >> r[i];
	
	if(n == 1){
		cout << 0 << endl;
		cout << 0 << endl;
		return 0;
	}
	
	for(int i = 1; i <= m; i++) dif[l[i]] = dif[r[i]+1] = 1;
	for(int i = 1; i <= n; i++) g[i] = g[i-1] + dif[i];
	int G = g[n];
	
	for(int i = 1; i <= m; i++){
		l[i] = g[l[i]];
		r[i] = g[r[i]];
	}
	
	for(int i = 0; i < 605; i++){
		mx[i] = -inf, mn[i] = inf;
	}
	for(int i = 1; i <= n; i++){
		mx[g[i]] = max(mx[g[i]], a[i]);
		mn[g[i]] = min(mn[g[i]], a[i]);
	}
	
	int ans = -inf, ans_i, ans_j;
	for(int i = 0; i <= G; i++){
		for(int j = 0; j <= G; j++){
			int sum = mx[i] - mn[j];
			for(int k = 1; k <= m; k++){
				if((i < l[k] || i > r[k]) && (j >= l[k] && j <= r[k])) sum++;
			}
			if(ans < sum){
				ans = sum;
				ans_i = i;
				ans_j = j;
			}
		}
	}
	
	cout << ans << endl;
	vector<int> vec;
	for(int k = 1; k <= m; k++){
		if((ans_i < l[k] || ans_i > r[k]) && (ans_j >= l[k] && ans_j <= r[k])) vec.push_back(k);
	}
	cout << vec.size() << endl;
	for(int i = 0; i < vec.size(); i++) cout << vec[i] << " "; cout << endl;
	
	return 0;
}