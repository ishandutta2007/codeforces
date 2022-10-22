#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=500+5;
char str[MaxN][MaxN];
int cum[MaxN][MaxN];
inline int Rect(int sx,int sy,int tx,int ty)
{
	return (cum[tx][ty]-cum[sx-1][ty]-cum[tx][sy-1]+cum[sx-1][sy-1]);
}
int a[MaxN],b[MaxN],s[MaxN],A[MaxN],B[MaxN],bb[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T;
	cin>>T;
	int n,m;
	while(T--)
	{
		cin>>n>>m;
		rep(i,1,n)
		{
			cin>>(str[i]+1);
			rep(j,1,m)
			{
				cum[i][j]=(cum[i-1][j]+cum[i][j-1]-cum[i-1][j-1]);
				if(str[i][j]=='1') ++cum[i][j];
			}
		}
		int Answer=((1<<29)-1);
		rep(x1,1,n)
			rep(x2,x1+4,n)
			{
				bb[0]=1-(1<<29);
				rep(i,1,m)
				{
					a[i]=(str[x1][i]=='0')+(str[x2][i]=='0')+Rect(x1+1,i,x2-1,i);
					b[i]=((x2-x1-1)-Rect(x1+1,i,x2-1,i));
					s[i]=(s[i-1]+a[i]);
					A[i]=(s[i-1]+b[i]);
					B[i]=(s[i-1]+(a[i]-b[i]));
					bb[i]=max(bb[i-1],B[i]);
				}
				rep(i,4,m)
					Answer=min(Answer,A[i]-bb[i-3]);
			}
		cout<<Answer<<endl;
	}
	return 0;
}