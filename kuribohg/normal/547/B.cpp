#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=400010;
int n,a[MAXN];
int S[MAXN],top;
int L[MAXN],R[MAXN];
int ans[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		while(top>0&&a[S[top]]>a[i]) R[S[top]]=i,top--;
		S[++top]=i;
	}
	for(int i=1;i<=n;i++) if(!R[i]) R[i]=n+1;
	top=0;
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		while(top>0&&a[S[top]]>a[i]) L[S[top]]=i,top--;
		S[++top]=i;
	}
	for(int i=1;i<=n;i++) if(!L[i]) L[i]=n+1;
	reverse(L+1,L+n+1);
	for(int i=1;i<=n;i++) L[i]=n+1-L[i];
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++) ans[R[i]-L[i]-1]=max(ans[R[i]-L[i]-1],a[i]);
	for(int i=n+2;i>=1;i--) ans[i]=max(ans[i],ans[i+1]);
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}