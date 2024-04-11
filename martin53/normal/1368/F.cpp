#include<bits/stdc++.h>
using namespace std;

const int nmax=1e3+42;

int n;

bool active[nmax];

int f(int k)
{
    return n-(n-1)/k-k;
}

int on()
{
    int ret=0;

    for(int i=1;i<=n;i++)
        if(active[i])ret++;

    return ret;
}

bool want[nmax];

void print(vector<int> cur)
{
    cout<<cur.size();

    for(auto w:cur)
    {
        cout<<" "<<w;
        active[w]=1;
    }

    cout<<endl;

    int ret;

    cin>>ret;

    assert(ret!=-1);

    for(int i=0;i<cur.size();i++)
    {
        int cur=i+ret;
        if(cur>n)cur=cur-n;

        active[cur]=0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin>>n;

    int k=1;

    for(int i=1;i<=n;i++)
    {
        if(f(k)<f(i))k=i;
    }

    for(int i=1;i<n;i++)
        if(i%k)want[i]=1;

    while(on()<f(k))
    {
        vector<int> taken={};

        for(int i=1;i<=n&&taken.size()<k;i++)
            if(want[i]&&active[i]==0)taken.push_back(i);

        print(taken);
    }

    //cout<<on()<<" "<<f(k)<<" "<<k<<endl;

    cout<<0<<endl;
    return 0;
}