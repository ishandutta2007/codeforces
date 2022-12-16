#include<bits/stdc++.h>
using namespace std;

int main()
{
int n;
string inp;
cin>>n>>inp;

set<char> seen={};

for(auto w:inp) 
    if('a'<=w&&w<='z')seen.insert(w);
    else seen.insert(w-'A'+'a');

cout<<(seen.size()==26?"YES":"NO")<<endl;
}