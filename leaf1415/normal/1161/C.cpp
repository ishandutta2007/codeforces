#include <iostream>

using namespace std;

int n;
int a[55];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int mn = 55;
	for(int i = 1; i <= n; i++) mn = min(mn, a[i]);
	int cnt = 0;
	for(int i = 1; i <= n; i++) if(a[i] == mn) cnt++;
	if(cnt > n/2) cout << "Bob" << endl;
	else cout << "Alice" << endl;
	
	return 0;
}