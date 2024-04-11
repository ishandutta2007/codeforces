#include <bits/stdc++.h>

using namespace std;
char v[300005];
int p[300005],ip[300005];
int main()
{
    ios_base::sync_with_stdio(0);
    int n,q,i,j;
    cin>>q;
    while(q--)
    {
        cin>>v;
        n=strlen(v);
        int kp=0,ki=0;
        for(int i=0;i<n;++i)
        {
            if((v[i]-'0')&1)
                p[++kp]=v[i]-'0';
            else
                ip[++ki]=v[i]-'0';
        }
        i=j=1;
        while(i<=kp || j<=ki)
        {
            if(p[i]<ip[j] && i<=kp || i<=kp && j>ki)
                cout<<p[i++];
            else if (p[i]>ip[j] && j<=ki || j<=ki && i>kp)
                cout<<ip[j++];
        }
        cout<<'\n';
    }
    return 0;
}