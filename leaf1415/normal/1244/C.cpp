#include <iostream>
#include <string>
#include <cstdlib>
#define llint long long

using namespace std;

llint n, p, w, d;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> p >> w >> d;
	
	for(llint i = 0; i < w; i++){
		llint a = p-i*d;
		if(a < 0) break;
		if(a % w) continue;
		llint x = a/w, y = i;
		if(x + y > n) break;
		cout << x << " " << y << " " << n-(x+y) << endl;
		return 0;
	}
	cout << -1 << endl;
	
	return 0;
}