#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	double r, d;
	cin >> r >> d;
	d = r-d;
	if(d < 0.0001) d = -10000000;
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++){
		double x, y, ri;
		cin >> x >> y >> ri;
		double dist = sqrt(x*x+y*y);
		if((dist - ri) - d >= -0.00000001){
			if((dist+ri) - r <= 0.00000001){
				ans++;
			}
		}
	}
	cout << ans << endl;
}