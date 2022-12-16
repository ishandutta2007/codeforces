#include<bits/stdc++.h>
using namespace std;

int eval(int p,int q)
{
    int cnt=0;

    while(p>1&&q>1)
    {
        if(p>q)p=(p+q-1)/q;
        else q=(p+q-1)/p;

        cnt++;
    }

    if(p+q==3)return cnt;
    return 1e9;
}

void solve()
{
    int n;
    scanf("%i",&n);

    for(int i=2;i<n;i++)
        if(eval(i,n)<=8)
        {
            vector< pair<int,int> > outp={};
            for(int j=2;j<n;j++)
                if(j!=i)outp.push_back({j,n});

            int p=i,q=n;

            while(p>1&&q>1)
            {
                if(p>q)
                {
                    p=(p+q-1)/q;
                    outp.push_back({i,n});
                }
                else
                {
                    q=(p+q-1)/p;
                    outp.push_back({n,i});
                }
            }

            printf("%i\n",outp.size());
            for(auto w:outp)printf("%i %i\n",w.first,w.second);
            return;
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