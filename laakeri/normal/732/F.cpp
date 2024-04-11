#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

struct Bridges {
	vector<int> c, h;
	void dfs(vector<pair<int, int> >* g, int x, int pe, int d, vector<int>& ns) {
		if (h[x]) return;
		h[x]=d;
		ns.push_back(x);
		for (auto nx:g[x]) {
			if (nx.S!=pe) {
				dfs(g, nx.F, nx.S, d+1, ns);
				h[x]=min(h[x], h[nx.F]);
			}
		}
		if (h[x]==d) {
			while (ns.size()>0) {
				int t=ns.back();
				c[t]=x;
				ns.pop_back();
				if (t==x) break;
			}
		}
	}
	Bridges(vector<pair<int, int> >* g, int n) : c(n+1), h(n+1) {
		vector<int> ns;
		for (int i=1;i<=n;i++) {
			dfs(g, i, -1, 1, ns);
		}
	}
};

vector<pair<int, int> > g[404040];
pair<int, int> o[404040];
int ea[404040];
int eb[404040];
int isb[404040];

vector<pair<int, pair<int, int> > > gc[404040];
int cs[404040];

int u0[404040];

void dfs0(int x){
	u0[x]=1;
	for (auto nx:g[x]){
		if (isb[nx.S]==0){
			if (o[nx.S].F==0){
				o[nx.S]={x, nx.F};
				if (u0[nx.F]==0){
					dfs0(nx.F);
				}
			}
		}
	}
}

int dfs1(int x, int p, int li){
	int go=0;
	int mane=0;
	for (auto nx:gc[x]){
		if (nx.F!=p){
			int asd=dfs1(nx.F, x, li);
			if (asd<=0){
				go+=-asd;
				if (nx.S.S==1) o[nx.S.F]={ea[nx.S.F], eb[nx.S.F]};
				else o[nx.S.F]={eb[nx.S.F], ea[nx.S.F]};
			}
			else{
				mane=max(mane, asd);
				if (nx.S.S==2) o[nx.S.F]={ea[nx.S.F], eb[nx.S.F]};
				else o[nx.S.F]={eb[nx.S.F], ea[nx.S.F]};
			}
		}
	}
	int mne=0;
	mne=max(mne, li-cs[x]-go);
	mne=max(mne, mane-cs[x]-go);
	if (mne>0) return mne;
	else return -(cs[x]+go);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		cin>>ea[i]>>eb[i];
		g[ea[i]].push_back({eb[i], i});
		g[eb[i]].push_back({ea[i], i});
	}
	Bridges b(g, n);
	for (int i=1;i<=n;i++){
		cs[b.c[i]]++;
	}
	for (int i=1;i<=m;i++){
		if (b.c[ea[i]]!=b.c[eb[i]]){
			isb[i]=1;
			gc[b.c[ea[i]]].push_back({b.c[eb[i]], {i, 1}});
			gc[b.c[eb[i]]].push_back({b.c[ea[i]], {i, 2}});
		}
	}
	for (int i=1;i<=n;i++){
		if (cs[i]>0){
			dfs0(i);
		}
	}
	int r=0;
	for (int i=1;i<=n;i++){
		if (cs[i]>0){
			r=i;
			break;
		}
	}
	int mi=0;
	int ma=n;
	int v=0;
	while (mi<=ma){
		int mid=(mi+ma)/2;
		int asd=dfs1(r, 0, mid);
		if (asd<=0){
			v=mid;
			mi=mid+1;
		}
		else{
			ma=mid-1;
		}
	}
	dfs1(r, 0, v);
	cout<<v<<'\n';
	for (int i=1;i<=m;i++){
		cout<<o[i].F<<" "<<o[i].S<<"\n";
	}
}