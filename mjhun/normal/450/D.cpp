#include <bits/stdc++.h>
#define mp make_pair
#define fst first
#define snd second
#define pb push_back
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

vector<pair<int,int> > g[100005];
priority_queue<pair<ll,pair<int,int> > > q;
int n,m,k;
ll d[100005];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	while(m--){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);x--;y--;
		g[x].pb(mp(y,c));
		g[y].pb(mp(x,c));
	}
	memset(d,-1,sizeof(d));
	q.push(mp(0,mp(0,0)));
	int r=k;
	while(k--){
		int x,c;
		scanf("%d%d",&x,&c);x--;
		q.push(mp(-c,mp(-k-2,x)));
	}
	while(!q.empty()){
		int x=q.top().snd.snd,w=q.top().snd.fst;
		ll c=q.top().fst;
		q.pop();
		if(d[x]>=0)continue;
		if(w<0)r--;
		d[x]=-c;
		fore(i,0,g[x].size()){
			int y=g[x][i].fst,c1=g[x][i].snd;
			if(d[y]<0){
				q.push(mp(c-c1,mp(0,y)));
			}
		}
	}
	printf("%d\n",r);
	return 0;
}