#include <bits/stdc++.h>
using namespace std;
int v[103];
vector<int>vc;
bool cmp(int a, int b)
{
    return a>b;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,k;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vc.clear();
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
        }
        for(i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            if(a==0)
            {
                vc.push_back(v[i]);
                v[i]=1000006;
            }
        }
        sort(vc.begin(),vc.end(),cmp);
        j=0;
        for(i=1;i<=n;++i)
        {
            if(v[i]==1000006)
                v[i]=vc[j++];
        }
        for(i=1;i<=n;++i)
            cout<<v[i]<<' ';
        cout<<'\n';
    }
    return 0;
}