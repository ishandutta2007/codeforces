#include <bits/stdc++.h>
using namespace std;
char v[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,k,mod,m;
    long long x1,y1,x2,y2;
    cin>>t;
    while(t--)
    {
        cin>>(v+1);
        n=strlen(v+1);
        if(n==1)
        {
            cout<<"0\n";
            continue;
        }
        if(n==2)
        {
            if(v[1]==v[2])
                cout<<"1\n";
            else
                cout<<"0\n";
            continue;
        }
        int cnt=0;
        for(i=2;i<=n;++i)
        {
            if(v[i]==v[i-1] || v[i]==v[i-2])
            {
                ++cnt;
                v[i]=3;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}