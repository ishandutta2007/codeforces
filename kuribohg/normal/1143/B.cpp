#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
int N,n,a;
char s[210];
void dfs(int x,int ans,LL cur)
{
    if(ans==0) return;
    if(x==n)
    {
        if(cur<=N)
            if(a<ans) a=ans;
        return;
    }
    int d=s[x]-'0';
    dfs(x+1,ans*d,cur*10+d);
    dfs(x+1,ans*9,cur*10+9);
    if(d!=0) dfs(x+1,ans*(d-1),cur*10+d-1);
    if(x==0&&d==1) dfs(x+1,ans,0);
}
int main()
{
    scanf("%s",s);
    N=atoi(s);
    n=strlen(s);
    dfs(0,1,0);
    printf("%d\n",a);
    return 0;
}