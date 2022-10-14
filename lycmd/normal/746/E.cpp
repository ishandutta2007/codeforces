#include<bits/stdc++.h>
using namespace std;
int const N=500010;
int n,m,a[N],cnt[2];
set<int>vis;
vector<int>p;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		if(cin>>a[i],vis.count(a[i])||cnt[a[i]&1]==n/2)
			p.push_back(i);
		else
			vis.insert(a[i]),cnt[a[i]&1]++;
	int c=0;
	for(int i=1;i<=m&&c<p.size();i++)
		if(!vis.count(i)&&cnt[i&1]<n/2&&c<p.size())
			a[p[c++]]=i,cnt[i&1]++;
	if(c<p.size())
		cout<<"-1\n",exit(0);
	cout<<c<<"\n";
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}