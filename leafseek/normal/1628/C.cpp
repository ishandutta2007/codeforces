#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=3000+5;
int a[MaxN][MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T;
	cin>>T;
	int n;
	while(T--)
	{
		cin>>n;
		int A=0;
		rep(i,1,n)
			rep(j,1,n)
			{
				cin>>a[i][j];
				int I=(i+j)&3;
				int J=(i-j)&3;
				if(true)
				{
					if((i+j)<=n)
					{
						if(I==0&&J==2)
							A^=a[i][j];
					}
					else
					{
						if(I==0&&J==0)
							A^=a[i][j];
					}
				}
				if(true)
				{
					if(j<=i)
					{
						if(I==((n+3)&3)&&J==((n+1)&3))
							A^=a[i][j];
					}
					else
					{
						if(I==((n+1)&3)&&J==((n+1)&3))
							A^=a[i][j];
					}
				}
			}
		cout<<A<<'\n';
	}
	return 0;
}