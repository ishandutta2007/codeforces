#include <iostream>

using namespace std;

int n, a, b;
char seat[200005];

int main(void)
{
	cin >> n >> a >> b;
	for(int i = 0; i < n; i++) cin >> seat[i];
	seat[n] = '*';
	
	int pair = 0, free = 0;
	int cnt = 0;
	for(int i = 0; i <= n; i++){
		if(seat[i] == '.') cnt++;
		else{
			pair += cnt/2;
			free += cnt%2;
			cnt = 0;
		}
	}
	
	int ans = 0;
	int p = min(pair, min(a, b));
	ans += p * 2;
	a -= p, b -= p;
	free += pair-p;
	ans += min(free, a+b);
	cout << ans << endl;
	
	return 0;
}