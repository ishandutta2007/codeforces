#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define LL long long
int n,T,du[N];
LL ans[N],a[N];
struct Node {
	int w,cnt;
	inline bool operator < (const Node &o) const {
		return w > o.w;
	}
} ;
priority_queue<Node> pq;
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(int i = 1;i <= n;++i)
			scanf("%I64d",a+i),du[i] = 0;
		while(!pq.empty()) pq.pop();
		for(int i = 1,u,v;i < n;++i)
			scanf("%d%d",&u,&v),++du[u],++du[v],ans[i] = 0;
		for(int i = 1;i <= n;++i) {
			if(du[i] != 1) pq.push((Node){(int)a[i],du[i]-1});
			ans[n-1] += a[i] * du[i];
		}
		for(int i = n-2;i >= 1;--i) {
			Node now = pq.top();pq.pop();
			ans[i] = ans[i+1] - now.w;
			--now.cnt;
			if(now.cnt) pq.push(now);
		}
		for(int i = 1;i < n;++i)
			printf("%I64d%c",ans[i]," \n"[i == n-1]);
	}
	return 0;
}