#include<bits/stdc++.h>
using namespace std;
int n,x,o;
string s;
int main()
{
    cin>>n>>s;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='z') x++;
        else if (s[i]=='n') o++;
    }
    for (int i=1;i<=o;i++) cout<<1<<" ";
    for (int i=1;i<=x;i++) cout<<0<<" ";
    cout<<endl;
    return 0;
}