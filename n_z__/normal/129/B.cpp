#include<bits/stdc++.h>
using namespace std;
int d[101];
bool c[101][101];
int e[101];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1,a,b;i<=m;i++)
	cin>>a>>b,d[a]++,d[b]++,c[a][b]=1,c[b][a]=1;
	int cc=1,ans=0;
	while(cc>0){
	    memset(e,0,sizeof(e));
	    ans++;
		cc=0;
		for(int i=1;i<=n;i++)
		if(d[i]==1)e[cc++]=i,d[i]--;
		for(int i=0;i<cc;i++)
		for(int j=1;j<=n;j++)
		if(c[e[i]][j])d[j]--;
	}
	cout<<ans-1<<endl;
}