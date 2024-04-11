#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
typedef long long int LL;
/*
4 3 2
1 5 100 100
2 3 4
3 2 3 4

201

4 3 2
1 5 100 100
1 3
2 2 4

-1
*/
int n, m, k, cost[MAXN], type[MAXN], deco[5][MAXN];
LL pf[5][MAXN]; priority_queue <int> lo;
priority_queue <int, vector <int>, greater <int> > hi;

inline bool cmp(const int &a, const int &b){
	return cost[a] < cost[b];
}
inline void update(LL &a, LL b){
	if((a == -1LL) || (a > b)) a = b;
}
inline void update(int &x){
	if(x){
		hi.push(cost[deco[1][x]]);
		hi.push(cost[deco[2][x]]);
		-- x;
	}
}
int main(){
	int i, j, a, A; LL ans = -1LL, lsum = 0LL;
	scanf("%d%d%d", &n, &m, &k);
	for(i = 1; i <= n; ++ i) scanf("%d", &cost[i]);
	scanf("%d", &A);
	for(i = 1; i <= A; ++ i){
		scanf("%d", &a);
		type[a] |= 1;
	}
	scanf("%d", &A);
	for(i = 1; i <= A; ++ i){
		scanf("%d", &a);
		type[a] |= 2;
	}
	for(i = 1; i <= n; ++ i)
		deco[type[i]][++ deco[type[i]][0]] = i;
	for(i = 0; i < 4; ++ i){
		sort(deco[i] + 1, deco[i] + 1 + deco[i][0], cmp);
		for(j = 1; j <= deco[i][0]; ++ j)
			pf[i][j] = pf[i][j - 1] + cost[deco[i][j]];
	} j = min(k, min(deco[1][0], deco[2][0]));
	for(i = 1; i <= deco[0][0]; ++ i)
		lo.push(cost[deco[0][i]]), lsum += cost[deco[0][i]];
	for(i = deco[1][0]; i > j; -- i)
		lo.push(cost[deco[1][i]]), lsum += cost[deco[1][i]];
	for(i = deco[2][0]; i > j; -- i)
		lo.push(cost[deco[2][i]]), lsum += cost[deco[2][i]];
	for(i = k - j; i <= deco[3][0]; ++ i, update(j)){
		if(i + 2 * j > m || (i + 2 * j + int(lo.size()) + int(hi.size())) < m) continue;
		while(!lo.empty() && !hi.empty() && lo.top() > hi.top()){
			lsum += hi.top() - lo.top();
			hi.push(lo.top()); lo.pop();
			lo.push(hi.top()); hi.pop();
		}
		while(int(lo.size()) > m - i - 2 * j){
			lsum -= lo.top();
			hi.push(lo.top());
			lo.pop();
		}
		while(int(lo.size()) < m - i - 2 * j){
			lsum += hi.top();
			lo.push(hi.top());
			hi.pop();
		} update(ans, pf[3][i] + pf[1][j] + pf[2][j] + lsum);
	} cout << ans << endl;
	return 0;
}