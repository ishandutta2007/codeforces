#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333,M=233;
int n,ans,v[M],s[N];
string a;
vector<int>p[M];
map<int,int>cnt;
signed main(){
	ios::sync_with_stdio(0);
	for(int i='a';i<='z';i++)
		cin>>v[i];
	cin>>a,n=a.size(),a=" "+a;
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+v[a[i]];
	for(int i=1;i<=n;i++)
		p[a[i]].push_back(i);
	for(int i='a';i<='z';i++){
		cnt.clear();
		for(int j:p[i])
			ans+=cnt[s[j]-v[i]],cnt[s[j]]++;
	}
	cout<<ans<<"\n";
}