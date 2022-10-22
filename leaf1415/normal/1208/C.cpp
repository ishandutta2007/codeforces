#include <iostream>
#include <set>
#define llint long long

using namespace std;

llint n;
llint ans[1005][1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i = 0; i < n/4; i++){
		for(int j = 0; j < n/4; j++){
			llint b = (i*(n/4)+j)*16;
			for(int y = 0; y < 4; y++){
				for(int x = 0; x < 4; x++){
					ans[i*4+y][j*4+x] = b + (y*4+x);
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	flush(cout);
	
	return 0;
}