#include<iostream>
using namespace std;
int main()
{
string a , b ,c;
cin>>a>>b>>c;
for(int i=0;i<3;i++)
{
   if(a[i]!=c[2-i])
{cout<<"No"; return 0;}
}
if(b[0]!=b[2])
{cout << "No"; return 0;}
cout<<"Yes";
}