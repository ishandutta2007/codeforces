#include<bits/stdc++.h>
using namespace std;
int const N=35;
int m,n,a[N];
int query(int x){
	cout<<x<<endl,cin>>x;
	return x;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		a[i]=query(1);
		if(!a[i])return 0;
	}
	int l=1,r=m+1;
	for(int i=0;l<r-1;i++){
		int mid=(l+r)>>1,res=query(mid)*a[i%n+1];
		if(!res)exit(0);
		if(res<0)r=mid;else l=mid;
	}
}