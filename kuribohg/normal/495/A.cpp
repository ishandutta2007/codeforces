#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
const int a[]={2,7,2,3,3,4,2,5,1,2};
int n;
int main()
{
    scanf("%d",&n);
    printf("%d\n",a[n%10]*a[n/10]);
    return 0;
}