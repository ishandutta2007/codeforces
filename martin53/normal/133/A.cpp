#include<bits/stdc++.h>
using namespace std;

int main()
{
string n;
cin>>n;
for(auto w:n)
if(w=='H' || w=='Q' || w=='9')
{cout<<"YES\n";return 0;} 
cout<<"NO"<<endl;
}