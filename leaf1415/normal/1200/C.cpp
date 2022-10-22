#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#define llint long long

using namespace std;

llint n, m, Q;

llint gcd(llint a, llint b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> Q;
	llint sx, sy, ex, ey;
	llint d = gcd(n, m);
	
	for(int q = 0; q < Q; q++){
		cin >> sx >> sy >> ex >> ey;
		if(sx == 1) sx = n; else sx = m;
		if(ex == 1) ex = n; else ex = m;
		sy--, ey--;
		
		llint g = sy / (sx/d);
		if(ey >= ex/d*g && ey < ex/d*(g+1)) cout << "YES" << endl;
		else cout << "NO" << "\n";
	}
	
	return 0;
}