#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef pair <int, int> pii;
const int MAXN = 200005;

int n, m, p[MAXN]; bool sold[MAXN];
priority_queue <pii> h[5];

int main(){
	memset(sold, false, sizeof(sold));
	int i, c;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i)
		scanf("%d", &p[i]);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &c);
		h[c].push(pii(- p[i], i));
	}
	for(i = 1; i <= n; ++ i){
		scanf("%d", &c);
		h[c].push(pii(- p[i], i));
	} scanf("%d", &m);
	for(i = 1; i <= m; ++ i){
		scanf("%d", &c);
		while(!h[c].empty() && sold[h[c].top().se])
			h[c].pop();
		if(h[c].empty()) printf("-1 ");
		else{
			printf("%d ", - h[c].top().fi);
			sold[h[c].top().se] = true;
			h[c].pop();
		}
	} return 0;
}