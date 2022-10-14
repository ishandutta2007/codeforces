#include<bits/stdc++.h>
using namespace std;
int n,m,mx;
vector<int>ans;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			int x=i,y=j,col=0;
			while(x!=y)x/=m,y/=m,col++;
			mx=max(mx,col),ans.push_back(col);
		}
	cout<<mx<<"\n";
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
}