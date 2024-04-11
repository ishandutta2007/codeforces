#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100000
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,ans;
char s[N];
int buc[N];
int main()
{
    cin>>s;
    n=strlen(s);    
    for(int i=0;i<n;i++)
    {
        if(!buc[s[i]])ans++;
        buc[s[i]]=1;
    }
    if(ans&1) puts("IGNORE HIM!");
    else puts("CHAT WITH HER!");
}