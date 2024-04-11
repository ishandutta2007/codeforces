#include <bits/stdc++.h>
#define ll long long//
#define ull unsigned long long
#define clr(f, n) memset(f, 0, sizeof(int) * (n))
#define cpy(f, g, n) memcpy(f, g, sizeof(int) * (n))
#define rev(f, n) reverse(f, f + n)
#define pir pair<int, int>
#define mkp make_pair
#define fst it->first
#define sec it->second
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
inline void print(int *f, int len)
{
    for (int i = 0; i < len; i++)
        printf("%lld ", f[i]);
    puts("");
}
bitset<100001>f[27],p;
char c[100001],s[101001];
signed main()
{
	scanf("%s",c+1);
	up(i,1,strlen(c+1))f[c[i]-'a'][i]=1;
	int q=read();
	while(q--)
	{
		int opt=read();
		if(opt==1)
		{
			int x=read();
			char ch[2];
			cin>>ch;
			f[c[x]-'a'][x]=0;
			f[ch[0]-'a'][x]=1;
			c[x]=ch[0];
		}
		else
		{
			int l,r;
			p.set();
			l=read(),r=read();
			scanf("%s",s+1);
			int len=strlen(s+1);
			for(int i=1;i<=len;++i)
			{
				p&=(f[s[i]-'a']>>(i-1));
			}
			int x1=(p>>l).count(),x2=(p>>(r-len+2)).count();
			int ans=max(0ll,x1-x2);
			printf("%lld\n",ans);
		}
	}
}