#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#define all(x) x.begin(),x.end()
#define FOR(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)
#define bits(x) __builtin_popcount(x)

#define MAX 100005

int n,root,val[MAX],par[MAX],hi[MAX][2],cant[MAX],may[MAX],men[MAX],prof[MAX];
long long wrong[MAX];
vector<int> leafs;

void fill(int v) {
	if (cant[v]==0) {
		may[v]=men[v]=val[v];
		return;
	}
	fill(hi[v][0]); fill(hi[v][1]);
	may[v]=may[hi[v][1]];
	men[v]=men[hi[v][0]];
}

void fill2() {
	//vector<bool> vis(n,false);
	queue<int> cola;
	cola.push(root);
	//vis[root]=true;
	wrong[root]=0;
	prof[root]=0;
	
	while (!cola.empty()) {
		int cu=cola.front(); cola.pop();
		if (cant[cu]==0) continue;
		int le=hi[cu][0],ri=hi[cu][1];
		prof[le]=prof[ri]=prof[cu]+1;
		wrong[le]=wrong[cu]+(long long)men[ri];
		wrong[ri]=wrong[cu]+(long long)may[le];
		
		//cout<<le<<": "<<wrong[le]<<" "<<prof[le]<<endl;
		//cout<<ri<<": "<<wrong[ri]<<" "<<prof[ri]<<endl;
		cola.push(le); cola.push(ri);
	}
}

vector<pair<int,int> > claves;

int main(){
	cin>>n;
	
	memset(cant,0,sizeof(cant));
	for (int i=0;i<n;i++) {
		cin>>par[i]>>val[i];
		if (par[i]!=-1) {
			par[i]--;
			int p=par[i];
			hi[p][cant[p]]=i; cant[p]++;
		} else root=i;
		claves.push_back(make_pair(val[i],i));
	}
	
	for (int i=0;i<n;i++) {
		if (cant[i]==2) {
			if (val[hi[i][0]]>val[hi[i][1]]) swap(hi[i][0],hi[i][1]);
		} else leafs.push_back(i);
	}
	
	//for (int i=0;i<leafs.size();i++) cout<<leafs[i]<<" "; cout<<endl;
	fill(root);
	fill2();
	sort(all(claves));
	
	
	int queries,qq;
	cin>>queries;
	for (int q=0;q<queries;q++) {
		cin>>qq;
		int index = lower_bound(all(claves), make_pair(qq,0)) - claves.begin();
		int nodo;
		
		if (index==0) nodo=claves[0].second;
		else if (index==n) nodo=claves[n-1].second;
		else {
			int ant=claves[index-1].second,sig=claves[index].second;
			if (cant[ant]==0) nodo=ant;
			else nodo=sig;
		}
		double ans=wrong[nodo];
		ans/=(double)prof[nodo];
		printf("%.11f\n",ans);
	}
	
	return 0;
}