#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,inp[nmax];

int output[nmax];

vector< pair<int,int> > active;

int main()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int prv=0;

    for(int i=1;i<=n;i++)
    {
        for(auto &w:active)
            w.first=__gcd(w.first,inp[i]);

        active.push_back({inp[i],1});

        vector< pair<int,int> > help={};

        help.push_back({active[0].first,0});

        for(auto w:active)
            if(w.first==help.back().first)help[help.size()-1].second+=w.second;
            else help.push_back(w);

        active=help;

        int sum=0;

        for(auto w:active)
            if(i-sum>=w.first&&w.first>=i-sum-(w.second-1))
            {
                int l=i-w.first+1;

                if(prv<l)
                {
                    output[i]++;
                    prv=i;
                }

                break;
            }
            else sum+=w.second;
    }

    for(int i=1;i<=n;i++)
    {
        output[i]+=output[i-1];

        printf("%i ",output[i]);
    }

    printf("\n");

    return 0;
}