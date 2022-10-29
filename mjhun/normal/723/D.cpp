#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n,m,k;
char b[64][64];
bool vis[64][64];
int nl;
int l[64][64];
vector<pair<int,int> > w[2505];
vector<pair<int,int> > p;
pair<int,int> z[2505];

bool dfs(int x, int y){
	if(x<0||x>=n||y<0||y>=m)return false;
	if(b[x][y]=='*')return true;
	if(vis[x][y])return true;
	vis[x][y]=true;
	p.pb(mp(x,y));
	bool r=true;
	if(!dfs(x-1,y))r=false;
	if(!dfs(x+1,y))r=false;
	if(!dfs(x,y-1))r=false;
	if(!dfs(x,y+1))r=false;
	return r;
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	fore(i,0,n)scanf("%s",b[i]);
	fore(i,0,n){
		fore(j,0,m){
			p.clear();
			if(!vis[i][j]&&b[i][j]=='.'&&dfs(i,j)){
				w[nl++]=p;
			}
		}
	}
	fore(i,0,nl)z[i]=mp(w[i].size(),i);
	sort(z,z+nl);
	int r=0;
	fore(_,0,nl-k){
		int i=z[_].snd;
		r+=w[i].size();
		fore(j,0,w[i].size()){
			b[w[i][j].fst][w[i][j].snd]='*';
		}
	}
	printf("%d\n",r);
	fore(i,0,n)puts(b[i]);
	return 0;
}