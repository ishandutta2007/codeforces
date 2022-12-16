#include<bits/stdc++.h>
using namespace std;

int main()
{
int n, h;
cin>>n>>h;
int outp=n;
for(int i=1;i<=n;i++)
{
int cur;
cin>>cur;
if(cur>h)outp++;
}
cout<<outp<<endl;
}