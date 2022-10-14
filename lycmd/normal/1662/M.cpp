#include<bits/stdc++.h>
using namespace std;
int const N=233;
int t,n,m,r[N],w[N];
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>m;
		int mxr=0,mxw=0;
		for(int i=1;i<=m;i++)
			cin>>r[i]>>w[i],mxr=max(mxr,r[i]),mxw=max(mxw,w[i]);
		cout<<(mxr+mxw>n?"IMPOSSIBLE\n":
			string(mxr,'R')+string(n-mxr,'W')+"\n");
	}
}