#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 1e6 + 5,NN = N * 20,INF = 0x7fffffff / 2;
int n,d,id2[N];
struct Node {
	int s,a;
} p[N];
bool cmp(const Node &a,const Node &b) {return a.a < b.a || (a.a == b.a && a.s > b.s);}
vector<int> lsh;
int dp[N];

#define lc (k << 1)
#define rc (lc | 1)
#define left lc,l,mid
#define right rc,mid+1,r
int seg[N << 2],tag[N << 2];
void pushup(int k) {seg[k] = max(seg[lc],seg[rc]);}
void puttag(int k,int v) {tag[k] += v; seg[k] += v;}
void pushdown(int k) {
	if(tag[k]) puttag(lc,tag[k]),puttag(rc,tag[k]),tag[k] = 0;
}
void change(int k,int l,int r,int x,int y,int v) {
	if(x <= l && r <= y) return puttag(k,v);
	int mid = l + r >> 1;
	pushdown(k);
	if(x <= mid) change(left,x,y,v);
	if(y > mid) change(right,x,y,v);
	pushup(k);
}
int query(int k,int l,int r,int x,int y) {
	if(x <= l && r <= y) return seg[k];
	int mid = l + r >> 1,res = 0;
	pushdown(k);
	if(x <= mid) res = query(left,x,y);
	if(y > mid) res = max(res,query(right,x,y));
	return res;
}
void build(int k,int l,int r) {
	if(l == r) {
		seg[k] = -INF;
		return;
	}
	int mid = l + r >> 1;
	build(left); build(right); pushup(k);
}
int main() {
	ios::sync_with_stdio(0);
	cin >> n >> d;
	fr(i,1,n) {
		cin >> p[i].s >> p[i].a;
		if(p[i].s < d) --i,--n;
	}
	if(n == 0) return cout << 0 << endl,0;
	fr(i,1,n) id2[i] = i;
	fr(i,1,n) {
		lsh.push_back(p[i].s);
		lsh.push_back(p[i].a);
	}
	sort(lsh.begin(),lsh.end());
	lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());
	fr(i,1,n) {
		p[i].s = lower_bound(lsh.begin(),lsh.end(),p[i].s) - lsh.begin() + 1;
		p[i].a = lower_bound(lsh.begin(),lsh.end(),p[i].a) - lsh.begin() + 1;
	}
	sort(p+1,p+n+1,cmp);
	sort(id2+1,id2+n+1,[](const int &i,const int &j) {
		return p[i].s < p[j].s;
	});

	build(1,0,n); change(1,0,n,0,0,INF);
	int p1 = 1,ans = 0,pos;
	fr(i,1,n) {
		for(;p1 <= n && p[id2[p1]].s < p[i].a;++p1) {
			if(p[id2[p1]].a > p[id2[p1]].s) continue;
			pos = lower_bound(p+1,p+n+1,(Node){INF,p[id2[p1]].a},cmp) - p - 1;
			change(1,0,n,0,pos,-1);
			//cout << id2[p1] << ' ' << -1 << endl;
		}
		pos = upper_bound(p+1,p+n+1,(Node){0,p[i].s},cmp) - p - 1;
		dp[i] = query(1,0,n,0,pos) + 1;
		change(1,0,n,i,i,dp[i]+INF);
		if(p[i].a <= p[i].s) {
			pos = lower_bound(p+1,p+n+1,(Node){INF,p[i].a},cmp) - p - 1;
			change(1,0,n,0,pos,1);
			//cout << i << ' ' << 1 << endl;
		}
		ans = max(ans,dp[i]);
	}
	cout << ans << endl;
	return 0;
}