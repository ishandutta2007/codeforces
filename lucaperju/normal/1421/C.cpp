#include <bits/stdc++.h>
using namespace std;
char v[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,s=0,k,n,m,mx=0;
    cin>>v;
    n=strlen(v);
    if(n==3)
    {
        cout<<"3\nL 2\nR 2\nR 5";
        return 0;
    }
    cout<<"4\n";
    cout<<"R "<<n-2<<'\n';
    n+=2;
    cout<<"L "<<n-1<<'\n';
    n+=(n-2);
    cout<<"R "<<2<<'\n';
    n+=(n-2);
    cout<<"R "<<n-1<<'\n';
    return 0;
}