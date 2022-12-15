#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define LL long long
using namespace std;
const int N=1e6+10;
int n,m,k;
int a[N],c[20000005],d[N];
int b[35];
int main(){
	scanf("%d",&n);
	int x,v,y,mx=0;
	for(int i=1;i<=n;++i) {
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
		if(n%2==0){
			x=0;y=a[i];
			while(y){
				if(y&1) b[x]^=1;
				y>>=1;++x;
			}
		}
	}
	x=0;y=0;
	LL z=0,w=0;
	for(int j=1;(1<<j)<=mx+mx;++j){
		v=(1<<j);w=0;
		//cout<<"v "<<v<<endl;
		for(int i=1;i<=n;++i) {
			d[i]=a[i]&(v-1);
			c[d[i]]++;
		}
		for(int p=1;p<v/2;++p){
			w=w+c[v-p];
			z=(LL)c[p]*(LL)w;
			if(z&1) b[j]^=1;
		}
		//cout<<b[j]<<endl;
		w=w+c[v/2];
		//cout<<w<<endl;
		z=(LL)w*(LL)(w-1)/(LL)2;
		if(z&1) b[j]^=1;
		//cout<<b[j]<<endl;
		for(int i=1;i<=n;++i) {
			d[i]=a[i]&(v-1);
			c[d[i]]--;
		}
		//for(int i=1;i<=10;++i) cout<<c[i]<<" ";cout<<endl;
	}
	v=1;
	int ans=0;
	for(int i=0;i<=30;++i){
		if(b[i]&1) ans=ans+v;
		v=v<<1;
	}
	printf("%d\n",ans);
	return 0;
}