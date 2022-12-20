#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42,MX=1e6+42;

int n,m;

pair<int,int> small[nmax],big[nmax];

vector< pair<int,int> > help;

int low[MX];

bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.first!=b.first)return a.first>b.first;
    return a.second>b.second;
}
int main()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=n;i++)scanf("%i%i",&small[i].first,&small[i].second);

    for(int i=1;i<=m;i++)scanf("%i%i",&big[i].first,&big[i].second);

    for(int i=1;i<=n;i++)
    {
        help={};
        for(int j=1;j<=m;j++)
            if(small[i].first<=big[j].first&&small[i].second<=big[j].second)
            {
                help.push_back({big[j].first-small[i].first,big[j].second-small[i].second});
            }

        //sort(help.begin(),help.end(),cmp);

        int mx=-1;

        for(auto k:help)
            {
                low[k.first]=max(low[k.first],k.second+1);
            }
    }

    for(int i=MX-2;i>=0;i--)
        low[i]=max(low[i],low[i+1]);

    //for(int j=0;j<10;j++)cout<<low[j]<<" ";cout<<endl;

    int outp=1e8;

    for(int i=0;i<MX;i++)
        outp=min(outp,low[i]+i);

    printf("%i\n",outp);
    return 0;
}