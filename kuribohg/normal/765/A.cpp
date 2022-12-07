#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int main()
{
    scanf("%d",&n);
    if(n&1) puts("contest");
    else puts("home");
    return 0;
}