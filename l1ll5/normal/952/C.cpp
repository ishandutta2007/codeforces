#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<string>
#include<bitset>
#include<queue>
#include<map>
#include<set>
using namespace std;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=10*x+ch-'0';ch=getchar();}
	return x*f;
}
void print(int x)
{if(x<0)putchar('-'),x=-x;if(x>=10)print(x/10);putchar(x%10+'0');}

const int N=15;

int n;
int a[N],b[N];

inline bool check()
{
    for(int i=1;i<n;++i)
        if(a[i]-a[i+1]>=2)
		{
			int tmp=(a[i]-a[i+1])>>1;
			a[i]-=tmp;a[i+1]+=tmp;
		}
}

int main()
{
    n=read();
    register int i;
    for(i=1;i<=n;++i) a[i]=b[i]=read();
	sort(b+1,b+1+n);
    for(int T=1;T<n;++T)
    {
//        if(!check())
//        {cout<<"NO"<<endl;return 0;}
		check();
        int now(0);
        for(i=1;i<=n-T+1;++i)
            if(a[i]>a[now])
                now=i;
        int tmp=a[now];
        for(i=now;i<=n-T+1;++i)
            a[i]=a[i+1];
        a[n-T+1]=tmp;//for(i=1;i<=n;++i) cout<<a[i]<<" ";cout<<endl;
		check();
//        if(!check())
//        {cout<<"NO"<<endl;return 0;}
    }
//    bool flag=0;
//    for(i=2;i<=n;++i) if((a[i]-a[i-1])>=2) flag=1;
	bool flag=0;
	for(i=1;i<=n;++i)
		if(a[i]!=b[i])
			flag=1;
    flag ? cout<<"NO"<<endl : cout<<"YES"<<endl;
    return 0;
}