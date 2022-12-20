#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

void answer(int u)
{
    cout<<"! "<<u<<endl;
    cout.flush();
    exit(0);
}
int query(int u,int v,int w)
{
    cout<<"? "<<u<<" "<<v<<" "<<w<<endl;
    cout.flush();

    int ret;
    cin>>ret;
    return ret;
}

map<int,int> seen;

mt19937 rng(42);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int h;
    cin>>h;

    int n=(1<<h)-1;

    for(int i=1;i<=420;i++)
    {
        int u=rng()%n+1;
        int v=rng()%n+1;
        int w=rng()%n+1;

        if(u==v||v==w||w==u)
        {
            i--;
            continue;
        }

        seen[query(u,v,w)]++;
    }

    vector< pair<int,int> > there={};
    for(auto w:seen)
        there.push_back({w.second,w.first});

    sort(there.begin(),there.end());

    int SZ=there.size();

    int u=there[SZ-1].second;
    int v=there[SZ-2].second;

    for(int w=1;w<=n;w++)
        if(u!=w&&v!=w)
        {
            if(query(u,v,w)==w)
                answer(w);
        }

    return 0;
}