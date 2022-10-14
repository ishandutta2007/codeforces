#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=200010;
int n,rt1,rt2,a[N];
int fa(int x){
	return!x?1:x&(x-1)?(1ll<<(64-__builtin_clzll(x)))-x:0;
}
int calc(int x,int y){
	int cnt=0;
	for(;x^y;cnt++,y=fa(y))
		if(x>y)swap(x,y);
	return cnt;
}
int find(int x){
	int p=1;
	for(int i=1;i<=n;i++)
		if(calc(a[x],a[p])<calc(a[x],a[i]))
			p=i;
	return p;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	rt2=find(rt1=find(1));
	cout<<rt1<<" "<<rt2<<" "<<calc(a[rt1],a[rt2])<<"\n";
}