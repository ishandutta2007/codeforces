#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
bool is_prime(int n)
{
    if(n==1) return false;
    for(int i=2;i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}
int main()
{
    cin>>n;
    if(n==2) puts("1");
    else if(is_prime(n)) puts("1");
    else if(n%2==1&&is_prime(n-2)) puts("2");
    else if(n%2==0) puts("2");
    else puts("3");
    return 0;
}