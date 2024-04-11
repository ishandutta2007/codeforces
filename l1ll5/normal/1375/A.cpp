#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <assert.h>
#define N 200005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int t;
int n;
int a[N];
int main()
{
	t=read();
	while(t--){
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();

        for(int i=0;i<=n;i++)
        {
            for(int j=1;j<=i;j++)  a[j]=-a[j];
            int bg=0,sm=0;
            for(int i=2;i<=n;i++)
    		{
    			int x=a[i]-a[i-1];
    			if(x>=0) sm++;
    			if(x<=0)bg++;
    		}
            if(sm>=(n-1)/2)
            {
                if(bg>=(n-1)/2)
                {
                //    cerr<<"ok"<<endl;
                    break ;
                }
            }
            for(int j=1;j<=i;j++)  a[j]=-a[j];
        }


		for(int i=1;i<=n;i++)
		{
			cout<<a[i]<<' ';
		}
		cout<<endl;
	}
}