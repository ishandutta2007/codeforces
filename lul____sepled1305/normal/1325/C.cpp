#include<bits/stdc++.h>
using namespace std;
long long i,j,k,a,b,n,t,crit,ll=-1e9,lll=-1e9,llll=-1e9;
long long print,normprint;
vector<vector<pair<long long, long long>>> tree;
bool line=true;

int main()
{
    cin>>n;
    for(i=0;i<n;i++)
    {
        vector<pair<long long, long long>> v;
        tree.push_back(v);
    }
    for(i=0;i<n-1;i++)
    {
        cin>>a>>b;
        pair<long long, long long> u;
        u.first=i;
        u.second=b-1;
        tree[a-1].push_back(u);
        u.second=a-1;
        tree[b-1].push_back(u);
    }
    for(i=0;i<n;i++)
    {
        if(tree[i].size()>2)
        {
            line = false;
            crit=i;
            break;
        }
    }
    if(line)
    {
        for(i=0;i<n-1;i++)
        {
            cout<<i<<"\n";
        }
    } else
    {
        ll=tree[i][0].first;
        lll=tree[i][1].first;
        llll=tree[i][2].first;
        while(print<n-1)
        {
            if(print==ll) cout<<0<<"\n";
            else if(print==lll) cout<<1<<"\n";
            else if(print==llll) cout<<2<<"\n";
            else
            {
                cout<<normprint+3<<"\n";
                normprint++;
                //cout<<"BUG";
            }
            print++;
        }
    }
    //cout<<ll<<lll<<llll;
    return 0;
}