#include<bits/stdc++.h>
using namespace std;

int main()
{
string outp;
cin>>outp;

set<char> in={};

for(auto w:outp) 
    in.insert(w);

if(in.size()%2==0)cout<<"CHAT WITH HER!" <<endl;
else cout<<"IGNORE HIM!" <<endl;
}