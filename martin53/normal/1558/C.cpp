#include<bits/stdc++.h>
using namespace std;

const int nmax=2e3+42;

int inp[nmax];

vector<int> outp;

void add(int pos)
{
    //cout<<"add "<<pos<<endl;

    assert(pos%2==1);

    outp.push_back(pos);

    reverse(inp+1,inp+pos+1);
}

int where(int val)
{
    for(int i=1;true;i++)
        if(inp[i]==val)return i;
}

void solve(int n)
{
    add(where(n));

    add(where(n-1)-1);

    add(where(n-1)+1);

    add(3);

    add(n);

    //cout<<"solve "<<n<<" : ";for(int i=1;i<=n;i++)cout<<inp[i]<<" ";cout<<endl;
}

void solve()
{
    int n;

    scanf("%i",&n);

    for(int i=1;i<=n;i++)
        scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)
        if(inp[i]%2!=i%2)
        {
            printf("-1\n");
            return;
        }

    outp={};

    for(int i=n;i>=3;i=i-2)
        solve(i);

    for(int i=1;i<=n;i++)assert(inp[i]==i);

    printf("%i\n",outp.size());
    for(auto w:outp)printf("%i ",w);
    printf("\n");
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