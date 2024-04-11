#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=509,M=5009;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,l[N][N],rt,cnt,a[M],fa[M];
bool vst[N];

int findrt(vector<int>s) {
	int mx=0;
	for(auto u:s) for(auto v:s) if(l[u][v]>mx) mx=l[u][v];
	return mx;
}
int solve(vector<int>s) {
	if(s.size()==1) return s[0];
	int sz=s.size(),u=findrt(s),id=++cnt;
	a[id]=u;
	for(auto v:s) vst[v]=0;
	for(auto v:s) if(!vst[v]) {
		vector<int>t;
		for(auto w:s) if(l[v][w]!=u) vst[w]=1,t.push_back(w);
		fa[solve(t)]=id;
	}
	return id;
}

int main() {
	cnt=n=read();
	rep(i,1,n) rep(j,1,n) l[i][j]=read();
	rep(i,1,n) a[i]=l[i][i];
	vector<int>s; rep(i,1,n) s.push_back(i);
	rt=solve(s);
	printf("%d\n",cnt);
	rep(i,1,cnt) printf("%d ",a[i]); puts("");
	printf("%d\n",rt);
	rep(i,1,cnt) if(i!=rt) printf("%d %d\n",i,fa[i]); puts("");
	return 0;
}