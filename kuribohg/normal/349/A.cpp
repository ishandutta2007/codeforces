#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a1,a2;
int a[100010];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        if(a[i]==25) a1++;
        else if(a[i]==50)
        {
            if(a1) a1--,a2++;
            else {puts("NO");return 0;}
        }
        else if(a[i]==100)
        {
            if(a1&&a2) a1--,a2--;
            else if(a1>=3) a1-=3;
            else {puts("NO");return 0;}
        }
    }
    puts("YES");
    return 0;
}