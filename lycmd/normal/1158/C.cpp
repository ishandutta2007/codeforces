#include<bits/stdc++.h>
using namespace std;
int const N=500010;
int t,n,cur,a[N],p[N];
int solve(int x){
	int i=x;
	while(i>1&&(p[i-1]==x||p[i-1]==-1))
		i=solve(i-1);
	a[x]=++cur;
	return i;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n,cur=0;
		for(int i=1;i<=n;i++)
			cin>>p[i];
		if(solve(n+1)>1){
			cout<<"-1\n";
		}else{
			for(int i=1;i<=n;i++)
				cout<<a[i]<<" ";
			cout<<"\n"; 
		}
	}
}