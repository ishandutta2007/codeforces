#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

vector<int> g[3003];
int n,m,k;
int d[3003][3003];
int f[3003][3003];
set<pair<int,pair<int,int> > > w;
queue<pair<int,int> > q;
vector<int> sol;

int main(){
	scanf("%d%d%d",&n,&m,&k);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	while(k--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);a--;b--;c--;
		w.insert(mp(a,mp(b,c)));
	}
	memset(d,-1,sizeof(d));
	d[0][0]=0;
	q.push(mp(0,0));
	while(!q.empty()){
		int x=q.front().snd,z=q.front().fst;
		q.pop();
		fore(i,0,g[x].size()){
			int y=g[x][i];
			if(d[x][y]<0&&w.find(mp(z,mp(x,y)))==w.end()){
				d[x][y]=d[z][x]+1;
				f[x][y]=z;
				q.push(mp(x,y));
			}
		}
	}
	int bi=0;
	fore(i,1,n){
		if(d[i][n-1]<0)continue;
		if(d[bi][n-1]<0||d[i][n-1]<d[bi][n-1])bi=i;
	}
	printf("%d\n",d[bi][n-1]);
	if(d[bi][n-1]>=0){
		int y=bi,z=n-1;
		while(z){
			sol.pb(z);
			int x=f[y][z];
			z=y;y=x;
		}
		sol.pb(0);
		reverse(sol.begin(),sol.end());
		printf("%d",sol[0]+1);
		fore(i,1,sol.size())printf(" %d",sol[i]+1);
		puts("");
	}
	return 0;
}