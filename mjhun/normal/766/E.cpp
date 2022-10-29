#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

ll r;
const int MAXN=1<<17;
int a[MAXN];
vector<int> g[MAXN];int n;
bool tk[MAXN];
int szt[MAXN];

void dfs0(int x, int f, int c, vector<vector<int> >& w){
	c^=a[x];
	fore(i,0,20)w[i][(c>>i)&1]++;
	for(auto y:g[x])if(y!=f&&!tk[y])dfs0(y,x,c,w);
}

int calcsz(int x, int f){
	szt[x]=1;
	for(auto y:g[x])if(y!=f&&!tk[y])szt[x]+=calcsz(y,x);
	return szt[x];
}

void cdfs(int x=0, int sz=-1){
	if(sz<0)sz=calcsz(x,-1);
	for(auto y:g[x])if(!tk[y]&&szt[y]*2>=sz){
		szt[x]=0;cdfs(y,sz);return;
	}
	tk[x]=true;r+=a[x];
	vector<vector<int> > s(20,vector<int>(2,0));
	fore(i,0,20)s[i][(a[x]>>i)&1]++;
	for(auto y:g[x])if(!tk[y]){
		vector<vector<int> > w(20,vector<int>(2,0));
		dfs0(y,-1,0,w);
		fore(i,0,20){
			r+=(1LL<<i)*w[i][0]*s[i][1];
			r+=(1LL<<i)*w[i][1]*s[i][0];
			if((a[x]>>i)&1){
				s[i][0]+=w[i][1];
				s[i][1]+=w[i][0];
			}
			else {
				s[i][0]+=w[i][0];
				s[i][1]+=w[i][1];
			}
		}
	}
	for(auto y:g[x])if(!tk[y])cdfs(y);
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i);
	fore(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);g[y].pb(x);
	}
	cdfs();
	printf("%lld\n",r);
	return 0;
}