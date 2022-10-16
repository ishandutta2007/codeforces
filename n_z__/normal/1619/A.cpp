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
        if(s.size()%2==1){cout<<"NO"<<endl;continue;}
        int half=s.size()/2;
        for(int x=0;x<half;x++)
        if(s[x]!=s[half+x]){cout<<"NO"<<endl;goto nxt;}
        cout<<"YES"<<endl;
        nxt:;
    }
}