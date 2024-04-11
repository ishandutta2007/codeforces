#include<bits/stdc++.h>
using namespace std;

int main()
{
int cnt=0;
string inp;
cin>>inp;
for(auto k:inp) 
    if(k=='4' || k=='7')cnt++;
cout<<(cnt==4||cnt==7?"YES":"NO")<<endl;
}