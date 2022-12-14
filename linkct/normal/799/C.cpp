#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pii;
#define fi first
#define se second
const int MAXN = 100005;

int beauty[MAXN], c, d, n, price[MAXN], clist[MAXN], dlist[MAXN], ans;
priority_queue <pii> q;

inline void update(int &a, int b){if(a < b) a = b;}
inline bool cmp(const int &a, const int &b){
	return price[a] < price[b];
}
void solve(int c, int cl[], int d, int dl[]){
	int i, dbest = 0; bool flg; pii tmp;
	while(!q.empty()) q.pop();
	for(i = 1; i <= dl[0] && price[dl[i]] <= d; ++ i)
		if(beauty[dl[i]] > beauty[dbest])
			dbest = dl[i];
	for(i = 1; i <= cl[0] && price[cl[i]] <= c; ++ i)
		q.push(pii(beauty[cl[i]], cl[i]));
	for(i = 1; i <= cl[0] && price[cl[i]] <= c; ++ i){
		if(dbest) update(ans, beauty[dbest] + beauty[cl[i]]);
		while(!q.empty() && price[q.top().se] + price[cl[i]] > c)
			q.pop();
		if(q.empty()) continue;
		if(q.top().se == cl[i]){
			tmp = q.top();
			q.pop();
			flg = true;
		}else flg = false;
		if(!q.empty()) update(ans, beauty[cl[i]] + q.top().fi);
		if(flg) q.push(tmp);
	}
}
int main(){
	int i; char type[5];
	scanf("%d%d%d", &n, &c, &d);
	for(i = 1; i <= n; ++ i){
		scanf("%d%d%s", &beauty[i], &price[i], type);
		if(type[0] == 'C') clist[++ clist[0]] = i;
		else dlist[++ dlist[0]] = i;
	}
	sort(clist + 1, clist + 1 + clist[0], cmp);
	sort(dlist + 1, dlist + 1 + dlist[0], cmp);
	ans = 0;
	solve(c, clist, d, dlist);
	solve(d, dlist, c, clist);
	printf("%d\n", ans);
	return 0;
}