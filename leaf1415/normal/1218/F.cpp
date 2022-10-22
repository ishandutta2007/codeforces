#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define llint long long

using namespace std;

llint n, k, a;
llint x[100005], c[100005];
priority_queue<llint, vector<llint>, greater<llint> > Q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> x[i];
	cin >> a;
	for(int i = 1; i <= n; i++) cin >> c[i];
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		Q.push(c[i]);
		while(k < x[i]){
			if(Q.size() == 0){
				cout << -1 << endl;
				return 0;
			}
			ans += Q.top();
			Q.pop();
			k += a;
		}
	}
	cout << ans << endl;

	return 0;
}