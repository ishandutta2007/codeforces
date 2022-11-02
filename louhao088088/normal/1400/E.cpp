#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=((x<<1)+(x<<3)+(ch^48));
	if(f==1)x=-x;return x;
}
int a[maxn],n,m,ans,Max;
int getans(int l,int r)
{
	int M=1e9+5,num=0,l1=l;//cout<<l<<" "<<r<<endl;
	if(l==r&&a[l]==0)return 0;
	if(l==r)return 1;
	for(int i=l;i<=r;i++)if(a[i]<M)M=a[i];num=M;
	for(int i=l;i<=r;i++)
	{
		a[i]=a[i]-M;
		if(a[i]==0)
		{
			if(l1<=i-1)num=num+getans(l1,i-1);l1=i+1;
		}
		else if(i==r&&l1<=r)
		{
			num=num+getans(l1,r);
		}
	}//cout<<l<<" "<<r<<" "<<num<<" "<<M<<endl;
	return min(r-l+1,num);
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	ans=getans(1,n);
	cout<<ans<<endl;
}