#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int l,r,n;
char str[100010];
int main()
{
    scanf("%s",str);
    n=strlen(str);
    bool flag=true;
    for(int i=0;i<n;i++)
        if(str[i]!='a') flag=false;
    if(flag)
    {
        for(int i=0;i<n-1;i++)
            putchar(str[i]);
        putchar('z');
        puts("");
        return 0;
    }
    l=0;
    while(str[l]=='a') l++;
    r=l;
    while(r!=n&&str[r]!='a') r++;
    for(int i=l;i<r;i++) str[i]--;
    puts(str);
    return 0;
}