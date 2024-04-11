#include<bits/stdc++.h>
using namespace std;

const int nmax=1000+42;

int n;

pair<int,int> inp[nmax];

vector< pair<int,int> > outp;

int help[nmax];

int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i].first);
        inp[i].second=i;
    }

    sort(inp+1,inp+n+1);

    for(int t=0;t<n;t++)
    {
        //sort(inp+1,inp+n+1);

        for(int i=1;i<n;i++)
        {
            int j=i+1;
            /*
            cout<<i<<" "<<j<<endl;
            for(int k=1;k<=n;k++)cout<<inp[k].first<<" "<<inp[k].second<<endl;
            cout<<"---"<<endl;
            */
            if(inp[i].second>inp[j].second)
            {
                //cout<<"swapped "<<inp[i].second<<" "<<inp[j].second<<endl;

                outp.push_back({inp[j].second,inp[i].second});
                swap(inp[i].second,inp[j].second);
            }
        }
    }

    for(int i=1;i<=n;i++)
        help[inp[i].second]=inp[i].first;

    for(int i=1;i<n;i++)
        assert(help[i]<=help[i+1]);

    printf("%i\n",outp.size());
    for(auto k:outp)printf("%i %i\n",k.first,k.second);

    return 0;
}