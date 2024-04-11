#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ans=1;
    while(ans<=n)
    if(ans==n||ans==n-1)return puts("1"),0;
    else if(ans&1)ans*=2,ans+=2;else ans*=2,ans+=1;
    puts("0");
}