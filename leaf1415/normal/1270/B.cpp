#include <iostream>
#include <cstdlib>
#define llint long long

using namespace std;

llint T;
llint n;
llint a[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n-1; i++){
			if(abs(a[i]-a[i+1]) >= 2){
				cout << "YES" << "\n";
				cout << i << " " << i+1 << "\n";
				goto end;
			}
		}
		cout << "NO" << "\n";
		end:;
	}
	flush(cout);
	
	return 0;
}