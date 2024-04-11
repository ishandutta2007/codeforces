#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

struct state {int len,link;map<int,int> next;};
state st[1<<20];
int sz,last;
void sa_init(){
	last=st[0].len=0;sz=1;
	st[0].link=-1;
}
void sa_extend(int c){
	int k=sz++,p;
	st[k].len=st[last].len+1;
	if(c<=0)st[k].len=0;
	for(p=last;p!=-1&&!st[p].next.count(c);p=st[p].link)st[p].next[c]=k;
	if(p==-1)st[k].link=0;
	else {
		int q=st[p].next[c];
		if(st[p].len+1==st[q].len)st[k].link=q;
		else {
			int w=sz++;
			st[w].len=st[p].len+1;
			st[w].next=st[q].next;st[w].link=st[q].link;
			for(;p!=-1&&st[p].next[c]==q;p=st[p].link)st[p].next[c]=w;
			st[q].link=st[k].link=w;
		}
	}
	last=k;
}

int n;
char _s[1<<20];
ll c[1<<20];
ll dp[1<<20];bool vis[1<<20];
ll rr;

ll dfs(int x){
	ll& r=dp[x];
	if(vis[x])return r;
	vis[x]=true;
	for(auto p:st[x].next){
		if(p.fst<=0)r+=c[-p.fst];
		else r+=dfs(p.snd);
	}
	rr=max(rr,r*st[x].len);
	return r;
}

int main(){
	scanf("%d",&n);
	sa_init();
	fore(i,0,n){
		scanf("%s",_s);
		for(int j=0;_s[j];++j){
			sa_extend(_s[j]);
		}
		sa_extend(-i);
	}
	fore(i,0,n)scanf("%lld",c+i);
	dfs(0);
	printf("%lld\n",rr);
	return 0;
}