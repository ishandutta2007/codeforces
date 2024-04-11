#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
int mp[405];
int n,m;
int a[405],b[405];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],mp[a[i]]=1;
	cin>>m;
	for(int i=1;i<=m;i++) cin>>b[i],mp[b[i]]=1;
	for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--)
			if(!mp[a[i]+b[j]]){
				printf("%d %d",a[i],b[j]);
				return 0;
			}
	return 0;
}