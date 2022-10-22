#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;

llint h, w;
char c[1000005];
int a[1000005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;
	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			cin >> c[y*w+x];
		}
	}
	
	if(h == 1 || w == 1){
		cout << 0 << endl;
		return 0;
	}
	if(h >= 4 && w >= 4){
		cout << -1 << endl;
		return 0;
	}
	if(h < 4){
		for(int y = 0; y < h; y++){
			for(int x = 0; x < w; x++){
				a[y*w+x] = c[y*w+x]%2;
			}
		}
	}
	else{
		swap(h, w);
		for(int y = 0; y < h; y++){
			for(int x = 0; x < w; x++){
				a[y*w+x] = c[x*h+y]%2;
			}
		}
	}
	
	if(h == 2){
		llint ans = inf;
		for(int p = 0; p < 2; p++){
			for(int q = 0; q < 2; q++){
				if(p == q) continue;
				llint tmp = 0;
				for(int x = 0; x < w; x++){
					llint s = (a[0*w+x] + a[1*w+x]) % 2;
					if(x % 2 == 0) tmp += (p+s)%2;
					else tmp += (q+s)%2;
				}
				ans = min(ans, tmp);
			}
		}
		cout << ans << endl;
	}
	else{
		llint ans = inf;
		for(int p = 0; p < 2; p++){
			for(int q = 0; q < 2; q++){
				for(int r = 0; r < 2; r++){
					for(int s = 0; s < 2; s++){
						if(p == q || r == s) continue;
						llint tmp = 0;
						for(int x = 0; x < w; x++){
							llint f = p, g = r;
							if(x % 2) f = q, g = s;
							llint i = a[0*w+x], j = a[1*w+x], k = a[2*w+x];
							if(f == 0 && g == 0) tmp += min(i+j+k, 3-(i+j+k));
							if(f == 0 && g == 1) tmp += min(2-(i+j)+k, 1-k+i+j);
							if(f == 1 && g == 0) tmp += min(1-i+j+k, 2-(j+k)+i);
							if(f == 1 && g == 1) tmp += min(1-j+i+k, 2-(i+k)+j);
						}
						ans = min(ans, tmp);
						//cout << p << " " << q << " " <<r << " " << s << " " <<tmp << endl;
					}
				}
			}
		}
		cout << ans << endl;
	}
	
	
	return 0;
}