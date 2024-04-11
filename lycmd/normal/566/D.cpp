#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,q,f[N],r[N];
int find(int x){
	return x^f[x]?f[x]=find(f[x]):x;
}
int check(int x,int y){
	return find(x)==find(y);
}
int merge(int x,int y){
	int fx=find(x),fy=find(y);
	return fx^fy?(f[fx]=fy,1):0;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		f[i]=i,r[i]=i+1;
	while(q--){
		int op,x,y;cin>>op>>x>>y;
		switch(op){
			case 1:merge(x,y);break;
			case 2:for(int i=x+1;i<=y;x=r[i],r[i]=r[y],i=x)merge(i-1,i);break;
			case 3:cout<<(check(x,y)?"YES\n":"NO\n");break;
		}
	}
}//