#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <vector>
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
char s[N];
int t[N];
int n;
int ans;
vector<int> v[N];
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='(') t[i]=0;
        else t[i]=1;
    }
    while(1)
    {
        int i=1,j=n;
        bool ck=0;

        while(1)
        {
            if(t[i]!=0) i++;
            if(t[j]!=1) j--;
            if(i>j) break ;

            if(t[i]==0 && t[j]==1)
            {
                ck=1;
                v[ans].push_back(i);
                v[ans].push_back(j);
                t[i]=t[j]=-1;
            }
        }
        sort(v[ans].begin(),v[ans].end());
        if(!ck) break ;
        ans++;
    }
    printf("%d\n",ans);
    for(int i=0;i<ans;i++)
    {
        printf("%d\n",v[i].size());
        for(int j=0;j<v[i].size();j++)
        printf("%d ",v[i][j]);
        puts("");
    }
}