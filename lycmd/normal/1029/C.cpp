#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> node;
int const N=300010;
int n,ans;
node a[N],ls[N],rs[N];
node merge(node a,node b){
	return{max(a.first,b.first),min(a.second,b.second)};
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].first>>a[i].second;
	ls[0]=rs[n+1]={0,1000000000};
	for(int i=1;i<=n;i++)
		ls[i]=merge(ls[i-1],a[i]);
	for(int i=n;i;i--)
		rs[i]=merge(rs[i+1],a[i]);
	for(int i=1;i<=n;i++){
		auto t=merge(ls[i-1],rs[i+1]);
		ans=max(ans,t.second-t.first);
	}
	cout<<ans<<"\n";
}