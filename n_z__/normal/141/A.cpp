#include<bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<char,int>mp;
main()
{
    string a,b,c;
    cin>>a>>b>>c;
    for(auto q:a)
    mp[q]++;
    for(auto q:b)
    mp[q]++;
    for(auto q:c)
    mp[q]--;
    for(auto q:mp)
    if(q.second)return puts("NO"),0;
    puts("YES");
}