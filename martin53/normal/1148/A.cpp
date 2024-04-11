#include<bits/stdc++.h>
using namespace std;
int main()
{
long long a,b,c;
cin>>a>>b>>c;

long long sol_1=2*c+2*min(a,b);
if(b<a)sol_1++;

long long sol_2=1+2*c+2*min(a,b-1);
if(b-1<a)sol_2++;

cout<<max(sol_1,sol_2)<<endl;
return 0;
}