#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=1000010;
int n,ans,a[N],tr[N],t[N];
map<int,int>cnt;
void add(int x,int y){
	for(;x<=n;x+=x&-x)tr[x]+=y;
}
int ask(int x){
	int res=0;
	for(;x;x&=x-1)res+=tr[x];
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cnt.clear();
	for(int i=n;i;i--) 
		add(t[i]=++cnt[a[i]],1);
	cnt.clear();
	for(int i=1;i<=n;i++)
		add(t[i],-1),ans+=ask(cnt[a[i]]++);
	cout<<ans<<"\n";
}