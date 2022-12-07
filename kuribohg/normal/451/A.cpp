#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int main()
{
    cin>>n>>m;
    if(min(n,m)%2==0) puts("Malvika");
    else puts("Akshat");
    return 0;   
}