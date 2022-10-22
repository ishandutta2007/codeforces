#include <iostream>
#include <algorithm>

using namespace std;

int h, w, cl, ce, v;
int l[100005], e[100005];
int q;

int main(void)
{
	cin >> h >> w >> cl >> ce >> v;
	for(int i = 0; i < cl; i++) cin >> l[i];
	for(int i = 0; i < ce; i++) cin >> e[i];
	
	cin >> q;
	int sx, sy, tx, ty;
	for(int i = 0; i < q; i++){
		cin >> sy >> sx >> ty >> tx;
		int ans = 1e9;
		
		if(sy == ty) ans = abs(sx - tx);
		else{
			auto p = upper_bound(l, l+cl, sx);
			if(p != l+cl) ans = min(ans, abs(sx - *p) + abs(sy - ty) + abs(tx - *p));
			if(p != l) ans = min(ans, abs(sx - *(p-1)) + abs(sy - ty) + abs(tx - *(p-1)));
			
			p = upper_bound(e, e+ce, sx);
			if(p != e+ce) ans = min(ans, abs(sx - *p) + (abs(sy - ty)+v-1) / v + abs(tx - *p));
			if(p != e) ans = min(ans, abs(sx - *(p-1)) + (abs(sy - ty)+v-1) / v + abs(tx - *(p-1)));
		}
		cout << ans << endl;
	}
	
	return 0;
}