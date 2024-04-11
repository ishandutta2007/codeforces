#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=100006;
int n,a[N],b[N],c[N],d[N],i,u,v;
long long s;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<=n;i++)
		scanf("%d",b+i);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	u=v=n;
	while(u||v){
		if(!v)s+=a[u--];
		else if(!u)v--;
		else if(a[u]>b[v]) s+=a[u--];
		else v--;
		if(!u)s-=b[v--];
		else if(!v)u--;
		else if(b[v]>a[u])s-=b[v--];
		else u--;
	}
	cout<<s;
}