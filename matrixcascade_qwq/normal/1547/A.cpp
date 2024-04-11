#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int long long
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define down(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
using namespace std;
int n, m, k;
int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}
int a[101010];
signed main()
{
	int T=read();
	while(T--)
	{
		int x1,y1,x2,y2,x3,y3;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		int ans=abs(x2-x1)+abs(y2-y1);
		if(x1==x2&&x1==x3&&y3<max(y1,y2)&&y3>min(y1,y2))ans+=2;
		else if(y1==y2&&y1==y3&&x3<max(x1,x2)&&x3>min(x1,x2))ans+=2;
		cout<<ans<<endl;
	}
}