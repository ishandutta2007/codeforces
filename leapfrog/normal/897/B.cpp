#include<bits/stdc++.h>
using namespace std;
int k,P;
inline int work(int x)
{
	int t[105],cnt=0,r=0,zk=1;
	while(x) t[++cnt]=x%10,x/=10;
	for(int i=cnt;i>=1;i--) r=(r+1ll*zk*t[i]%P)%P,zk=1ll*zk*10%P;
	for(int i=1;i<=cnt;i++) r=(r+1ll*zk*t[i]%P)%P,zk=1ll*zk*10%P;
	return r;
}
int main()
{
	scanf("%d%d",&k,&P);int r=0;
	for(int i=1;i<=k;i++) r=(r+work(i))%P;
	return printf("%d\n",r),0;
}