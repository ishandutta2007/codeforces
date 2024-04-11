#include <iostream>
#include <string>
#define llint long long

using namespace std;

llint T;
llint n, m, k;
llint h[105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> m >> k;
		for(int i = 1; i <= n; i++) cin >> h[i];
		
		for(int i = 1; i < n; i++){
			llint H = max(h[i+1]-k, 0LL);
			m += h[i] - H;
			if(m < 0){
				cout << "NO" << "\n";
				goto end;
			}
		}
		cout << "YES" << "\n";
		end:;
	}
	
	return 0;
}