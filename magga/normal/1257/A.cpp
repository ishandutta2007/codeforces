#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n,x,a,b;cin>>n>>x>>a>>b;
    long long int ans = min(abs(b-a)+x,n-1);
    cout<<ans<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num;
    cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }   
}