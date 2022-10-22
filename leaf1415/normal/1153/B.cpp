#include <iostream>

using namespace std;

int n, m, h;
int a[105], b[105];
int c[105][105];
int ans[105][105];

int main(void)
{
	cin >> n >> m >> h;
	for(int i = 1; i <= m; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> c[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(c[i][j]) ans[i][j] = h;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			ans[i][j] = min(ans[i][j], b[i]);
		}
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			ans[j][i] = min(ans[j][i], a[i]);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}