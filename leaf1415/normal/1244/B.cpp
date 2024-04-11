#include <iostream>
#include <string>
#define llint long long
#define inf 1000000000

using namespace std;

llint t, n;
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	for(int q = 0; q < t; q++){
		cin >> n >> s;
		s = "#" + s;
		llint l = inf, r = -inf;
		for(llint i = 1; i <= n; i++){
			if(s[i] == '1'){
				l = min(l, i);
				r = max(r, i);
			}
		}
		if(l >= inf){
			cout << n << "\n";
			continue;
		}
		llint ans = max(2*r, 2*(n-l+1));
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}