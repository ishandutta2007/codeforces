#include <bits/stdc++.h>
using namespace std;

bool ok(int a, int b, int x, int x1, int x2){
	if((a || b) && x == x1 && x == x2) return false;
	if(x + b - a > x2) return false;
	if(x + b - a < x1) return false;
	return true;
}

void solve(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int x, y, x1, y1, x2, y2;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	cout << ((ok(a, b, x, x1, x2) && ok(c, d, y, y1, y2)) ? "YES" : "NO") << '\n'; 
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}