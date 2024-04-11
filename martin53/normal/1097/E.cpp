#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n,inp[nmax];

int f(int sz)
{
    int groups=0;

    while(groups*(groups+1)/2<=sz)groups++;

    groups--;

    return groups;
}

vector< vector<int> > outp;

pair<int/*value*/,int/*id*/> lowest[nmax];

bool been[nmax];

int parent[nmax];

vector<int> find_lis()
{
    for(int i=0;i<=n+5;i++)
        lowest[i]={1e9,0};

    for(int i=1;i<=n;i++)
        if(been[i]==0)
        {
            int pos=lower_bound(lowest+1,lowest+n+1,make_pair(inp[i],i))-lowest;

            parent[i]=lowest[pos-1].second;

            lowest[pos]={inp[i],i};
        }

    vector<int> ret={};

    int i=1;

    while(lowest[i].second)i++;

    i--;
    /*
    for(int j=1;j<=i;j++)cout<<j<<" -> "<<lowest[j].first<<" "<<lowest[j].second<<endl;
    for(int j=1;j<=n;j++)cout<<parent[j]<<" ";cout<<endl;
    */
    i=lowest[i].second;

    while(i)
    {
        ret.push_back(i);
        i=parent[i];
    }

    reverse(ret.begin(),ret.end());

    return ret;
}

void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    outp={};

    for(int i=1;i<=n;i++)been[i]=0;

    int should=f(n),remain=n;

    for(int i=1;i<=should;i++)
    {
        vector<int> cur=find_lis();

        if(cur.size()==0)break;

        //cout<<"cur: ";for(auto w:cur)cout<<w<<" ";cout<<endl;

        if(f(remain-cur.size())<=should-i)
        {
            //pick cur
            for(auto &w:cur)
            {
                been[w]=1;

                w=inp[w];
            }

            outp.push_back(cur);

            remain=remain-cur.size();
        }
        else
        {
            for(int j=0;j<=n+5;j++)
                lowest[j]={1e9,0};

            int sub=outp.size();

            for(int j=1;j<=n;j++)
                if(been[j]==0)
                {
                    int pos=lower_bound(lowest,lowest+n+1,make_pair(inp[j],j))-lowest;

                    if(outp.size()-sub<=pos)outp.push_back({});

                    outp[sub+pos].push_back(inp[j]);

                    lowest[pos]={inp[j],j};
                }

            break;
        }
    }

    printf("%i\n",outp.size());
    for(auto cur:outp)
    {
        printf("%i",cur.size());
        for(auto w:cur)printf(" %i",w);
        printf("\n");
    }
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        solve();
    }
    return 0;
}