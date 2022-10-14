#include<bits/stdc++.h>
using namespace std;
int const N=10010;
int n;
pair<int,int>a[N];
set<pair<int,int> >s;
void solve(int l,int r){
	if(l>=r)return;
	int mid=(l+r)>>1;
	solve(l,mid),solve(mid+1,r); 
	for(int i=l;i<=r;i++)
		s.insert({a[mid].first,a[i].second});
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].first>>a[i].second,s.insert(a[i]);
	sort(a+1,a+1+n);
	solve(1,n);
	cout<<s.size()<<"\n";
	for(auto i:s)
		cout<<i.first<<" "<<i.second<<"\n";
}