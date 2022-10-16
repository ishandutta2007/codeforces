#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        vector<pair<int,int>>v;
        int a=s[0],b=s[s.size()-1];
        for(int x=1;x<s.size()-1;x++)
        if((s[x]>=a&&s[x]<=b)||(s[x]<=a&&s[x]>=b))v.push_back({s[x],x});
        if(a<b)sort(v.begin(),v.end());
        else sort(v.begin(),v.end(),greater<>());
        cout<<abs(b-a)<<' '<<v.size()+2<<endl;
        cout<<1<<' ';
        for(auto q:v)
        cout<<q.second+1<<' ';
        cout<<s.size()<<endl;
    }
}