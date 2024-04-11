#include<bits/stdc++.h>
using namespace std;
int a[5001];
map<int,int>mp;
int main(){
	int m,n;
	cin>>m>>n;
	for(int x=1;x<=m;x++){
	cin>>a[x];
	for(int y=1;y<=n;y++)
	if(mp[a[x]*y]==0)mp[a[x]*y]=y;
	else mp[a[x]*y]=min(mp[a[x]*y],y);}
	int q;
	cin>>q;
	while(q--){
		int ans=n+1,qq;
		cin>>qq;
		for(int x=1;x<=m;x++)
		for(int y=0;y<=n;y++)
		if(mp[qq-y*a[x]])ans=min(ans,y+mp[qq-y*a[x]]);
		cout<<(ans!=n+1?ans:-1)<<endl;
	}
}