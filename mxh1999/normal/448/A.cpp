#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a,b,c,d,e,f;
int main()
{
    scanf("%d%d%d",&a,&b,&c);
    scanf("%d%d%d",&d,&e,&f);
    int hzw=a+b+c;
    int hzw1=d+e+f;
    int k=((hzw+4)/5)+((hzw1+9)/10);
    scanf("%d",&n);
    if  (n>=k) printf("YES\n");
    else printf("NO\n");
    return 0;
}