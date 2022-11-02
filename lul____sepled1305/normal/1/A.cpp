#include<bits/stdc++.h>
using namespace std;
int n,m,a;
long long ans = 1LL;
 
int main()
{
    cin>>n>>m>>a;
    ans*=((n-1)/a+1);
    ans*=((m-1)/a+1);
    cout<<ans;
}