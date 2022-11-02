#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1000000
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define int long long
int n;
int bin[N];
ll ans;
int f[N];
int ck(int x)
{
	int d=x/49,D=d*49;
	for(int i=0;i<=300;i++)
	if(x>=i*49&&f[x-D+i*49]+d-i<=n)return 1;
	return 0;
}
main()
{
    n=read();
    if(n<=500)
    {
        for(int i=0;i<=n;i++)
        for(int j=0;i+j<=n;j++)
        for(int k=0;i+j+k<=n;k++)
        {
            int tmp=4*i+9*j+49*k;
            if(!bin[tmp])ans++,bin[tmp]=1;
        }
        printf("%d\n",ans);
    }
    else
    {
    	int L=4*9;
        int T=49*n-4900;
        int R=49*n;
    	ans=T-L+25;
        memset(f,0x3f,sizeof(f));
        f[0]=0;

        for(int i=1;i<=300;i++)
    	for(int j=1;j<=200000;j++)
        {
    		if(j>=4)f[j]=min(f[j-4]+1,f[j]);
    		if(j>=9)f[j]=min(f[j-9]+1,f[j]);
    	}

        for(int i=T+1;i<=R;i++)
        if(ck(i))ans++;

        cout<<ans<<endl;
    }
}
//4 10 20 35 56 83 116 155 198
// 6 10 15 21 27 33  39  43
//  4  5  6  6  6  6   4