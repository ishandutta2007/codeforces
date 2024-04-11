#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back

int read(){
	int i;
	scanf("%d",&i);
	return i;
}

struct SegTree{
	int mn[1<<20],lz[1<<20],s;
	void Init(int n){
		s=1;
		while(s<n)s*=2;
		fill(lz,lz+s*2,0);
		fill(mn,mn+s*2,0);
		REP(i,n)
			mn[s+i]=i-n;
		for(int i=s-1;i>=1;i--)
			mn[i]=min(mn[i*2],mn[i*2+1]);
	}
	int NodeMin(int i){
		return mn[i]+lz[i];
	}
	void Propagate(int i){
		lz[i*2]+=lz[i];
		lz[i*2+1]+=lz[i];
		mn[i]+=lz[i];
		lz[i]=0;
	}
	void Add(int b,int e,int l,int r,int v,int i){
		if(e<=l||r<=b)
			return;
		if(b<=l&&r<=e){
			lz[i]+=v;
			return;
		}
		Propagate(i);
		Add(b,e,l,(l+r)/2,v,i*2);
		Add(b,e,(l+r)/2,r,v,i*2+1);
		mn[i]=min(NodeMin(i*2),NodeMin(i*2+1));
	}
	void Add(int b,int e,int v){
		if(b<e)
			Add(b,e,0,s,v,1);
	}
	int Get(){
		return NodeMin(1);
	}
} seg;

const int Nmax=500000;
int h[Nmax],s[Nmax],n,k,d[Nmax];
vector<int> tree[Nmax],qs[Nmax];

typedef pair<int,int> pii;
void dfs(int v,int p,pii k1,pii k2){
	pii kv=MP(h[v],v);
	if(kv<k1)
		swap(kv,k1);
	if(kv<k2)
		swap(kv,k2);
	qs[k1.second].PB(k2.first);
	d[v]=k1.first;
	for(auto i:tree[v])
		if(i!=p)
			dfs(i,v,k1,k2);
}

int main(){
	n=read();
	REP(i,n)
		h[i]=read();
	REP(i,n-1){
		int a=read()-1,b=read()-1;
		tree[a].PB(b);
		tree[b].PB(a);
	}
	k=read();
	REP(i,k)
		s[i]=read();
	sort(s,s+k);
	dfs(0,-1,MP(INT_MAX,-1),MP(INT_MAX,-1));
	sort(d,d+n);
	int w=n-1,need=-1;
	for(int i=k-1;i>=0;i--){
		if(d[w]>=s[i])
			w--;
		else{
			need=s[i];
			break;
		}
	}
	if(need==-1){
		printf("0\n");
		return 0;
	}
	seg.Init(k);
	REP(i,n){
		int u=upper_bound(s,s+k,d[i])-s;
		seg.Add(0,u,1);
	}
	int ans=INT_MAX;
	REP(i,n)
		if(h[i]<need){
			int u=upper_bound(s,s+k,h[i])-s;
			for(auto& j:qs[i]){
				int t=upper_bound(s,s+k,min(j,need))-s;
				j=t;
				seg.Add(u,t,1);
			}
			if(seg.Get()>=0)
				ans=min(ans,need-h[i]);
			for(auto& j:qs[i])
				seg.Add(u,j,-1);
		}
	if(ans==INT_MAX)
		printf("-1\n");
	else
		printf("%d\n",ans);
}