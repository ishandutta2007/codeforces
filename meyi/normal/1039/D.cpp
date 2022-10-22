#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define ll long long
#define N 100005

ll n;

ll head[N],cnt;

struct P{
	int to,next;
}e[N * 2];

inline void add(int x,int y){
	e[++cnt].to = y;
	e[cnt].next = head[x];
	head[x] = cnt;
}

ll fa[N],dfn[N],dfncnt;

inline void dfs(int u,int f){
	fa[u] = f;
	for(int i = head[u];i;i = e[i].next){
		int v = e[i].to;
		if(v == f)
		continue;
		dfs(v,u);
	}
	dfn[++dfncnt] = u;
}

ll ans[N];
ll f[N];// 

inline ll solve(int k){
    if(ans[k]!=-1)return ans[k];
	ll ans = 0;
	for(int i = 1;i <= n;++i)
	f[i] = 1;
	for(int i = 1;i <= n;++i){
		int u = dfn[i];
		int fi = fa[u];
		if(fi && f[u] != -1 && f[fi] != -1)
		if(f[u] + f[fi] >= k)
		ans ++ ,f[fi] = -1;
		else
		f[fi] = std::max(f[fi],f[u] + 1);
	}
	return ans;
}

int main(){
	scanf("%lld",&n);
	for(int i = 1;i < n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	dfs(1,0);
	ll s = std::sqrt(n * log2(n));
	memset(ans,-1,sizeof(ans));
	ans[1] = n;//solve 
	for(int i = 2;i <= s;++i)
	ans[i] = solve(i);
	for(int i = s + 1;i <= n;++i){
		if(ans[i]!=-1)continue;
		ans[i] = solve(i);
		int l = i,r = n,to = i;
		while(l <= r){
			ll mid = (l + r) >> 1;
			if(solve(mid) == ans[i])
			l = mid + 1,to = mid;
			else
			r = mid - 1;
//			std::cout<<l<<" "<<r<<std::endl;
		}
		to -= 1;// 
		while(solve(to + 1) == ans[i] && to <= n)
		to ++ ;
		for(int j = i + 1;j <= to;++j)
		ans[j] = ans[i];
	}
	for(int i = 1;i <= n;++i)
	std::cout<<ans[i]<<std::endl;
}