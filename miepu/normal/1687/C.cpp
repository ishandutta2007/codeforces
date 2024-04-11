#include<bits/stdc++.h>
#define int long long
const int N=1005000;
using namespace std;

int a[N],b[N],sa,sb;
int n,m;
set<int> A;
int vis[N];
vector<int> L[N],R[N];

void Set(int k);
void erase(int l,int r){
	vector<int> nw;
	auto it=A.lower_bound(l);
	while(it!=A.end()&&*it<=r){
		nw.push_back(*it);
		it++;
	}
	for(auto x:nw)A.erase(x);
	for(auto x:nw)Set(x);
}

void Set(int k){
	if(vis[k])return;
	A.erase(k);
	for(auto x:L[k])
		if(vis[x])
			erase(k+1,x);
	for(auto x:R[k])
		if(vis[x])
			erase(x+1,k);
	vis[k]=1;
}

void solve(){
	cin>>n>>m;
	sa=sb=0;
	for(int i=0;i<=n;i++)L[i].clear(),R[i].clear();
	for(int i=1;i<=n;i++)cin>>a[i],sa+=a[i];
	for(int i=1;i<=n;i++)cin>>b[i],sb+=b[i];
	for(int i=1;i<=m;i++){
		int l,r;cin>>l>>r;
		L[l-1].push_back(r);
		R[r].push_back(l-1);
	}
	if(sa!=sb){
		cout<<"No\n";return ;
	}
	A.clear();
	for(int i=0;i<=n;i++)A.insert(i),vis[i]=0;
	sa=sb=0;
	for(int i=0;i<=n;i++){
		if(sa==sb)Set(i);
		sa+=a[i+1],sb+=b[i+1];
	}
	cout<<(A.size()?"No":"Yes")<<'\n';
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}