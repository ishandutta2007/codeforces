#include <iostream>
#define llint long long

using namespace std;

llint T;
llint n, x;
llint a[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> x;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		llint mx = 0;
		for(int i = 1; i <= n; i++){
			mx = max(mx, a[i]);
			if(x == a[i]){
				cout << 1 << "\n";
				goto end;
			}
		}
		cout << max(2LL, (x+mx-1)/mx) << "\n";
		end:;
	}
	flush(cout);
	
	return 0;
}