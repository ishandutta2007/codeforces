#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int n;
int p[105];

int main(void)
{
	cin >> n;
	for(int i = 0; i < n/2; i++) cin >> p[i];
	sort(p, p+n/2);
	
	int ans = 1e9, tmp;
	
	tmp = 0;
	for(int i = 0; i < n/2; i++) tmp += abs(p[i] - (2*i+1));
	ans = min(ans, tmp);
	
	tmp = 0;
	for(int i = 0; i < n/2; i++) tmp += abs(p[i] - (2*i+2));
	ans = min(ans, tmp);
	
	cout << ans << endl;
	return 0;
}