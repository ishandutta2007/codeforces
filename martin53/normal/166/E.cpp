#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long go_a[2],go_b[2],go_c[2],go_d[2];
int main()
{
int n;
cin>>n;
go_a[1]=1;
go_b[1]=1;
go_c[1]=1;
for(int i=2;i<=n;i++)
{
go_a[i&1]=(go_b[!(i&1)]+go_c[!(i&1)]+go_d[!(i&1)])%mod;
go_b[i&1]=(go_a[!(i&1)]+go_c[!(i&1)]+go_d[!(i&1)])%mod;
go_c[i&1]=(go_a[!(i&1)]+go_b[!(i&1)]+go_d[!(i&1)])%mod;
go_d[i&1]=(go_a[!(i&1)]+go_b[!(i&1)]+go_c[!(i&1)])%mod;
}
cout<<go_d[n&1]<<endl;
return 0;
}