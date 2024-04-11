#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void read(ll &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

#define maxn 200010
ll n;
ll a[maxn],s[maxn];
int f[maxn];
int que[maxn],cnt;
double point[maxn];

int find(int t)
{
	if (cnt==0)	return 0;
	if (cnt==1)	return que[1];
	int l=1,r=cnt;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (point[mid]<t)	r=mid;else l=mid+1;
	}
	return que[l];
}
void insert(int k)
{
	while (cnt>1)
	{
		int j=que[cnt];
		if (s[k]>=s[j])	return;
		double mjy=(s[j]-s[k])/(j-k);
		if (mjy>point[cnt-1])	cnt--;
		else break;
	}
	double mjy=(s[que[cnt]]-s[k])/(que[cnt]-k);
	point[cnt]=mjy;
	que[++cnt]=k;
}
int find2(int t)
{
	if (cnt==0)	return 0;
	if (cnt==1)	return que[1];
	int l=1,r=cnt;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (point[mid]>t)	r=mid;else l=mid+1;
	}
	return que[l];
}
void insert2(int k)
{
	while (cnt>1)
	{
		int j=que[cnt];
		double mjy=(s[j-1]-s[k-1])/(j-k);
		if (mjy<=point[cnt-1])	cnt--;
		else break;
	}
	double mjy=(s[que[cnt]-1]-s[k-1])/(que[cnt]-k);
	point[cnt]=mjy;
	que[++cnt]=k;
}
int main()
{
	read(n);
	ll mxh=0;
	for (int i=1;i<=n;i++)	read(a[i]),mxh+=a[i]*i;
	for (int i=1;i<=n;i++)	s[i]=s[i-1]+a[i];
	for (int i=n;i>=1;i--)
	{
		f[i]=find(a[i]);
		insert(i);
	}
	ll mjy=0;
	for (int i=1;i<=n;i++)
	if (f[i]!=0)	mjy=max(mjy,a[i]*(f[i]-i)-s[f[i]]+s[i]);
	ll mmdmjy=mxh+mjy;
	memset(que,0,sizeof(que));
	memset(point,0,sizeof(point));
	cnt=0;
	for (int i=1;i<=n;i++)
	{
		f[i]=find2(a[i]);
		insert2(i);
	}
	mjy=0;
	for (int i=1;i<=n;i++)
	if (f[i]!=0)	mjy=max(mjy,a[i]*(f[i]-i)-s[f[i]-1]+s[i-1]);
	mmdmjy=max(mmdmjy,mxh+mjy);
	cout<<mmdmjy<<endl;
	return 0;
}