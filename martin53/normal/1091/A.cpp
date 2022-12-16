#include<bits/stdc++.h>
using namespace std;
int main()
{
int y,b,r;
cin>>y>>b>>r;
int m=min(y,b-1);
m=min(m,r-2);

m=m*3+3;

cout<<m<<endl;
return 0;
}