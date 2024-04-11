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
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

vector<int> g[100005];int n,m;
vector<int> c[100005];int nc;
bool b[100005];
int v[100005];
vector<pair<int,int> > e;
int s0[100005],s1[100005];
int w[100005];

void add(int x, int y){
	e.pb(mp(x,y));
	if(SZ(e)==m){
		for(auto p:e)printf("%d %d\n",p.fst+1,p.snd+1);
		exit(0);
	}
}

void add2(int i, int j){
	add(i,j);
	if(s0[j]==s0[i])s0[s0[i]]=-1,s0[i]=s0[j]=s1[i]=s1[j]=-1;
	else {
		s1[s0[i]]=s1[s0[j]];
		s0[s0[j]]=s0[s0[i]];
	}
	n--;
}

void dfs(int x){
	if(v[x]>=0)return;
	v[x]=nc;c[nc].pb(x);
	for(int y:g[x])dfs(y);
}

priority_queue<pair<int,int> > q;

int main(){
	scanf("%d%d",&n,&m);
	fore(_,0,m){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);g[y].pb(x);
	}
	memset(v,-1,sizeof(v));
	fore(i,0,n)if(!SZ(g[i]))b[nc]=true,v[i]=nc,c[nc++]={i};
	fore(i,0,n)if(SZ(g[i])==1&&v[i]<0)dfs(i),b[nc++]=false;
	fore(i,0,n)if(v[i]<0)dfs(i),b[nc++]=true;
	if(nc==1){
		if(n>=5)fore(i,0,n)add(c[0][i],c[0][(i+2)%n]);
		else if(n==4&&!b[0]){
			add(c[0][1],c[0][3]);
			add(c[0][3],c[0][0]);
			add(c[0][0],c[0][2]);
			assert(0);
		}
	}
	else {
		fore(i,0,n)s0[i]=s1[i]=i;
		pair<int,int> t=mp(-1,-1);
		fore(i,0,nc)t=max(t,mp(SZ(c[i]),i));
		int k=t.snd;
		if(SZ(c[k])>n-SZ(c[k])){
			if(SZ(c[k])==2){add(c[k][0],c[k^1][0]);assert(0);}
			if(SZ(c[k])==3){
				if(!b[k])add2(c[k][0],c[k][2]);
			}
			else if(SZ(c[k])==4&&b[k]){
				add2(c[k][0],c[k][2]);
				if(SZ(c[k])-1>n-(SZ(c[k])-1))add2(c[k][1],c[k][3]);
			}
			else if(SZ(c[k])==4){
				add2(c[k][1],c[k][3]);
				if(SZ(c[k])-1>n-(SZ(c[k])-1)){
					add2(c[k][3],c[k][0]);
					if(SZ(c[k])-2>n-(SZ(c[k])-2))add2(c[k][0],c[k][2]);
				}
			}
			else {
				fore(i,0,SZ(c[k])){
					add2(c[k][i],c[k][(i+2)%SZ(c[k])]);
					if(SZ(c[k])-i-1<=n-(SZ(c[k])-i-1))break;
				}
			}
			vector<int> t;
			for(int x:c[k])if(s0[x]==x)t.pb(x);
			c[k]=t;
		}
		int l=-1;
		fore(i,0,nc)q.push(mp(SZ(c[i]),i==k?i:-i));
		while(!q.empty()){
			auto p=q.top();q.pop();
			int i=abs(p.snd);
			if(l>=0&&v[l]==i){
				if(q.empty())break;
				auto qwe=p;
				p=q.top();q.pop();q.push(qwe);
				i=abs(p.snd);
			}
			if(l>=0)add(s1[l],s0[c[i][w[i]]]);
			l=c[i][w[i]++];
			if(p.fst>1)q.push(mp(p.fst-1,i==k?i:-i));
		}
		if(v[l]!=k){
			add(s1[l],s0[c[k][0]]);
		}
	}
	puts("-1");
	return 0;
}