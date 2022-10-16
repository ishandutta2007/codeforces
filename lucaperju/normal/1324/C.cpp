#include <bits/stdc++.h>

using namespace std;
char v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,ok=0,i,j,cnt=4,h,l,r,t;
    cin>>t;
    while(t--)
    {
        cin>>v;
        n=strlen(v);
        int mx=0;
        int cnt=0;
        for(i=0;i<n;++i)
        {
            if(v[i]=='L')
                ++cnt;
            else
                cnt=0;
            mx=max(mx,cnt);
        }
        cout<<mx+1<<'\n';
    }
    return 0;
}