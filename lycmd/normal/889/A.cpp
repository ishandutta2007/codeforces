#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,a[N],vis[N],cnt;
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--){
		if(vis[i])continue;
		int p=i;
		while(p&&!vis[p])vis[p]=1,p=a[p];
		cnt++; 
	}
	cout<<cnt<<"\n";
	return 0;
}