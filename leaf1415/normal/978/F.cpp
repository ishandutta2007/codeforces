#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#define inf 1000000000

using namespace std;
typedef pair<int, int> P;

int n, k;
int r[200005];
vector<int> G[200005];
P p[200005];

int main(void)
{
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> r[i];
	
	int a, b;
	for(int i = 0; i < k; i++){
		cin >> a >> b;
		a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	for(int i = 0; i < n; i++) p[i] = make_pair(r[i], i);
	sort(p, p+n);
	
	for(int i = 0; i < n; i++){
		int ans = upper_bound(p, p+n, make_pair(r[i]-1, inf)) - p;
		for(int j = 0; j < G[i].size(); j++){
			if(r[i] > r[G[i][j]]) ans--;
		}
		cout << ans << " ";
	}
	cout << endl;
	
	return 0;
}