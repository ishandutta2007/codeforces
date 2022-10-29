#include <bits/stdc++.h>
#define mp make_pair
#define fst first
#define snd second
using namespace std;
typedef long long ll;

int n,m,t;
vector<pair<int,ll> > rc[512];
map<int,ll> yc;
multiset<ll> cs;
ll f[512][512];
ll g[512][512];
ll INF;

int main(){
	scanf("%d%d%d",&n,&m,&t);
	while(m--){
		int l,r,c;
		scanf("%d%d%d",&l,&r,&c);l--;r--;
		rc[l].push_back(mp(r,c));
	}
	memset(g,1,sizeof(g));INF=g[0][0];
	for(int i=0;i<n;++i){
		if(i)for(int j=i;j<n;++j)g[i][j]=g[i-1][j];
		yc.clear();cs.clear();
		for(int j=i;j<n;++j)yc[j]=INF,cs.insert(INF);
		for(int k=0;k<rc[i].size();++k){
			if(yc[rc[i][k].fst]>rc[i][k].snd){
				cs.erase(cs.find(yc[rc[i][k].fst]));
				yc[rc[i][k].fst]=rc[i][k].snd;
				cs.insert(rc[i][k].snd);
			}
			g[i][i]=min(g[i][i],rc[i][k].snd);
		}
		cs.erase(cs.find(yc[i]));
		for(int j=i+1;j<n;++j){
			g[i][j]=*cs.begin();
			for(int k=0;k<rc[j].size();++k){
				ll c=g[i][j-1]+rc[j][k].snd;
				if(yc[rc[j][k].fst]>c){
					cs.erase(cs.find(yc[rc[j][k].fst]));
					yc[rc[j][k].fst]=c;
					cs.insert(c);
				}
				g[i][j]=min(g[i][j],c);
			}
			cs.erase(cs.find(yc[j]));
		}
	}
	memset(f,1,sizeof(f));
	memset(f[0],0,sizeof(f[0]));
	for(int k=1;k<=t;++k){
		f[k][k-1]=g[0][k-1];
		for(int i=k;i<n;++i){
			f[k][i]=f[k][i-1];
			for(int j=1;j<=k;++j){
				f[k][i]=min(f[k][i],f[k-j][i-j]+g[i-j+1][i]);
			}
		}
	}
	cout<<(f[t][n-1]==INF?-1:f[t][n-1])<<endl;
	return 0;
}