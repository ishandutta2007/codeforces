#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#define llint long long

using namespace std;
typedef pair<llint, int> P;

llint n, m;
llint a[100005], c[100005], r[100005];
priority_queue<P, vector<P>, greater<P> > Q;

int main(void)
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> c[i];
	
	for(int i = 1; i <= n; i++) Q.push(make_pair(c[i], i));
	for(int i = 1; i <= n; i++) r[i] = a[i];
	
	int t, d;
	for(int i = 0; i < m; i++){
		cin >> t >> d;
		if(r[t] >= d){
			r[t] -= d;
			cout << c[t]*d << endl;
			continue;
		}
		else{
			llint ans = c[t]*r[t];
			d -= r[t];
			r[t] = 0;
			while(d > 0){
				if(Q.size() == 0){
					cout << 0 << endl;
					goto pass;
				}
				int p = Q.top().second;
				if(r[p] == 0){
					Q.pop();
					continue;
				}
				if(r[p] >= d){
					r[p] -= d;
					ans += c[p]*d;
					d = 0;
				}
				else{
					ans += c[p]*r[p];
					d -= r[p];
					r[p] = 0;
				}
			}
			cout << ans << endl;
			pass:;
		}
	}
	return 0;
}