#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int t,n,m,c[N];
vector<int>e[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			c[i]=0,e[i].clear();
		while(m--){
			int x,y;cin>>x>>y;
			e[y].push_back(x);
		}
		for(int i=1;i<=n;i++)
			for(int j:e[i])
				if(c[j]==1)c[i]=2;
				else if(!c[j]&&c[i]!=2)c[i]=1;
		int cnt=0;
		for(int i=1;i<=n;i++)
			cnt+=c[i]==2;
		cout<<cnt<<"\n";
		for(int i=1;i<=n;i++)
			if(c[i]==2)cout<<i<<" ";
		cout<<"\n";
	}
}