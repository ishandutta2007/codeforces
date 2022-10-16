#include<bits/stdc++.h>
using namespace std;
int sum(long long int x)
{
     int s =0;
     while (x != 0) {
      s = s + x % 10;
      x = x / 10;
   }
   return s;
}
void solve()
{
    long long int n,ans,i;cin>>n;
    i=0;
    while(sum(n+i)%4!=0)
    {
        i++;
    }
    cout<<n+i<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}