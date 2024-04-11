#include <iostream>
#include <vector>
#define llint long long 

using namespace std;

int n, c;
int a[500005];
int csum[500005], sum[500005], mx[500005];
vector<int> vec[500005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> c;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int num = 0, ans = 0;
	for(int i = 1; i <= n; i++) if(a[i] == c) num++;
	for(int i = 1; i <= n; i++){
		csum[i] = csum[i-1];
		if(a[i] == c) csum[i]++;
	}
	ans = min(num+1, n);
	
	for(int i = 1; i <= n; i++) vec[a[i]].push_back(i);
	
	for(int i = 1; i <= 500000; i++){
		if(i == c || (int)vec[i].size() == 0) continue;
		sum[0] = 0;
		for(int j = 0; j < (int)vec[i].size(); j++){
			sum[j+1] = sum[j] + 1 - csum[vec[i][j]];
			if(j > 0) sum[j+1] += csum[vec[i][j-1]-1];
		}
		mx[(int)vec[i].size()+1] = -1e9;
		for(int j = vec[i].size(); j >= 0; j--){
			mx[j] = max(mx[j+1], sum[j]);
		}
		for(int j = 0; j < vec[i].size(); j++){
			if(j > 0) ans = max(ans, num + mx[j+1] - sum[j] + 1);
			else ans = max(ans, num + mx[j+1] - sum[j]);
		}
	}
	cout << ans << endl;
	
	return 0;
}