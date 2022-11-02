#include<cstdio>
#include<iostream>
using namespace std;
const int N=100002;
int n,i,j,x,y,a[N],f[N],p[N],t[N];
long long s[N],S,ans[N];
int F(int x){
	return x==f[x]?x:f[x]=F(f[x]);
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<=n;i++)
		scanf("%d",p+i);
	for(i=n;i;i--){
			ans[i]=S;
		x=p[i];
		t[x]=1;
		f[x]=x;
		s[x]=a[x];
		if(t[x-1]){
			y=F(x-1);
			f[y]=x;
			s[x]+=s[y];
		}
		if(t[x+1]){
			y=F(x+1);
			f[y]=x;
			s[x]+=s[y];
		}
		if(s[x]>S)
			S=s[x];
	}
	for(i=1;i<=n;i++)
		cout<<ans[i]<<endl;
	//while(1);
}