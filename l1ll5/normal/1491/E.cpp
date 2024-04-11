#include <bits/stdc++.h>
using namespace std;
using LL = long long;
inline int read() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define N 800005
#define INF 0x3f3f3f3f
int n;
vector<int> v[N];
struct zgz{
	int to,next;
}edge[N];
int head[N],cnt=2;
void add(int x,int y){
	edge[cnt].to=y;
	edge[cnt].next=head[x];
	head[x]=cnt++;
}
int ban[N];
int fib[50];
int isfib[N];
int sz[N];
int f[N];
void dfs(int x,int fa) {

	sz[x] = 1;
	for(auto to : v[x]) {
		if(to == fa) continue ;
	//	if(ban[to]) continue ;
		f[to] = x;
		dfs(to, x);
		sz[x] += sz[to];
	}
} 
int fd;
void find(int x,int y) {	
 //	cerr << x << endl; 
	if(sz[x] == y) {
		fd = x;
	}
	for(auto to : v[x]) {
		if(to == f[x]) continue ;
		if(ban[to]) continue ;
		find(to, y);
	}
}

bool check(int mx, int root) {
//	cerr << mx << ' ' << root << endl;
	if(mx <= 3) {
		return 1;
	} 
	int tmp = fib[ isfib[mx] - 2];

//	dfs(root);
	fd = -1;
	find(root, tmp);
	int xx = fd;
	if(xx == -1) {
		return 0;
	}
	ban[xx] = 1;
	int ok1 =
	check(tmp, xx);
	int ok2 =
	check(mx - tmp, root); 
	return ok1 && ok2; 
}
int ct[N];
int fid(int x,int mxn) {
	for(int i=head[x];i;i=edge[i].next){
		int to=edge[i].to;
		if(to==f[x])continue ;
		if(ct[i >> 1]) continue ;
	//	cerr << x<< ' ' << to  << ' '<< sz[to] << ' ' << mxn-sz[to] << endl; 
		if(isfib[sz[to]] && isfib[mxn - sz[to]]) {
			ct[i >> 1] = 1;
			sz[x] -= sz[to];
			return to;
		}
		int xxx = fid(to, mxn);
		if(xxx != -1) {
			sz[x] -= sz[xxx];
			return xxx;
		}
	}
	return -1;
	
}
int over = 0;
void ck(int mxn,int x){
	if(over) return ;
	if(mxn <= 3){
		return ;
	}
	int to = fid(x,mxn);
	//cerr << x << ' ' << mxn << ' '  << to << endl;
	if(to == -1) {
		over =1 ;
		return ;
	} 
	ck(sz[to],to);
	ck(sz[x], x);
	
}
int main() {
	//freopen("0.in","r",stdin); 
	fib[0] = fib[1] = 1;
	for(int i = 2; i <= 30; i += 1){
		fib[i] = fib[i-1] + fib[i-2];
	}  
	for(int i = 0; i <= 30 ; i += 1) {
		if(fib[i] <= 200000) isfib[fib[i]] = i; 
	}
//	cerr << fib[30] << endl;
	scanf("%d", &n);
//	n = 2e5;
	if(!isfib[n]) {
		puts("NO");
		return 0;
	} 
//	cerr << " a " << endl;
    for(int i = 1; i <= n - 1 ; i += 1) {
    	int x, y;
		scanf("%d %d", &x, &y); 
		v[x].push_back(y);
		v[y].push_back(x);	
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	ck(n,1);
	if(!over)
	puts("YES");
	else puts("NO");
	/*
	int ans = check(n, 1);
	if(ans) puts("YES");
	else puts("NO"); */
}