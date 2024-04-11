#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int a, b, ans;
	cin >> a >> b;
	ans = int(double(a + b) / 2.0 / b + 1e-12);
	if(!ans) cout << -1 << endl;
	else printf("%.12lf\n", (a + b) / 2.0 / ans);
	return 0;
}