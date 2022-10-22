#include <iostream>

using namespace std;

int n, m;
int a[105], b[105];
int ans[31][105][105];

int main(void)
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> b[i];
	
	int x = 0;
	for(int i = 1; i <= n; i++) x ^= a[i];
	for(int i = 1; i <= m; i++) x ^= b[i];
	if(x != 0){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	
	for(int p = 0; p < 31; p++){
		int nx = 1;
		for(int i = 1; i <= n; i++){
			if((a[i] & (1<<p)) == 0) continue;
			int t = -1;
			for(int j = nx; j <= m; j++){
				if(b[j] & (1<<p)){
					t = j;
					break;
				}
			}
			if(t != -1){
				ans[p][i][t] ^= 1;
				a[i] &= ~(1<<p);
				b[t] &= ~(1<<p);
				nx = t+1;
			}
		}
		for(int i = 1; i <= n; i++){
			if((a[i] & (1<<p))) ans[p][i][1] ^= 1;
		}
		for(int i = 1; i <= m; i++){
			if((b[i] & (1<<p))) ans[p][1][i] ^= 1;
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int val = 0;
			for(int k = 0; k < 31; k++){
				val ^= (ans[k][i][j]<<k);
			}
			cout << val << " ";
		}
		cout << endl;
	}
	return 0;
}