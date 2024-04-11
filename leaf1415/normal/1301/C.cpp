#include <iostream>
#include <string>
#include <cstdlib>
#define llint long long
#define inf 1e18

using namespace std;

llint T;
llint n, m;

llint comb(llint x)
{
	return x*(x+1)/2;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> m;
		llint r = n-m;
		
		m++;
		llint ans = r%m * comb((r+m-1)/m);
		ans += (m-r%m) * comb(r/m);
		ans = comb(n) - ans;
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}