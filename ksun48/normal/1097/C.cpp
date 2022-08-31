#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 510000;

int upfreq[MAXN];
int downfreq[MAXN];

int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int ans = 0;

	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		int minsum = 0;
		int cursum = 0;
		for(char x : s){
			if(x == '('){
				cursum ++;
			} else {
				cursum --;
			}
			minsum = min(minsum, cursum);
		}
		if(minsum == 0 && cursum == 0){
			ans++;
		} else if(minsum == 0){
			upfreq[cursum]++;
		} else if(minsum == cursum){
			downfreq[-cursum]++;
		}
	}
	ans /= 2;
	for(int i = 0; i < MAXN; i++){
		ans += min(upfreq[i], downfreq[i]);
	}
	cout << ans << endl;
}