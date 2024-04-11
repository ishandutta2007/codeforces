#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,j,i,k;
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        for(i=1;i<=a;++i)
        {
            char c;
            c='a';
            c+=i%3;
            cout<<c;
        }
        cout<<'\n';
    }
    return 0;
}