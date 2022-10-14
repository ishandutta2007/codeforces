#include<bits/stdc++.h>
using namespace std;
int const N=233;
int t,n,p[N];
struct dsu{
	int f[N];
	void init(int n){
		for(int i=1;i<=n;i++)
			f[i]=i;
	}
	int find(int x){
		return x^f[x]?f[x]=find(f[x]):x;
	}
	int merge(int x,int y){
		return x=find(x),y=find(y),x^y?(f[x]=y,1):0;
	}
};
dsu g;
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n,g.init(n);
		for(int i=1,x;i<=n;i++)
			cin>>x,p[x]=i,g.merge(x,i);
		for(int i=1;i<n;i++)
			if(g.merge(i,i+1))
				swap(p[i],p[i+1]);
		for(int i=1,j=1;i<=n;i++,j=p[j])
			cout<<j<<" ";
		cout<<"\n";
	}
}