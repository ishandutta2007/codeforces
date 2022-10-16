#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int w,h,ans;cin>>w>>h;
    ans=1;
    for(long long int i=0;i<w+h;i++)
    {
        ans=ans*2;
        ans=ans%998244353;
    }
    cout<<ans<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num;
    for(long long int i=0;i<1;i++)
    {
       	solve();
    }   
}