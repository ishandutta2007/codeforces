#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=2e5+10;
int n,a[M][6];

signed main()
{
	WT
	{
		n=read();int f=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=5;j++)a[i][j]=read();
		for (int i=1;i<=5;i++)
			for (int j=i+1;j<=5;j++)
			{
				int cnt1=0,cnt2=0,cnt3=0;
				for (int w=1;w<=n;w++)
					if (a[w][i]&&a[w][j])cnt1++;
					else if (a[w][i])cnt2++;
					else if (a[w][j])cnt3++;
				if (cnt1>=abs(cnt2-cnt3)&&cnt1+cnt2+cnt3==n)f=1;
			}
		
		if (f)YES
		else NO
	}
	return 0;
}