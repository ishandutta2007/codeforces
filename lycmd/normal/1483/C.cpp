#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=300010;
int n,a[N],b[N],f[N],g[N];
stack<int>s;
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++){
		int t=f[i-1];
		for(;!s.empty()&&a[i]<a[s.top()];s.pop())
			t=max(t,g[s.top()]);
		f[i]=max(s.empty()?LLONG_MIN:f[s.top()],t+b[i]),g[i]=t,s.push(i);
	}
	cout<<f[n]<<"\n";
}