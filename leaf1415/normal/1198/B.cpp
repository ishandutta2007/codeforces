#include <iostream>
#include <algorithm>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;


llint n, Q;
llint a[200005];
P b[200005];
llint c[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) b[i] = make_pair(a[i], 0);
	cin >> Q;
	llint t, p, x;
	for(int q = 1; q <= Q; q++){
		cin >> t;
		if(t == 1){
			cin >> p >> x;
			b[p] = make_pair(x, q);
		}
		else{
			cin >> x;
			c[q] = x;
		}
	}
	for(int i = Q; i >= 1; i--) c[i] = max(c[i+1], c[i]);
	for(int i = 1; i <= n; i++){
		cout << max(b[i].first, c[b[i].second+1]) << " ";
	}
	cout << endl;
	
	return 0;
}