#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,a[nmax];
set<int> outp;
int main()
{
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
for(int i=1;i<=n;i++)
{
if(a[i])outp.insert(a[i]);
}
cout<<outp.size()<<endl;
return 0;
}