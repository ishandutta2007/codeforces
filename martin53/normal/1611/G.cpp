#include<bits/stdc++.h>
using namespace std;

vector< pair<int,int> > seen[2];

bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.second!=b.second)return a.second<b.second;

    return a.first>b.first;
}

int LIS(vector< pair<int,int> > now)
{
    //for(auto w:now)cout<<w.first<<" "<<w.second<<endl;

    vector<int> low={};

    for(auto w:now)
    {
        int cur=w.first;

        int pos=lower_bound(low.begin(),low.end(),cur)-low.begin();

        if(pos==low.size())low.push_back(cur);
        else low[pos]=cur;
    }

    //cout<<" -> "<<low.size()<<endl;

    return low.size();
}

int solve()
{
    int n,m;

    scanf("%i%i",&n,&m);

    seen[0]={};
    seen[1]={};

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            char c=getchar();
            while(c!='0'&&c!='1')c=getchar();

            if(c=='1')
            {
                seen[(i+j)%2].push_back({j-n+i,j+n-i});
            }
        }

    int outp=0;

    for(int i=0;i<2;i++)
    {
        sort(seen[i].begin(),seen[i].end(),cmp);

        outp+=LIS(seen[i]);
    }

    return outp;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%i\n",solve());
    }

    return 0;
}