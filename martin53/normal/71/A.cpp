#include<bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin>>t;

while(t) 
{
t--;
string inp;
cin>>inp;
if(inp.size()>10)cout<<inp[0]<<inp.size()-2<<inp.back()<<endl;
else cout<<inp<<endl;
} 

}