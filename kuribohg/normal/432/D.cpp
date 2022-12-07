#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=100010;
int n,next[MAXN],l[MAXN],c[MAXN],tot;
char a[MAXN];
void initKMP()
{
    int j=0;
    for(int i=2;i<=n;i++)
    {
        while(j&&a[i]!=a[j+1]) j=next[j];
        if(a[i]==a[j+1]) j++;
        next[i]=j;
    }
}
int main()
{
    scanf("%s",a+1);
    n=strlen(a+1);
    initKMP();
    for(int i=0;i<=n;i++) c[i]=1;
    for(int i=n;i>=1;i--) c[next[i]]+=c[i];
    while(n) l[++tot]=n,n=next[n];
    printf("%d\n",tot);
    for(int i=tot;i>=1;i--)
        printf("%d %d\n",l[i],c[l[i]]);
    return 0;
}