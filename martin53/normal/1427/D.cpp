#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax],help[nmax];

vector<int> cur;

void apply()
{
    int pos=n;

    reverse(cur.begin(),cur.end());

    int where=0;

    for(auto t:cur)
    {
        for(int j=1;j<=t;j++)
        {
            where++;
            help[where]=inp[pos-t+j];
        }

        pos=pos-t;
    }

    for(int i=1;i<=n;i++)inp[i]=help[i];
}

void put(int l,int r)
{
    if(l>r)return;
    cur.push_back(r-l+1);
}

mt19937 rng(42);

void solve()
{

    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    /*
    n=7;
    for(int i=1;i<=n;i++)inp[i]=i;

    shuffle(inp+1,inp+n+1,rng);

    cout<<"inp: ";for(int i=1;i<=n;i++)cout<<inp[i]<<" ";cout<<endl;
    */
    vector< vector<int> > outp={};

    for(int i=1;i<=n;i++)
    {
        cur={};

        if(outp.size()%2==0)
        {
            if(inp[i]==i)continue;

            int t=i;

            while(inp[t]!=i)t++;

            for(int j=1;j<i;j++)
                put(j,j);

            put(i,t);

            for(int j=t+1;j<=n;j++)
                put(j,j);
        }
        else
        {
            if(inp[n+1-i]==i)continue;

            int t=n+1-i;

            while(inp[t]!=i)t--;

            for(int j=1;j<t;j++)
                put(j,j);

            put(t,n+1-i);

            for(int j=n+1-i+1;j<=n;j++)
                put(j,j);
        }

        outp.push_back(cur);

        apply();
        /*
        cout<<"i= "<<i<<endl;
        for(auto w:cur)cout<<w<<" ";cout<<endl;
        for(int j=1;j<=n;j++)cout<<inp[j]<<" ";cout<<endl;
        */
    }

    bool broken=0;
    for(int i=1;i<=n;i++)
        if(inp[i]!=i)broken=1;

    if(broken)
    {
        cur={};

        for(int j=1;j<=n;j++)
            cur.push_back(1);

        outp.push_back(cur);

        apply();
        /*
        for(auto w:cur)cout<<w<<" ";cout<<endl;
        for(int j=1;j<=n;j++)cout<<inp[j]<<" ";cout<<endl;
        */
    }

    vector< vector<int> > actual={};
    for(auto w:outp)
        if(w.size()>1)actual.push_back(w);
    outp=actual;

    for(int i=1;i<=n;i++)
        assert(inp[i]==i);

    assert(outp.size()<=n);

    printf("%i\n",outp.size());
    for(auto k:outp)
    {
        printf("%i",k.size());
        for(auto w:k)printf(" %i",w);
        printf("\n");
    }

}
int main()
{
    int t=1;
    while(t)
    {
        solve();
        t--;
    }

    return 0;
}