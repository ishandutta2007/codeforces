#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n;
int d[2048][2048];
vector<int> c[2048];
int w[2048];
bool v[2048][2048];
priority_queue<pair<int,pair<int,int> > > q;

int main(){
	scanf("%d",&n);
	fore(i,0,n)fore(j,0,n)scanf("%d",&d[i][j]);
	fore(i,0,n)if(d[i][i]){puts("NO");return 0;}
	fore(i,0,n)fore(j,0,n)if(d[i][j]!=d[j][i]){puts("NO");return 0;}
	fore(i,0,n)c[i].pb(i),w[i]=i;
	fore(i,0,n)fore(j,i+1,n){
		if(!d[i][j]){puts("NO");return 0;}
		q.push(mp(-d[i][j],mp(i,j)));
	}
	while(!q.empty()){
		int x=q.top().snd.fst;
		int wx=w[x];
		int y=q.top().snd.snd;
		int wy=w[y];
		q.pop();
		if(v[x][y])continue;
		fore(i,0,c[wx].size())fore(j,0,c[wy].size()){
			if(d[c[wx][i]][c[wy][j]]!=d[x][c[wx][i]]+d[x][y]+d[y][c[wy][j]]){puts("NO");return 0;}
			v[c[wx][i]][c[wy][j]]=v[c[wy][j]][c[wx][i]]=true;
		}
		fore(i,0,c[wx].size())w[c[wx][i]]=wy,c[wy].pb(c[wx][i]);
		c[wx].clear();
	}
	puts("YES");
	return 0;
}