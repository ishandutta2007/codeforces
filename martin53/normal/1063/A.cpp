#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
string inp;
int n;
int seen[26];
int main()
{
cin>>n;
cin>>inp;
for(auto k:inp)
    seen[k-'a']++;
for(int i=0;i<26;i++)
    for(int j=0;j<seen[i];j++)
    cout<<char(i+'a');
cout<<endl;
return 0;
}