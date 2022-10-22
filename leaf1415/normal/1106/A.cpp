#include <iostream>

using namespace std;

int n;
char a[505][505];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j] == 'X' && a[i-1][j-1] == 'X' && a[i-1][j+1] == 'X' && 
				a[i+1][j-1] == 'X' && a[i+1][j+1] == 'X') ans++;
		}
	}
	cout << ans << endl;
	return 0;
}