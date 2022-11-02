#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
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

        // pd 0
        bool ans0=1;
        for(int i=1;i<=n;i++)
        if(a[i]!=i) ans0=0;

        if(ans0){
            puts("0");
            continue ;
        }

        int i=1;
        while(a[i]==i && i<=n) i++;
        while(a[i]!=i && i<=n) i++;
        while(a[i]==i && i<=n) i++;

        if(i!=n+1) {
            puts("2");
        }
        else puts("1");

    }
}