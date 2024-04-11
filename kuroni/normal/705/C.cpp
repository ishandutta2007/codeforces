#include<iostream>
using namespace std;
int n,q,k,v,x,y,t,a[300300],b[300300],c[300300];
int main() {
	cin>>n>>q;
	while (q--)
	{
		cin>>k>>v;
		if (k==1) a[++y]=v,b[v]++,c[v]++,t++;
		else if (k==2) t-=b[v],b[v]=0;
		else while (x<v) {n=a[++x]; if(c[n]) c[n]--; if(b[n]>c[n]) t--,b[n]--;}
		cout<<t<<'\n';
	}
}