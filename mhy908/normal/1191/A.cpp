#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
int main()
{
    scanf("%d", &n);
    if(n%4==1)printf("0 A");
    if(n%4==2)printf("1 B");
    if(n%4==3)printf("2 A");
    if(n%4==0)printf("1 A");
}