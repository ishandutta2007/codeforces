#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int n;
char s[400];
int a[200],b[200];

int main()
{
    cin>>n;
    scanf("%s",s+1);
    for (int i=1;i<=n;++i)
        a[i]=s[i]-'0';
    for (int i=1;i<=n;++i)
        b[i]=s[i+n]-'0';
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    int flag=1;
    for (int i=1;i<=n;++i)
        if (a[i]<=b[i])
        {
            flag=0;
            break;
        }
    if (flag)
    {
        puts("YES");
        return 0;
    }
    flag=1;
    for (int i=1;i<=n;++i)
        if (a[i]>=b[i])
        {
            flag=0;
            break;
        }
    if (flag)
    {
        puts("YES");
        return 0;
    }
    puts("NO");
    return 0;
}