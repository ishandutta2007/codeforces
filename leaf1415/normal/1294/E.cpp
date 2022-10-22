#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint h, w;
llint a[200005];
llint cnt[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;
	
	for(int y = 0; y < h; y++){
		for(int x = 1; x < w; x++){
			cin >> a[y*w+x];
		}
		cin >> a[y*w];
		a[y*w] -= w;
		if(a[y*w] < 0) a[y*w] = 1000000000;
	}
	/*for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			cout << a[y*w+x] << " ";
		}
		cout << endl;
	}*/
	llint ans = 0;
	for(int x = 0; x < w; x++){
		for(int y = 0; y < h; y++) cnt[y] = 0;
		for(int y = 0; y < h; y++){
			llint val = a[y*w+x];
			if(val%w != x%w || val/w >= h) continue;
			if(y-val/w >= 0) cnt[y-val/w]++;
			else cnt[h-(val/w-y)]++;
		}
		llint tmp = inf;
		for(int y = 0; y < h; y++) tmp = min(tmp, y + h-cnt[y]);
		ans += tmp;
		//cout << ans << endl;
	}
	cout << ans << endl;
	
	return 0;
}