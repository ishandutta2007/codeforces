#include <bits/stdc++.h>
using namespace std;
char v[1003];
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,k,mod,m;
    long long x1,y1,x2,y2;
    cin>>t;
    while(t--)
    {
        cin>>v;
        n=strlen(v);
        if(n%2 || v[0]==')' || v[n-1]=='(')
            cout<<"no\n";
        else
            cout<<"Yes\n";
    }
    return 0;
}