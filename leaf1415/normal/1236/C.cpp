#include <iostream>
#define llint long long

using namespace std;

llint n;
llint ans[305][305];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		if(i % 2){
			for(int j = 1; j <= n; j++){
				ans[j][i] = (i-1)*n+j;
			}
		}
		else{
			for(int j = 1; j <= n; j++){
				ans[n+1-j][i] = (i-1)*n+j;
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}