#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,inp[nmax];

vector< pair<int,int> > given;

int need[nmax];

bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.first!=b.first)return a.first<b.first;
    return a.second>b.second;
}

int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)
        if(1<=inp[i]&&inp[i]<=i)
        {
            pair<int,int> cur={inp[i],i-inp[i]};
            given.push_back(cur);
        }

    sort(given.begin(),given.end(),cmp);

    //for(auto w:given)cout<<w.first<<" "<<w.second<<endl;

    for(int i=1;i<=n;i++)need[i]=1e9+i;

    int outp=0;

    for(auto w:given)
    {
        int pos=upper_bound(need+1,need+n+1,w.second)-need;

        need[pos]=w.second;

        outp=max(outp,pos);
    }

    printf("%i\n",outp);

    return 0;
}