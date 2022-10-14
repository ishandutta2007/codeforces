#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a;
multiset<int>s;
vector<int>v;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n*n;i++)
		cin>>a,s.insert(a);
	for(int i=1;i<=n;i++){
		int k=*s.rbegin();
		s.erase(s.find(k));
		for(int j=0;j<v.size();j++)
			s.erase(s.find(gcd(k,v[j]))),
			s.erase(s.find(gcd(k,v[j])));
		v.push_back(k);
	}
	assert(s.empty());
	reverse(v.begin(),v.end());
	for(int i=0;i<n;i++)
		cout<<v[i]<<" ";
	cout<<"\n";
}