#include<iostream>
#include<cstdio>
using namespace std;
int n;
int s1,s2;
int main()
{
    cin>>n;
    int x;
    for(int i=1;i<=n;i++) cin>>x,s1+=x;
    for(int i=1;i<=n;i++) cin>>x,s2+=x;
    if(s1>=s2) printf("Yes");
    else printf("No");
    return 0;
}