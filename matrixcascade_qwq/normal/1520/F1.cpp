//MatrixCascade

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define clr(f, n) memset(f, 0, sizeof(int) * (n))
#define cpy(f, g, n) memcpy(f, g, sizeof(int) * (n))
#define rev(f, n) reverse(f, f + n)
#define pir pair<int, int>
#define mkp make_pair
#define fst it->first
#define sec it->second
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
int T;
int main()
{
	int t;
	n=read(),t=read();
	int lst,la;
	up(i,1,t)
	{
		k=read();
		int l=1,r=n;
		if(i!=1)
		{
			if(k<lst)
			{
				r=la-1;
			}
			else
			{
				k-=(lst-1);
				l=la+1;
			}
		}
		while(l<r)
		{
			int mid=(l+r)>>1;
			cout<<"? "<<l<<" "<<mid<<endl;
			int nw=(mid-l+1)-read();
			if(nw>=k)r=mid;
			else
			{
				l=mid+1;
				k-=nw;
			}
		}
		cout<<"! "<<l<<endl;
		lst=k;
		la=l;
	}
}