#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstdio>
#define llint long long
#define inf 1e18
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;

int n, m;
int a[5005];
int sum[5005][5005];
vector<llint> vec[5005];
bool b[5005][5005];
int bsum[5005][5005];
llint ans[5005];

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	//cin >> n >> m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]); //cin >> a[i];
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			sum[i][j] = sum[i][j-1];
			if(a[j] == i) sum[i][j]++;
		}
	}
	
	int f, h;
	for(int i = 1; i <= m; i++){
		//cin >> f >> h;
		scanf("%d %d", &f, &h);
		vec[f].push_back(h);
		b[f][h] = true;
	}
	for(int i = 1; i <= n; i++) sort(vec[i].begin(), vec[i].end());
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			bsum[i][j] = bsum[i][j-1];
			if(b[i][j]) bsum[i][j]++;
		}
	}
	
	/*int mx = 0;
	for(int i = 0; i <= n; i++){
		int tmp = 0;
		for(int j = 1; j <= n; j++){
			llint x = inf, y = inf;
			if(vec[j].size() >= 1) x = vec[j][0];
			if(vec[j].size() >= 2) y = vec[j][1];
			if(x > y) swap(x, y);
			
			llint l = sum[j][i], r = sum[j][n]-sum[j][i];
			if(l > r) swap(l, r);
			if(x <= l && y <= r) tmp += 2;
			else if(x <= r) tmp++;
		}
		mx = max(mx, tmp);
	}*/
	
	llint mx = 0;
	for(int i = 0; i <= n; i++){
		llint col = a[i], ord = sum[col][i];
		if(col > 0 && !b[col][ord]) continue;
		
		llint cnt = 0, tmp = 1;
		for(int j = 1; j <= n; j++){
			if(j == col){
				llint x = ord, y = inf;
				if(vec[j].size() >= 2){
					y = vec[j][0];
					if(x == y) y = vec[j][1];
				}
				llint r = sum[j][n]-sum[j][i];
				
				//cout << "!" << x << " " << y << endl;
				
				if(y <= r){
					cnt += 2;
					if(ord <= r) tmp *= (llint)bsum[j][r]-1, tmp %= mod;
					else tmp *= bsum[j][r], tmp %= mod;
				}else cnt++;
			}
			else{
				llint x = inf, y = inf;
				if(vec[j].size() >= 1) x = vec[j][0];
				if(vec[j].size() >= 2) y = vec[j][1];
				if(x > y) swap(x, y);
				llint l = sum[j][i], r = sum[j][n]-sum[j][i];
				if(l > r) swap(l, r);
				if(x <= l && y <= r){
					cnt += 2;
					tmp *= (llint)bsum[j][l] * ((llint)bsum[j][r]-1) % mod, tmp %= mod;
				}else if(x <= r){
					cnt++;
					tmp *= bsum[j][l] + bsum[j][r], tmp %= mod;
				}
			}
		}
		ans[cnt] += tmp;
		if(ans[cnt] >= mod) ans[cnt] -= mod;
		mx = max(mx, cnt);
	}
	
	//for(int i = 0; i <= n; i++) cout << ans[i] << " "; cout << endl;
	//cout << mx << endl;
	
	cout << mx << " " << ans[mx] << endl;
	
	return 0;
}