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
const int mod=1e9+7;
signed main()
{
	string s;
	cin>>n>>m>>s;
	int f=-1;
	k=s.size();
	up(i,1,m)
	{
		int x=read();
		if(f==-1||x-f>=k)n-=k;
		else
		{
			if(s[x-f]!=s[0])
			{
				cout<<0;
				return 0;
			}
			else
			{
				n-=x-f;
			}
		}
		f=x;
	}
	int w=1;
	up(i,1,n)w*=26,w%=mod;
	cout<<w;
}