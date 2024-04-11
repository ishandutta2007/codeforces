#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
vector<pair<int, int> > points;
int main() {
	int n;
	cin>>n;
	for(int i = 0; i < 4*n+1; ++i) {
		int x,y;
		cin>>x>>y;
		points.push_back({x, y});
	}
	for(int x1 = 0; x1 <= 50; ++x1) {
		for(int x2 = x1+1; x2 <= 50; ++x2) {
			for(int y1 = 0; y1 <= 50; ++y1) {
				int y2 = y1 + x2 - x1;
				int cnt = 0;
				int x_ans = 0;
				int y_ans = 0;
				for(int i = 0; i < 4*n+1; ++i) {
					int ok = 1;
					int x = points[i].F;
					int y = points[i].S;
					if(x > x2 || x < x1 || y > y2 || y < y1) ok = 0;
					if(!(x == x1 || x == x2 || y == y1 || y == y2)) {
						ok = 0;
					}
					if(ok == 0) {
						++cnt;
						x_ans = x;
						y_ans = y;
					}

				}
				if(cnt == 1) {
					cout<<x_ans<<' '<<y_ans<<endl;
					return 0;
				}
			}
		}
	}
}