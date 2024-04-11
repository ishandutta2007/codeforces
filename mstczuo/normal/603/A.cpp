# include <iostream>

using namespace std;

char a[100010];

int main() {
	int n;
	scanf("%d%s", &n, a+1); 
	
	int ans = 1;
	for(int i = 2; i <= n; ++i)
		ans += (a[i] != a[i-1]);
	int cnt = 0;
	for(int i = 2; i <= n; ++i)
		if(a[i] == a[i-1]) cnt += 1;
	cout << ans + min(cnt, 2) << endl;
	return 0;
}