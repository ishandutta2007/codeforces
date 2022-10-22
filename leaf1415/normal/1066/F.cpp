#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define llint long long

using namespace std;

llint n;
llint x[200005], y[200005];
map<llint, vector<llint>> mp;
llint px[200005][2], py[200005][2];
llint len[200005];
llint dp[200005][2];

llint dist(llint x, llint y, llint a, llint b){
	return abs(x-a) + abs(y-b);
}

void recover(llint mx, llint dif, llint &x, llint &y)
{
	if(dif >= 0) x = mx, y = x - dif;
	else y = mx, x = dif + y;
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	
	for(int i = 1; i <= n; i++) mp[max(x[i],y[i])].push_back(x[i]-y[i]);
	for(auto it = mp.begin(); it != mp.end(); it++){
		sort(it->second.begin(), it->second.end());
	}
	int i = 1;
	for(auto it = mp.begin(); it != mp.end(); it++){
		llint x, y;
		recover(it->first, it->second.front(), px[i][0], py[i][0]);
		recover(it->first, it->second.back(), px[i][1], py[i][1]);
		for(int j = 0; j < it->second.size()-1; j++){
			llint x, y, nx, ny;
			recover(it->first, it->second[j], x, y);
			recover(it->first, it->second[j+1], nx, ny);
			len[i] += dist(x, y, nx, ny);
		}
		i++;
	}
	int n = mp.size();
	
	/*for(int i = 1; i <= n; i++){
		cout << px[i][0] << " " << py[i][0] << endl;
	}*/
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < 2; j++){
			dp[i][j] = 1e18;
		}
	}
	dp[0][0] = dp[0][1] = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				llint cost = dist(px[i][j], py[i][j], px[i+1][1-k], py[i+1][1-k]) + len[i+1];
				dp[i+1][k] = min(dp[i+1][k], dp[i][j] + cost);
			}
		}
	}
	
	
	/*for(int i = 0; i <= n; i++){
		for(int j = 0; j < 2; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	
	cout << min(dp[n][0], dp[n][1]) << endl;
	return 0;
}