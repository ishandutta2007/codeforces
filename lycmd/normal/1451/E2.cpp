#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,xr[N],vis[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	int flgzr=0,flgeq=0;
	for(int i=2;i<=n;i++){
		cout<<"XOR 1 "<<i<<endl;
		cin>>xr[i];
		if(!xr[i])flgzr=i;
		if(vis[xr[i]])flgeq=i;
		else vis[xr[i]]=i;
	}
	if(flgzr){
		cout<<"OR 1 "<<flgzr<<endl;
		int a1;cin>>a1;
		cout<<"! "<<a1;
		for(int i=2;i<=n;i++)
			cout<<" "<<(a1^xr[i]);
		cout<<endl;
	}else if(flgeq){
		cout<<"OR "<<flgeq<<" "<<vis[xr[flgeq]]<<endl;
		int a1;cin>>a1;a1^=xr[flgeq];
		cout<<"! "<<a1;
		for(int i=2;i<=n;i++)
			cout<<" "<<(a1^xr[i]);
		cout<<endl;
	}else{
		int p1,p2,a1,t;
		for(int i=2;i<=n;i++){
			if(xr[i]==1)p1=i;
			if(xr[i]==2)p2=i; 
		}
		cout<<"OR 1 "<<p1<<endl,cin>>a1,a1>>=1,a1<<=1;
		cout<<"OR 1 "<<p2<<endl,cin>>t,a1|=t&1;
		cout<<"! "<<a1;
		for(int i=2;i<=n;i++)
			cout<<" "<<(a1^xr[i]);
		cout<<endl;
	}
}