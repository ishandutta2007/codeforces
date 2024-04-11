#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <cmath>
using namespace std;
const int inf=0x3f3f3f3f;
int n,g[1001][1001],cnt=0,ans=-inf;
string trans(string x){
	for(int i=0;i<x.size();i++)if(x[i]>='a')x[i]-=32;
	return x;
}
map<string,int> M;
string u,v,x;
int main() {
	scanf("%d",&n);
	for(int i=1;i<=1000;i++)
		for(int j=1;j<=1000;j++)
			if(i!=j)g[i][j]=inf;
	for(int i=0;i<n;i++){
		cin >> u >> x >> v;
		u=trans(u);v=trans(v);
		if(!M.count(u))M[u]=++cnt;
		if(!M.count(v))M[v]=++cnt;
		g[M[v]][M[u]]=1;
		g[M[u]][M[v]]=1;
	}
	for(int k=1;k<=cnt;k++)
		for(int i=1;i<=cnt;i++)
			for(int j=1;j<=cnt;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	int s=M["POLYCARP"];
	for(int i=1;i<=cnt;i++){
		if(g[s][i]!=inf)ans=max(ans,g[s][i]);
	}
	printf("%d",ans+1);
}