#include <bits/stdc++.h>

int n,m,x,a[1000005];

void solve() {
	scanf("%d%d%d",&n,&m,&x);
	std::priority_queue<std::pair<int,int> >q;
	for (int i = 1; i <= n; ++ i) scanf("%d",&a[i]);
	puts("YES");
	for (int i = 1; i <= m; ++ i) q.push({0,i});
	for (int i = 1; i <= n; ++ i) {
		auto p = q.top(); q.pop();
		int y = p.first, x = p.second;
		printf("%d ",x);
		q.push({y - a[i],x});
	} puts("");
}
	

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}