#include<bits/stdc++.h>
using namespace std;
int main()
{
long long a, b, c;
cin>>a>>b>>c;

a=(a+c-1)/c;
b=(b+c-1)/c;

cout<<a*b<<endl;
}