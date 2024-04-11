#include <bits/stdc++.h>

using namespace std;
int v[200005];
int main()
{
    int i,j,n,m,k=0,cnt=0,s=0,mx=-9999999999LL,mn=9999999999LL,t;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        if(i==1 || v[i]>v[i-1] && !k)
            continue;
        else
        {
            if(v[i]<v[i-1] && k==0)
                k=1;
            else
                if(v[i]>v[i-1] && k==1)
                    k=2;
        }
    }
    if(k!=2)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}