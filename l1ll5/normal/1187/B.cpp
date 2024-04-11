#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 200020
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,ans;
int bin[30];
char s[N],t[N];
vector<int> a[30];
int main()
{
    n=read();
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
    a[s[i]-'a'].push_back(i);
    m=read();
    while(m--)
    {
        scanf("%s",t+1);
        int len=strlen(t+1);
        for(int i=0;i<=26;i++)
        bin[i]=0;
        for(int i=1;i<=len;i++)bin[t[i]-'a']++;
        int tmp=0;
        for(int i=0;i<26;i++)
        if(bin[i])
        {
            tmp=max(tmp,a[i][bin[i]-1]);
        }
        printf("%d\n",tmp);
    }
}