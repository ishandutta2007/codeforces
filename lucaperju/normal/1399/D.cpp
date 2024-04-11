#include <bits/stdc++.h>
using namespace std;
int v[200005];
int rz[200005];
vector<int>zeroes,ones;
int main()
{
    long long t,n,m,i,j,x,y,k,l,r;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            char c;
            cin>>c;
            v[i]=c-'0';
        }
        int val=0;
        zeroes.clear();
        ones.clear();
        for(i=1;i<=n;++i)
        {
            if(v[i]==0)
            {
                if(ones.size())
                {
                    rz[i]=rz[ones[ones.size()-1]];
                    ones.pop_back();
                    zeroes.push_back(i);
                }
                else
                {
                    rz[i]=++val;
                    zeroes.push_back(i);
                }
            }
            else
            {
                if(zeroes.size())
                {
                    rz[i]=rz[zeroes[zeroes.size()-1]];
                    zeroes.pop_back();
                    ones.push_back(i);
                }
                else
                {
                    rz[i]=++val;
                    ones.push_back(i);
                }
            }
        }
        cout<<val<<'\n';
        for(i=1;i<=n;++i)
            cout<<rz[i]<<' ';
        cout<<'\n';
    }
    return 0;
}