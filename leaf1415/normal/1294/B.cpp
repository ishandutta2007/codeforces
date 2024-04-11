#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n;
P p[1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 1; t <= T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> p[i].first >> p[i].second;
		sort(p+1, p+n+1);
		
		llint x = 0, y = 0;
		string ans;
		for(int i = 1; i <= n; i++){
			int nx = p[i].first, ny = p[i].second;
			if(nx < x || ny < y){
				cout << "NO" << endl;
				goto end;
			}
			for(int j = 0; j < nx-x; j++) ans += 'R';
			for(int j = 0; j < ny-y; j++) ans += 'U';
			x = nx, y = ny;
		}
		cout << "YES" << endl;
		cout << ans << endl;
		end:;
	}
	flush(cout);
	
	return 0;
}