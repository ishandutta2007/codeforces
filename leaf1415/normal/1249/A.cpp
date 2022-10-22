#include <iostream>
#include <algorithm>
#define llint long long

using namespace std;

llint Q;
llint n;
llint a[105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a+n);
		
		llint ans = 1;
		for(int i = 0; i < n-1; i++){
			if(a[i]+1 == a[i+1]) ans = 2;
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}