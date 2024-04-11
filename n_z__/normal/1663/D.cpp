#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;int q;
    cin>>s>>q;
    if(s=="ABC"&&q<2000||s=="ARC"&&q<2800||s=="AGC"&&q>=1200)
    cout<<"YES"<<endl;else cout<<"NO"<<endl;
}