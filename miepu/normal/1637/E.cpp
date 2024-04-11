#pragma GCC optimize(3) 
#include<bits/stdc++.h>
#define int long long
const int N=300005,T=800;
using namespace std;

map<pair<int,int>,int> a;
int n,m,ct[N],pr[N],A[N];
map<int,int> cnt,mx,id;
vector<int> pos[T];

void solve(){
	cnt.clear();
	a.clear();
	id.clear();
	mx.clear();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		cnt[x]++; 
	}
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		a[{x,y}]=a[{y,x}]=1; 
	}
	int cc=0;
	for(auto x:cnt){
		mx[x.second]=max(mx[x.second],x.first);
		A[++cc]=x.first;
	}
	vector<int> oc;
	int c=0;
	for(auto x:mx)
		oc.push_back(x.first),id[x.first]=c,ct[c]=x.first,c++;
	int ccc=oc.size();
	for(int i=0;i<ccc;i++)pos[i].clear();
	for(auto x:cnt){
		pos[id[x.second]].push_back(x.first);
	}
	for(int i=0;i<ccc;i++)sort(pos[i].begin(),pos[i].end()),reverse(pos[i].begin(),pos[i].end());
	int ans=0;
	for(int i=0;i<ccc;i++){
		for(int j=i;j<ccc;j++){
			int X=oc[i],Y=oc[j];
			for(int x:pos[i])
				for(int y:pos[j])
					if(!a[{x,y}]){
						if(x==y)continue;
						ans=max(ans,(X+Y)*(x+y));
						break;
					}
		}
	}
	cout<<ans<<'\n';
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}