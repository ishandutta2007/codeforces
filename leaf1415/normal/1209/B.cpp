#include <iostream>
#include <algorithm>

using namespace std;

int n;
string s;
int a[105], b[105];
bool state[105];
int N = 10000;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
	for(int i = 0; i < n; i++) state[i] = (s[i]=='1');
	
	int ans = 0;
	for(int i = 0; i < n; i++) if(state[i]) ans++;
	for(int i = 1; i <= N; i++){
		int cnt = 0;
		for(int j = 0; j < n; j++){
			if(i >= b[j] && (i-b[j])%a[j] == 0) state[j] = !state[j];
			if(state[j]) cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	
	return 0;
}