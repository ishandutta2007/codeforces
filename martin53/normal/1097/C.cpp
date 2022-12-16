#include<bits/stdc++.h>
using namespace std;
map<int,int> seen;
int n;
stack<char> ss;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n;
string s;
int ans=0;
for(int i=1;i<=n;i++)
{
    cin>>s;
    for(auto k:s)
        if(k=='(')ss.push(k);
        else
        {
            if(ss.size()&&ss.top()=='(')ss.pop();
            else ss.push(k);
        }
    int open=0,close=0;
    while(ss.size())
    {
        if(ss.top()=='(')open++;
        else close++;
        ss.pop();
    }
    //cout<<open<<" "<<close<<endl;
    if(open&&close)continue;
    if(seen[open-close])
    {
        ans++;
        seen[open-close]--;
    }
    else seen[-(open-close)]++;
}
cout<<ans<<endl;
return 0;
}