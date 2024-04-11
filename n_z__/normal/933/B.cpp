#include<bits/stdc++.h>
using namespace std;
#define int long long
int s[500001],ans;
main()
{
    int p,k;
    cin>>p>>k;
    for(;p;)
    ans++,s[ans]=(p%k+k)%k,p=(s[ans]-p)/k;
    cout<<ans<<endl;
    for(int x=1;x<=ans;x++)
    cout<<s[x]<<' ';
}