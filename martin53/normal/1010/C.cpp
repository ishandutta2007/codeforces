#include <bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,a[nmax],k;

int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
cin>>n>>k;
int g=k;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
    g=__gcd(g,a[i]%k);
}
cout<<k/g<<endl;
for(int i=0;i<k;i++)
    if(i%g==0)cout<<i<<" ";
cout<<endl;
return 0;
}