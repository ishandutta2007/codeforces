#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,a[N],v[N];
set<int>s[N];
vector<int>e[N];
void solve(int x,int fa){
	for(int i:s[fa])
		s[x].insert(__gcd(a[x],i));
	int t=v[fa];
	v[x]=__gcd(t,a[x]);
	s[x].insert(t);
	s[x].insert(__gcd(a[x],t));
	for(int y:e[x])
		if(y!=fa)
			solve(y,x);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1,x,y;i<n;i++)
		cin>>x>>y,e[x].push_back(y),e[y].push_back(x);
	solve(1,0);
	for(int i=1;i<=n;i++)
		cout<<*s[i].rbegin()<<" ";
	cout<<"\n";
}