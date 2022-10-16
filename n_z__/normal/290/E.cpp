#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    string s;
    cin>>s;
    auto a=s.find('Q');
    if(a==string::npos)return puts("Yes"),0;
    a/=2;
    int cnt=count(s.begin(),s.end(),'Q'),sqc=sqrt(cnt),w=(s.size()-cnt)/(sqc+1);
    string b=s.substr(a,w+sqc),ans;
    for(auto ww:b)
    if(ww=='H')ans+='H';
    else ans+=b;
    if(s==ans)puts("Yes");
    else puts("No");
}