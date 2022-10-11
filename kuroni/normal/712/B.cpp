#include <bits/stdc++.h>
using namespace std;
map<char,int> cnt;
string s;
main()
{
    cin>>s;
    for (int i = 0; i < s.size(); i++) cnt[s[i]]++;
    cout<<((s.size()%2)?-1:(abs(cnt['U']-cnt['D'])+abs(cnt['L']-cnt['R']))/2);
}