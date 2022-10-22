#include <iostream>
#include <stdlib.h>
const int inf = 1e9;

using namespace std;

int a, b;

int dist(int x, int y)
{
	int d = abs(x - y);
	return d * (d+1) / 2;
}

int main(void)
{
	cin >> a >> b;
	
	int ans = inf;
	for(int i = 1; i <= 1000; i++){
		ans = min(ans, dist(a, i) + dist(b, i));
	}
	cout << ans << endl;
	return 0;
}