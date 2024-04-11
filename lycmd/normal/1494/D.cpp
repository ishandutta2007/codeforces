#include<bits/stdc++.h>
using namespace std;
int const N=2333;
int n,tot,a[N][N],fa[N],v[N],vis[N][N];
vector<int>t;
inline int solve(vector<int>t){
	int k=t.size(),rv=t[0],mx=0;
	if(k==1)
		return(v[rv]=a[rv][rv],rv);
	for(int i=1;i<k;i++)
		mx=max(mx,a[rv][t[i]]);
	int rt=++tot;
	v[rt]=mx;
	vector<int>s;
	for(int i=0;i<k;i++)
		if(!vis[rt][i]){
			s.clear();
			for(int j=i;j<k;j++)
				if(a[t[i]][t[j]]<mx)
					s.push_back(t[j]),vis[rt][j]=1;
			fa[solve(s)]=rt;
		}
	return rt;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n,tot=n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		t.push_back(i);
	int rt=solve(t);
	cout<<tot<<"\n";
	for(int i=1;i<=tot;i++)
		cout<<v[i]<<" ";
	cout<<"\n"<<rt<<"\n";
	for(int i=1;i<=tot;i++)
		if(i!=rt)
			cout<<i<<" "<<fa[i]<<"\n";
}