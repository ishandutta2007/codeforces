#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define PB push_back
#define MP make_pair

using namespace std;

int read(){
	int i;
	scanf("%d",&i);
	return i;
}

typedef pair<int,int> pii;
const int inf=INT_MAX/2;

struct SegTree{
	vector<pii> mx;
	vector<int> lz;
	int s;
	void Init(int n){
		s=1;
		while(s<n)s*=2;
		mx.resize(s*2);
		REP(i,s)
			mx[i+s]=MP(0,i);
		for(int i=s-1;i>=1;i--)
			mx[i]=max(mx[i*2],mx[i*2+1]);
		lz.resize(s*2,0);
	}
	void Propagate(int i){
		mx[i].first+=lz[i];
		lz[i*2]+=lz[i];
		lz[i*2+1]+=lz[i];
		lz[i]=0;
	}
	pii NodeMax(int i){
		return MP(mx[i].first+lz[i],mx[i].second);
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
		mx[i]=max(NodeMax(i*2),NodeMax(i*2+1));
	}
	void Add(int b,int e,int v){
		if(b<e)
			Add(b,e,0,s,v,1);
	}
	pii Get(int b,int e,int l,int r,int i){
		if(e<=l||r<=b)
			return MP(-inf,-1);
		if(b<=l&&r<=e)
			return NodeMax(i);
		Propagate(i);
		return max(Get(b,e,l,(l+r)/2,i*2),Get(b,e,(l+r)/2,r,i*2+1));
	}
	pii Get(int b,int e){
		if(e<=b)	
			return MP(-inf,-1);
		return Get(b,e,0,s,1);
	}
} seg;

struct Solver{
	struct Query{
		int y,b,e,v;
		bool operator<(const Query& rhs)const{
			return y<rhs.y;
		}
	} qs[600000];
	int qc,xs[600000];
	Solver():qc(0){}
	void AddRect(int xb,int xe,int yb,int ye,int v){
	//	cout<<"Query "<<xb<<" "<<xe<<" "<<yb<<" "<<ye<<" "<<v<<endl;
		qs[qc]=Query{yb,xb,xe,v};
		qs[qc+1]=Query{ye,xb,xe,-v};
		xs[qc]=xb;
		xs[qc+1]=xe;
		qc+=2;
	}
	void Intesect(int x1,int x2,int y1,int y2,int t,int& ans1,int& ans2){
		if(y1<=t-x1&&t-x1<=y2){
			ans1=x1;
			ans2=t-x1;
		}
		if(y1<=t-x2&&t-x2<=y2){
			ans1=x2;
			ans2=t-x2;
		}
		if(x1<=t-y1&&t-y1<=x2){
			ans1=t-y1;
			ans2=y1;
		}
		if(x1<=t-y2&&t-y2<=x2){
			ans1=t-y2;
			ans2=y2;
		}
	}
	void Solve(int tMin,int tMax,int n,int& ans1,int& ans2){
		sort(qs,qs+qc);
		sort(xs,xs+qc);
		int s=1;
		FOR(i,1,qc)
			if(xs[i-1]!=xs[i])
				xs[s++]=xs[i];
		seg.Init(s);
		REP(i,qc-1){
			seg.Add(lower_bound(xs,xs+s,qs[i].b)-xs,lower_bound(xs,xs+s,qs[i].e)-xs,qs[i].v);
			if(qs[i+1].y!=qs[i].y){
				int p=tMin-qs[i+1].y+1,q=tMax-qs[i].y;
			//	cout<<"Check "<<qs[i].y<<" "<<p<<" "<<q<<endl;
				if(xs[s-1]<=p||q<xs[0])
					continue;
				int b=max(int(upper_bound(xs,xs+s,p)-xs-1),0);
				int e=upper_bound(xs,xs+s,q)-xs;
				pii g=seg.Get(b,e);
			//	cout<<b<<" "<<e<<" "<<g.first<<endl;
				if(g.first==n){
					int x1=xs[g.second],x2=xs[g.second+1]-1;
					int y1=qs[i].y,y2=qs[i+1].y-1;
					Intesect(x1,x2,y1,y2,tMin,ans1,ans2);
					Intesect(x1,x2,y1,y2,tMax,ans1,ans2);
					if(ans1==-1&&ans2==-1){
						ans1=x1;
						ans2=y1;
					}
					return;
				}
			}
		}
	}
} slv;

int group[100000],rng[100000][2],gr[100000][2];
vector<int> graph[100000],member[200001];
bool vis[100000];

void dfs(int v,int c,vector<int>* mb){
	if(vis[v])
		return;
	vis[v]=true;
	mb[c].PB(v);
	for(auto i:graph[v])
		dfs(i,c^1,mb);
}

int main(){
	int stMin=read(),stMax=read(),n=read(),m=read();
	REP(i,n)
		rng[i][0]=read(),rng[i][1]=read();
	REP(i,m){
		int a=read()-1,b=read()-1;
		graph[a].PB(b);
		graph[b].PB(a);
	}
	vector<int>* mbp=member;
	REP(i,n){
		dfs(i,0,mbp);
		if(!mbp->empty())
			mbp+=2;
	}
	int gs=mbp-member;
	REP(i,gs){
		gr[i][0]=0;
		gr[i][1]=inf;
		for(auto j:member[i]){
			group[j]=i;
			gr[i][0]=max(gr[i][0],rng[j][0]);
			gr[i][1]=min(gr[i][1],rng[j][1]);
		}
		if(gr[i][1]<gr[i][0]){
			printf("IMPOSSIBLE\n");
			return 0;
		}
	}
	REP(i,n)
		for(auto j:graph[i])
			if(group[i]==group[j]){
				printf("IMPOSSIBLE\n");
				return 0;
			}
	for(int i=0;i<gs;i+=2){
		slv.AddRect(gr[i][0],gr[i][1]+1,gr[i+1][0],gr[i+1][1]+1,1);
		slv.AddRect(gr[i+1][0],gr[i+1][1]+1,gr[i][0],gr[i][1]+1,1);
		int p=max(gr[i][0],gr[i+1][0]),q=min(gr[i][1],gr[i+1][1]);
		if(p<=q)
			slv.AddRect(p,q+1,p,q+1,-1);
	}
	int ans1=-1,ans2=-1;
	slv.Solve(stMin,stMax,gs/2,ans1,ans2);
	if(ans1==-1&&ans2==-1){
		printf("IMPOSSIBLE\n");
		return 0;
	}
	for(int i=0;i<gs;i+=2){
		int p=2,q=1;
		if(gr[i][0]<=ans1&&ans1<=gr[i][1]
		&& gr[i+1][0]<=ans2&&ans2<=gr[i+1][1]){
			p=1;
			q=2;
		}
		for(auto j:member[i])
			group[j]=p;
		for(auto j:member[i+1])
			group[j]=q;
	}
	printf("POSSIBLE\n");
	printf("%d %d\n",ans1,ans2);
	REP(i,n)
		printf("%d",group[i]);
	printf("\n");
}