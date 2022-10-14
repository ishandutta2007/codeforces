#include<bits/stdc++.h>
#define gb(x) (__builtin_ctz(x)+1)
using namespace std;
int const N=25,M=17000010,INF=0x3f3f3f3f;
int n,s,x[N],y[N],f[M],pre[M];
int dis(int i,int j){
	return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}
void print(int x){
	if(!x)return;
	int t=x^pre[x];
	print(pre[x]),cout<<gb(t)<<" ";
	if(t&=t-1)cout<<gb(t)<<" ";
	cout<<"0 ";
}
int main(){
	ios::sync_with_stdio(0);
	cin>>x[0]>>y[0]>>n,s=(1<<n)-1;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	memset(f,0x3f,sizeof f),f[0]=0;
	for(int i=1;i<=s;i++)
		for(int y=1;y<=n;y++)
			if(i>>(y-1)&1){
				int x=gb(i),t=i^(1<<(x-1)|(1<<(y-1)));
				if(f[i]>f[t]+dis(0,x)+dis(x,y)+dis(y,0))
					f[i]=f[t]+dis(0,x)+dis(x,y)+dis(y,0),pre[i]=t;
			}
	cout<<f[s]<<"\n0 ";
	print(s);
}