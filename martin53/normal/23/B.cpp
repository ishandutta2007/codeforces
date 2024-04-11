#include<bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin>>t;
int n;
for(int i=1;i<=t;i++)
{
    cin>>n;
    cout<<max(n-2,0)<<endl;
}
return 0;
}