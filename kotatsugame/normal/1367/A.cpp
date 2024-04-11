#include<iostream>
using namespace std;
int T;
main()
{
    cin>>T;
    for(;T--;)
    {
        string s;cin>>s;
        cout<<s[0];
        for(int i=1;i<s.size();i+=2)cout<<s[i];
        cout<<endl;
    }
}