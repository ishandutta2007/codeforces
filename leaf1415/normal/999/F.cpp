#include <iostream>
#include <map>

using namespace std;

int n, k;
map<int, int> cmap, fmap;
int h[15];
int dp[505][5005];

int calc(int fnum, int cnum)
{
	for(int i = 0; i <= fnum; i++){
		for(int j = 0; j <= cnum; j++){
			dp[i][j] = 0;
		}
	}
	for(int i = 0; i < fnum; i++){
		for(int j = 0; j <= cnum; j++){
			for(int l = 0; l <= min(cnum-j, k); l++){
				dp[i+1][j+l] = max(dp[i+1][j+l], dp[i][j] + h[l]);
			}
		}
	}
	return dp[fnum][cnum];
}

int main(void)
{
	cin >> n >> k;
	int c;
	for(int i = 0; i < n*k; i++){
		cin >> c;
		cmap[c]++;
	}
	int f;
	for(int i = 0; i < n; i++){
		cin >> f;
		fmap[f]++;
	}
	for(int i = 1; i <= k; i++) cin >> h[i];
	
	int ans = 0;
	for(auto it = fmap.begin(); it != fmap.end(); it++){
		int fnum = it->second, cnum = cmap[it->first];
		cnum = min(cnum, fnum*k);
		ans += calc(fnum, cnum);
	}
	cout << ans << endl;
	return 0;
}