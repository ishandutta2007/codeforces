#include<bits/stdc++.h>
using namespace std;
int seen[26];
int n;
string s;
int main()
{
cin>>n;
cin>>s;
if(n==1)
{
    cout<<"Yes"<<endl;
    return 0;
}
for(auto k:s)
    seen[k-'a']++;
for(int i=0;i<26;i++)
    if(seen[i]>1)
    {
    cout<<"Yes"<<endl;
    return 0;
    }
cout<<"No"<<endl;
return 0;
}