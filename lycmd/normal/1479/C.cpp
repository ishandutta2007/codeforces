#include<bits/stdc++.h>
#define int long long
using namespace std;
int l,r,n;
struct edge{int x,y,w;};
vector<edge>e;
signed main(){
	ios::sync_with_stdio(0);
	cin>>l>>r;
	n=log2(r-l+1)+2;
	for(int i=2;i<=n+1;i++)
		e.push_back({1,i,1});
	for(int i=2;i<n;i++)
		for(int j=i+1;j<=n;j++)
			e.push_back({i,j,1ll<<i-2});
	int s=0;
	for(int i=n;i>=2;i--){
		if((r-l>>i-1)&1)
			s+=1ll<<i-1;
		if((r-l>>i-2)&1)
			e.push_back({i,n+1,s+1});
	}
	n++;
	if(l>1)
		e.push_back({n,++n,l-1});
	cout<<"YES\n"<<n<<" "<<e.size()<<"\n";
	for(int i=0;i<e.size();i++)
		cout<<e[i].x<<" "<<e[i].y<<" "<<e[i].w<<"\n";
}