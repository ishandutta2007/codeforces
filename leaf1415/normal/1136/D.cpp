#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m;
int p[300005];
set<int> s[300005], P;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> p[i];
	int x = p[n];
	
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		s[u].insert(v);
	}
	
	int ans = 0;
	for(int i = n-1; i >= 1; i--){
		int c = p[i];
		if(!s[c].count(x)){
			P.insert(c);
			continue;
		}
		else{
			for(auto it = P.begin(); it != P.end(); it++){
				if(!s[c].count(*it)){
					P.insert(c);
					goto pass;
				}
			}
			ans++;
		}
		pass:;
	}
	cout << ans << endl;
	
	return 0;
}