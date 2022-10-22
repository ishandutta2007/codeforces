#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define int long long
int read(){
	int w=0,f=1;
	char c=' ';
	while(c<'0'||c>'9')f=(c=='-'?-f:f),c=getchar();
	while(c>='0'&&c<='9')w=w*10+c-'0',c=getchar();
	return w*f;
}
int readc(){
	char c=getchar();
	while(c!='L'&&c!='R')c=getchar();
	return c=='L';
}
int n,l,r,a[N],b[N],w[N],ans[N],fl,cnt;
bool check(int x){
	if(fl)return w[r]-w[r-x]>0;
	return w[l+x-1]-w[l-1]>0;
}
signed main(){
	n=read(),l=1,r=n;
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		b[i]=readc();
	sort(a+1,a+n+1);
	for(int i=(n&1)^b[n];i<=n;i+=2)
		a[i]*=-1;
	for(int i=1;i<=n;i++)
		w[i]=w[i-1]+a[i];
	for(int i=n-1;i>0;i--)
		fl^=b[i]^check(i),ans[++cnt]=fl?a[l++]:a[r--];
	assert(l==r);
	ans[++cnt]=a[l];
	for(int i=n;i>0;i--)
		printf("%lld %c\n",ans[i]>0?ans[i]:-ans[i],ans[i]>0?'L':'R');
	return 0;
}