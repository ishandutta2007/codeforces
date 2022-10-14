#include<bits/stdc++.h>
using namespace std;
int const N=55;
int n,m,x,y,f[N],d[N];
vector<pair<int,int> >ans;
int find(int x){
	return x^f[x]?f[x]=find(f[x]):x;
}
int merge(int x,int y){
	int fx=find(x),fy=find(y);
	return fx^fy?(f[fx]=fy,1):0;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		if(i==m&&n==m&&d[x]==1&&d[y]==1)
			cout<<"YES\n0\n",exit(0);
		if((n>1&&!merge(x,y))||++d[x]>2||++d[y]>2)
			cout<<"NO\n",exit(0);
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(d[i]<2&&d[j]<2&&merge(i,j))
				d[i]++,d[j]++,ans.push_back({i,j});
	for(int i=1;i<=n;i++)
		if(d[i]<2)
			for(int j=i;j<=n;j++)
				if(d[j]<2&&(n==1||i<j))
					ans.push_back({i,j});
	sort(ans.begin(),ans.end());
	cout<<"YES\n"<<ans.size()<<"\n";
	for(auto i:ans)
		cout<<i.first<<" "<<i.second<<"\n"; 
}