#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
char a[10000001];
int mid,len;
long long l,r;
int main()
{
    scanf("%s",a);
    len=strlen(a);
    for(int i=0;i<len;i++)
        if(a[i]=='^')
        {
            mid=i;
            break;
        }
    for(int i=0;i<mid;i++)
        if(a[i]!='=') l+=((mid-i)*(a[i]-'0'));
    for(int i=mid+1;i<len;i++)
        if(a[i]!='=') r+=((i-mid)*(a[i]-'0'));
    if(l==r) puts("balance");
    else if(l>r) puts("left");
    else puts("right");
    return 0;
}