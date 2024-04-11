#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

map<int,LL> mp;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int b;
		cin>>b;
		mp[b-i]+=b;
	}
	LL mx=0;
	for(pair<int,LL> p:mp){
		mx=max(mx,p.second);
	}
	cout<<mx<<endl;
	return 0;
}