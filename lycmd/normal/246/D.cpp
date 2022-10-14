#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,m,ans,a[N],flg[N];
set<int>s[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],flg[a[i]]=1;
	while(m--){
		int x,y;cin>>x>>y;
		if(a[x]==a[y])continue;
		s[a[x]].insert(a[y]),s[a[y]].insert(a[x]);
	}
	for(int i=1;i<N;i++)
		if(flg[i]){
			if(!ans||s[i].size()>s[ans].size())
				ans=i;
		}
	cout<<ans<<"\n";
}