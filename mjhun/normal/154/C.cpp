#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define P 1777771
using namespace std;

typedef long long ll;
int MOD[2]={1070777777,1000000007};

vector<int> g[1<<20];
int h[1<<20][2];
int p[1<<20][2];
int n,m;
unordered_map<long long,int> w;

int main(){
	scanf("%d%d",&n,&m);
	p[0][0]=p[0][1]=1;
	fore(i,1,1<<20){
		fore(j,0,2){
			p[i][j]=(1LL*p[i-1][j]*P)%MOD[j];
		}
	}
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);a--;b--;
		fore(j,0,2){
			h[a][j]+=p[b][j];
			h[a][j]%=MOD[j];
			h[b][j]+=p[a][j];
			h[b][j]%=MOD[j];
		}
		g[a].pb(b);
		g[b].pb(a);
	}
	fore(i,0,n)sort(g[i].begin(),g[i].end());
	ll r=0;
	fore(i,0,n){
		ll s=((1LL*h[i][0])<<32)|h[i][1];
		r+=w[s];
		w[s]++;
	}
	fore(x,0,n){
		fore(i,0,g[x].size()){
			int y=g[x][i];
			if(y>x)break;
			if(binary_search(g[y].begin(),g[y].end(),x)&&(h[x][0]+MOD[0]-p[y][0])%MOD[0]==(h[y][0]+MOD[0]-p[x][0])%MOD[0]){
				r++;
			}
		}
	}
	printf("%I64d\n",r);
	return 0;
}