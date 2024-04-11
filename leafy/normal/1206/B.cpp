#include<bits/stdc++.h>
using namespace std;
#define int long long 
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
const int N=1e5+5;
int n;
int a[N];
int ans=0;
int num=0;
signed main(){
	n=read();int flag=1;
	for(int i=1;i<=n;i++) {
		a[i]=read();
		if(a[i]) {
			if(abs(1-a[i])<abs(-1-a[i])) ans+=abs(1-a[i]);
			else ans+=abs(-1-a[i]),flag*=-1;
		}
		else num++;
	}
	if(!num) printf("%I64d",ans+(flag!=1)*2);
	else printf("%I64d",ans+num);
	return 0;
}