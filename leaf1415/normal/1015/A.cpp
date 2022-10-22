#include <iostream>

using namespace std;

int n, m;
bool a[105];

int main(void)
{
	cin >> n >> m;
	int l, r;
	for(int i = 0; i < n; i++){
		cin >> l >> r;
		for(int j = l; j <= r; j++) a[j] = true;
	}
	int cnt = 0;
	for(int i = 1; i <= m; i++) if(!a[i]) cnt++;
	
	cout << cnt << endl;
	for(int i = 1; i <= m; i++){
		if(!a[i]) cout << i << " ";
	}
	cout << endl;
	return 0;
}