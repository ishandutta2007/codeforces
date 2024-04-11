#include <iostream>
#define llint long long

using namespace std;

llint Q;
llint h, w;
llint cnth[50005], cntw[50005];
char c[500005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> h >> w;
		for(int y = 1; y <= h; y++) cnth[y] = 0;
		for(int x = 1; x <= w; x++) cntw[x] = 0;
		
		for(int y = 1; y <= h; y++){
			for(int x = 1; x <= w; x++){
				cin >> c[x+w*y];
				if(c[x+w*y] == '*') cnth[y]++, cntw[x]++;
			}
		}
		
		llint ans = 1e9;
		for(int y = 1; y <= h; y++){
			for(int x = 1; x <= w; x++){
				llint tmp = (w-cnth[y]) + (h-cntw[x]);
				if(c[x+w*y] == '.') tmp--;
				ans = min(ans, tmp);
			}
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}