#include <bits/stdc++.h>
using namespace std;
char v[205];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long i,j,n,t,m,k,n1;
    cin>>t;
    while(t--)
    {
        cin>>v;
        n=strlen(v);
        long long cnt=0;
        for(i=0;i<n;++i)
        {
            cnt+=v[i]-'0';
        }
        cnt=min(cnt,n-cnt);
        if(cnt%2==0)
            cout<<"NET\n";
        else
            cout<<"Da\n";
    }
    return 0;
}