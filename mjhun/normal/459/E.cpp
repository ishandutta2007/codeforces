#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n,m;
vector<int> xs[100005];
vector<int> ys[100005];
int f[300005];
//
int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,m){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);x--;y--;
		xs[w].pb(x);
		ys[w].pb(y);
	}
	fore(w,1,100001){
		vector<pair<int,int> > u;
		fore(i,0,xs[w].size()){
			u.pb(mp(ys[w][i],f[xs[w][i]]+1));
		}
		fore(i,0,u.size()){
			f[u[i].fst]=max(f[u[i].fst],u[i].snd);
		}
	}
	int r=0;
	fore(i,0,n)r=max(r,f[i]);
	printf("%d\n",r);
	return 0;
}