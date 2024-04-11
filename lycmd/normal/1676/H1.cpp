#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int t,n,a[N],tr[N];
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
	for(cin>>t;t--;){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i],tr[i]=0;
		int res=0;
		for(int i=1;i<=n;i++)
			res+=i-ask(a[i]-1)-1,add(a[i],1);
		cout<<res<<"\n";
	}
}