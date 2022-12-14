#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 100005;
typedef long long int ll;

int n, m, k, pos[MAXN], id[MAXN];

int main(){
	int i, t; ll ans = 0;
	scanf("%d%d%d", &n, &m, &k);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &id[i]);
		pos[id[i]] = i;
	}
	for(i = 1; i <= m; ++ i){
		scanf("%d", &t);
		ans += (ll)(((pos[t] - 1) / k) + 1);
		if(pos[t] != 1){
			int t_ = id[pos[t] - 1];
			swap(pos[t], pos[t_]);
			swap(id[pos[t]], id[pos[t_]]);
		}
	}
	cout << ans << endl;
	return 0;
}