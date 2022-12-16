#include<bits/stdc++.h>
using namespace std;
int main()
{
int b,k;
int n=0;
cin>>b>>k;
int x;
for(int i=1;i<=k;i++)
{
    cin>>x;
    n=(n*b+x)%2;
}
if(n==1)cout<<"odd"<<endl;
else cout<<"even"<<endl;
return 0;
}