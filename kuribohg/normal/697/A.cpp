#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,s,x;
int main()
{
    cin>>t>>s>>x;
    if(((x-t)%s==0||(x-t)%s==1)&&x!=t+1&&x>=t) puts("YES");
    else puts("NO");
    return 0;
}