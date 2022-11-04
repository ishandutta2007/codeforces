#include <bits/stdc++.h>
using namespace std;

int x,y,xx,yy;

int main(){
	cin >> x >> y;
	cin >> xx >> yy;
	int n; cin >> n;
	int ans = 0;
	for (int i=0; i<n; i++){
		int a,b,c; cin >> a >> b >> c;
		long long f0 = (long long)a*x + (long long)b*y;
		long long f1 = (long long)a*xx+ (long long)b*yy;
		bool t0 = (f0 > -c) ? (0) : (1);
		bool t1 = (f1 > -c) ? (0) : (1);
		ans+= t0 != t1;
	}
	cout << ans << endl;
	return 0;
}