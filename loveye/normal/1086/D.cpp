#include<bits/stdc++.h>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(file) freopen(file".in","r",stdin)
#define fileout(file) freopen(file".out","w",stdout)

const int N=2e5+5;
int n,q;
char str[N];
int mp[127];
set<int> s[3];
#define fi first
#define se second
struct BIT {
	int c[N]; void add(int x,int v) {for(;x<=n;x+=x&-x) c[x]+=v;}
	int ask(int x) {int z(0); for(;x;x&=x-1) z+=c[x]; return z;}
	int sum(int l,int r) {return l>r?0:ask(r)-ask(l-1);}
} t[3];
typedef pair<int,int> pii;
int calc() {
	int ans=0;
	fo(c,0,3) {
		vector<pii> tmp(1,pii(n+1,0));
		int y=(c+2)%3,b=(c+1)%3;
		int fy=s[y].empty()?n+1:*s[y].begin(),fb=s[b].empty()?n+1:*s[b].begin();
		tmp.push_back(pii(1,1));
		if(fy<=fb) tmp.push_back(pii(fy,-1)),tmp.push_back(pii(fb+1,1));
		int ly=s[y].empty()?0:*--s[y].end(),lb=s[b].empty()?1:*--s[b].end();
		tmp.push_back(pii(1,1));
		if(lb<=ly) tmp.push_back(pii(lb,-1)),tmp.push_back(pii(ly+1,1));
		sort(tmp.begin(),tmp.end());
		int res=0;
		fo(i,0,tmp.size()) {
			if(tmp[i].fi==n+1) break;
			res+=tmp[i].se;
			if(res==2&&tmp[i].fi!=tmp[i+1].fi)
				ans+=t[c].sum(tmp[i].fi,tmp[i+1].fi-1);
		}
	}
	return ans;
}
int main() {
	n=read(),q=read();
	scanf("%s",str+1);
	mp['R']=0; mp['S']=1; mp['P']=2;
	fr(i,1,n) {
		s[mp[str[i]]].insert(i);
		t[mp[str[i]]].add(i,1);
	}
	printf("%d\n",calc());
	while(q--) {
		static int i;
		static char op[3];
		scanf("%d%s",&i,op);
		s[mp[str[i]]].erase(i);
		t[mp[str[i]]].add(i,-1);
		str[i]=op[0];
		s[mp[str[i]]].insert(i);
		t[mp[str[i]]].add(i,1);
		printf("%d\n",calc());
	}
	return 0;
}
int read() {
	static int x,c,f; x=0,f=1;
	do c=getchar(),(c=='-'&&(f=-1)); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}