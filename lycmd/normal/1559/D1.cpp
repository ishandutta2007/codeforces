#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,m1,m2,f[N][2];
vector<int>a,b1,b2;
inline int find(int x,int op){
	return x==f[x][op]?x:f[x][op]=find(f[x][op],op);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m1>>m2;
	for(int i=1;i<=n;i++)
		f[i][0]=f[i][1]=i;
	while(m1--){
		int x,y;cin>>x>>y;
		int fx=find(x,0),fy=find(y,0);
		if(fx!=fy)f[fx][0]=fy;
	}
	while(m2--){
		int x,y;cin>>x>>y;
		int fx=find(x,1),fy=find(y,1);
		if(fx!=fy)f[fx][1]=fy;
	}
	for(int i=2;i<=n;i++)
		if(find(i,0)!=find(1,0)&&find(i,1)!=find(1,1))
			a.push_back(i),f[find(i,0)][0]=find(1,0),f[find(i,1)][1]=find(1,1);
	for(int i=2;i<=n;i++)
		if(find(i,0)!=find(1,0))
			b1.push_back(i),f[find(i,0)][0]=find(1,0);
		else if(find(i,1)!=find(1,1))
			b2.push_back(i),f[find(i,1)][1]=find(1,1);
	cout<<a.size()+min(b1.size(),b2.size())<<"\n";
	for(int i=0;i<a.size();i++)
		cout<<a[i]<<" 1\n";
	for(int i=0;i<min(b1.size(),b2.size());i++)
		cout<<b1[i]<<" "<<b2[i]<<"\n";
}