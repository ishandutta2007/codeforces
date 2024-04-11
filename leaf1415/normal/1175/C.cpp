#include <iostream>
#include <string>
#include <stack>
#define llint long long

using namespace std;

llint T;
llint n, k;
llint a[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		for(int i = 0; i < n; i++) cin >> a[i];
		
		llint mn = 1e18, mn_i;
		for(int i = 0; i+k < n; i++){
			if(mn > a[i+k]-a[i]){
				mn = a[i+k]-a[i];
				mn_i = i;
			}
		}
		cout << (a[mn_i]+a[mn_i+k])/2 << "\n";
	}
	flush(cout);
	
	return 0;
}