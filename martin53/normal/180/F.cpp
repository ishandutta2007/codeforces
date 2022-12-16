#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,a[nmax],b[nmax],inv_a[nmax],inv_b[nmax];
int p[nmax];
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
    inv_a[a[i]]=i;
}
for(int i=1;i<=n;i++)
{
    cin>>b[i];
    inv_b[b[i]]=i;
}
for(int i=1;i<=n;i++)
    p[inv_b[i]]=inv_a[i];
for(int i=1;i<=n;i++)cout<<p[i]<<" ";cout<<endl;
return 0;
}