#include<bits/stdc++.h>
using namespace std;
int ask(string s)
{
    cout<<s<<endl;
    int a;
    cin>>a;
    if(!a)exit(0);
    return a;
}
main(){
    int n=ask("a")+1,x;
    string s(n,'a');
    if(n==301)x=n;else x=ask(s);
    if(x==n)ask(string(n-1,'b'));
    for(int q=0;q<n;q++)
    {
        s[q]='b';
        int y=ask(s);
        if(y<x)x=y;else s[q]='a';
    }
}
/*
bbbbbb
*/