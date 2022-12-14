#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
const int MAXN = 1000005;

int n, bit[MAXN]; vector <int> pos[MAXN];

int query(int p){
	int ret = 0;
	for(; p; p -= p & -p)
		ret += bit[p];
	return ret;
}
void update(int p, int v){
	for(; p <= 1000000; p += p & -p)
		bit[p] += v;
}
inline int getInt(){
	char x; int ret;
	while((x = getchar()) < '0' || x > '9') ;
	ret = x - '0';
	while((x = getchar()) >= '0' && x <= '9')
		ret = ret * 10 - '0' + x;
	return ret;
}
int main(){
	int i, j, k, p, lastv; LL ans = 0LL;
	n = getInt();
	for(i = 1; i <= n; ++ i){
		pos[getInt()].push_back(i);
		update(i, 1);
	}
	for(i = 1, j = 0; i <= 1000000; ++ i){
		if(pos[i].empty()) continue;
		p = upper_bound(pos[i].begin(), pos[i].end(), j) - pos[i].begin();
		if(p == int(pos[i].size())){
			ans += query(n) - query(j) + (lastv = query(pos[i][0]));
			update(pos[i][0], -1);
			for(k = 1; k < int(pos[i].size()); ++ k){
				ans -= lastv - 1;
				ans += (lastv = query(pos[i][k]));
				update(pos[i][k], -1);
			} j = pos[i][k - 1];
		}else{
			ans += (lastv = query(pos[i][p])) - query(j);
			update(pos[i][p], -1);
			for(k = p + 1; k < int(pos[i].size()); ++ k){
				ans -= lastv - 1;
				ans += (lastv = query(pos[i][k]));
				update(pos[i][k], -1);
			}
			if(p){
				ans += query(n) - (lastv - 1);
				ans += (lastv = query(pos[i][0]));
				update(pos[i][0], -1);
				for(k = 1; k < p; ++ k){
					ans -= lastv - 1;
					ans += (lastv = query(pos[i][k]));
					update(pos[i][k], -1);
				} j = pos[i][k - 1];
			}else j = pos[i][k - 1];
		}
	} cout << ans << endl;
	return 0;
}