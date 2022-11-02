/**Nephren is the best girl**/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int MOD = 1e9+7;
const int chtholly = 0;
int T;

int find_set(int v, int par[])
{
    if(v == par[v])
        return v;
    return par[v] = find_set(par[v],par);
}

void union_sets(int a, int b, int par[])
{
    a = find_set(a,par);
    b = find_set(b,par);
    if (a != b)
        par[b] = a;
}

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/

    cin>>T;
    while(T--)
    {
        int n,i,j,counti = 0;
        cin>>n;
        int par[20];
        string s[2];
        cin>>s[0]>>s[1];
        map<int,int> mp[20];
        map<pii,int> mp_fi;
        bool pass = true;
        for(i=0;i<20;i++)
            par[i] = i;
        for(i=0;i<n;i++)
        {
            int cur = s[0].at(i)-'a';
            int tar = s[1].at(i)-'a';
            if(!mp[cur].count(tar))
                mp[cur].insert({tar,0});
        }
        for(i=19;i>=0;i--)
        {
            for(j=19;j>=0;j--)
            {
                if(mp[i].count(j) && j<i)
                {
                    pass = false;
                    break;
                }
                if(mp[i].count(j) && j>i)
                {
                    if(find_set(i,par)!=find_set(j,par))
                    {
                        union_sets(i,j,par);
                    }
                }
            }
        }
        for(i=0;i<20;i++)
            if(par[i]!=i)
                counti++;
        if(pass)
            cout<<counti<<"\n";
        else
            cout<<"-1\n";
    }
    return 0;
}

/**
    I lied. Ithea is better than Nephren.
    JK
**/