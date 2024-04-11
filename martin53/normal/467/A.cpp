#include<bits/stdc++.h>
using namespace std;

int main()
{
int n;
cin>>n;
int outp=0;
for(int i=1;i<=n;i++)
{
int p, q;
cin>>p>>q;
if(p+2<=q)outp++;
}
cout<<outp<<endl;
}