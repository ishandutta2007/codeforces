#include <iostream>
#include <string>
#define llint long long

using namespace std;

int T, n;
int a[3];
int dp[105][105][105];
int rep[105][105][105];
string s, u = "RPS";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> n;
		cin >> a[0] >> a[1] >> a[2];
		cin >> s;
		
		int b[3] = {0, 0, 0};
		for(int i = 0; i < s.size(); i++){
			if(s[i] == 'R') b[0]++;
			if(s[i] == 'P') b[1]++;
			if(s[i] == 'S') b[2]++;
		}
		int ans = 0;
		ans += min(b[0], a[1]);
		ans += min(b[1], a[2]);
		ans += min(b[2], a[0]);
		
		if(ans < (n+1)/2){
			cout << "NO" << endl;
			continue;
		}
		
		string t = s;
		for(int i = 0; i < n; i++) t[i] = ' ';
		for(int i = 0; i < n; i++){
			if(s[i] == 'R' && a[1]) t[i] = 'P', a[1]--;
			if(s[i] == 'P' && a[2]) t[i] = 'S', a[2]--;
			if(s[i] == 'S' && a[0]) t[i] = 'R', a[0]--;
		}
		for(int i = 0; i < n; i++){
			if(t[i] != ' ') continue;
			for(int j = 0; j < 3; j++){
				if(a[j]){
					a[j]--, t[i] = u[j];
					break;
				}
			}
		}
		cout << "YES" << endl;
		cout << t << endl;
	}
	
	return 0;
}