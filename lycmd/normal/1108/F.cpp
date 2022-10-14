#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int,int> node;
int const N=233333;
int n,m,ans,cnt,f[N];
map<int,vector<node> >mp;
int find(int x){
	return x^f[x]?f[x]=find(f[x]):x;
}
int check(int x,int y){
	return find(x)==find(y);
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
	while(m--){
		int a,b,c;cin>>a>>b>>c;
		mp[c].push_back({a,b});
	}
	for(auto i:mp){
		for(auto j:i.second)
			if(!check(j.x,j.y))
				ans++;
		for(auto j:i.second)
			if(merge(j.x,j.y))
				ans--;
	}
	cout<<ans<<"\n";
}