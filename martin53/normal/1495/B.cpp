#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

int low_left[nmax],low_right[nmax];

vector< pair<int,int> > hill;

bool cmp(pair<int,int> a,pair<int,int> b)
{
    return a.second-a.first>b.second-b.first;
}

int eval_without(int i)
{
    for(auto w:hill)
        if(w.first!=i&&w.second!=i)
        {
            //cout<<w.first<<" "<<w.second<<endl;

            return w.second-w.first+1;
        }

    return -1;
}

int take(int sz)
{
    if(sz%2==0)return sz-1;
    return sz;
}
void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    low_left[1]=0;
    for(int i=2;i<=n;i++)
        if(inp[i]>inp[i-1])low_left[i]=low_left[i-1]+1;
        else low_left[i]=0;

    low_right[n]=0;
    for(int i=n-1;i>=1;i--)
        if(inp[i]>inp[i+1])low_right[i]=low_right[i+1]+1;
        else low_right[i]=0;

    hill={};

    inp[0]=-1e9;
    inp[n+1]=-1e9;

    for(int i=1;i<=n;i++)
        if(inp[i-1]<inp[i]&&inp[i]>inp[i+1])
    {
        hill.push_back({i-low_left[i],i});
        hill.push_back({i,i+low_right[i]});
    }

    sort(hill.begin(),hill.end(),cmp);

    int outp=0;

    for(int x=2;x<n;x++)
        if(inp[x-1]<inp[x]&&inp[x]>inp[x+1])
    {
        int l=low_left[x],r=low_right[x];

        int other=eval_without(x);

        //cout<<x<<" "<<l<<" "<<r<<" "<<other<<endl;

        if(max(l,r)<other)continue;

        if(l<=take(r))continue;

        if(r<=take(l))continue;

        outp++;
    }

    printf("%i\n",outp);
}

int main()
{
    int t;
    //scanf("%i",&t);
    t=1;

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}