#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <set>
#include <algorithm>
#define ll long long 
#define pii pair<int,int>
template <typename T> inline void chmin(T &x,const T &b) {x=(x<b?x:b);}
template <typename T> inline void chmax(T &x,const T &b) {x=(x>b?x:b);}
using namespace std;
int n,m;
char a[200005];
char b[200005];
int c[200005],d[200005];

inline bool check(int mid)
{
	for(int l=1;l<=n;l++)
	{
		int r=n-(mid-1)-l;
		// if(r<1) continue;
		// cout<<l<<' '<<r<<endl;
		if(c[l]==0 || r<0 || d[r]==0) continue;
		if(c[l]+d[r]>=m) return true;
	}
	return false;
}

int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s%s",a,b);
	c[0]=0;
	for(int i=1;i<=n;i++)
	{
		c[i]=c[i-1];
		// if(i==1) cout<<(c[i]<m)<<' '<<(a[i-1]==b[c[i]])<<endl;
		if(c[i]<m && a[i-1]==b[c[i]]) c[i]++;
	}
	// cout<<a[0]<<' '<<b[c[1]]<<endl;
	// cout<<c[1]<<endl;
	d[0]=0;
	for(int i=1;i<=n;i++)
	{
		d[i]=d[i-1];
		if(d[i]<m && a[n-i]==b[m-1-d[i]]) d[i]++;
	}
	// cout<<c[1]<<' '<<d[3]<<endl;
	// for(int i=0;i<=n;i++)
	// {
	// 	cout<<c[i]<<' '<<d[i]<<endl;
	// }
	// cout<<check(92)<<endl;
	// return 0;
	int l=1,r=n,mid,res=1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		{
			res=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	printf("%d\n",res);
	return 0;
}