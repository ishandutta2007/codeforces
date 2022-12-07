#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
bool is_ok(int n)
{
    int a[5];
    a[1]=n%10,n/=10;
    a[2]=n%10,n/=10;
    a[3]=n%10,n/=10;
    a[4]=n;
    sort(a+1,a+5);
    if(a[1]!=a[2]&&a[2]!=a[3]&&a[3]!=a[4]) return true;
    return false;
}
int n;
int main()
{
    scanf("%d",&n);
    for(int i=n+1;i<=9999;i++)
        if(is_ok(i))
        {
            printf("%d\n",i);
            break;
        }
    return 0;
}