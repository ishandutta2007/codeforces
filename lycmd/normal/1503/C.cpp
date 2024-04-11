#include<bits/stdc++.h>
#define int long long 
#define node pair<int,int>
#define a first
#define c second
using namespace std;
int const N=233333;
int n,ans,pre;
node p[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].a>>p[i].c,ans+=p[i].c;
	sort(p+1,p+1+n);
	for(int i=1;i<n;i++)
		ans+=max(p[i+1].a-(pre=max(pre,p[i].a+p[i].c)),0ll);
	cout<<ans<<"\n";
}