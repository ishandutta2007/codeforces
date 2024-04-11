#include <bits/stdc++.h>

const int maxn = 3005;
std::set<std::pair<int,int> > ans;

int n,d[maxn],c[maxn];
std::vector<int>v[2];

std::pair<int,int>work(std::pair<int,int> x) {
	if (x.first > x.second) std::swap(x.first,x.second);
	return x;
}

void ask(int u,int *d) {
	printf("? %d\n",u);
	fflush(stdout);
	for (int i = 1; i <= n; ++ i) 
		scanf("%d",&d[i]);
}

void solve(int x) {
	for (int u:v[x]) {
		if (u == 1) continue;
		ask(u,d);
		for (int i = 1; i <= n; ++ i) {
			if (d[i] == 1) {
				ans.insert(work({u,i}));
			}
		}
	} 
}

int main() {
	scanf("%d",&n);
	ask(1,d);
	for (int i = 1; i <= n; ++ i) {
		if (d[i] == 1) {
			ans.insert(work({1,i}));
		}
		c[i] = d[i] % 2;
		v[c[i]].push_back(i);
	} if (v[0].size() - 1 <= (n + 1) / 2 - 1) solve(0);
	else solve(1);
	puts("!");
	for (auto x:ans) { printf("%d %d\n",x.first,x.second); }
	fflush(stdout);
	return 0;
}