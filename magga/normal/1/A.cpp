#include<bits/stdc++.h>
using namespace std;
void solve()
{
  long long int n,m,a,ans;cin>>n>>m>>a;
  ans = 0;
  ans = ((n+a-1)/a)*((m+a-1)/a);
  cout<<ans<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num=1;
    //cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }
}