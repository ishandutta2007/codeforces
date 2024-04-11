#include<bits/stdc++.h>
using namespace std;
int n,k,l;
int main()
{
    scanf("%d%d",&n,&k);
    if(k%n==0)
    {
        cout<<k/n;
    }
    else
    {
        cout<<k/n+1;
    }
    return 0;
}