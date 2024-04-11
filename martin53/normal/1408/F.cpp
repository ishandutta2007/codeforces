#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42,MX=1e6+42;

int n,m;

vector< pair<int,int> > outp;

void make(int l,int r)
{
    if(l==r)return;

    int av=(l+r)/2;

    make(l,av);
    make(av+1,r);

    for(int i=l;i<=av;i++)
        outp.push_back({i,av+1+i-l});
}

vector<int> groups[20];

int pointer;

int main()
{
    scanf("%i",&n);

    int help=n;

    for(int i=0;i<20;i++)
        if((n&(1<<i)))pointer++;

    for(int i=0;i<=20;i++)
        if((n&(1<<i)))
        {
            make(help-(1<<i)+1,help);

            pointer--;

            for(int k=help;k>help-(1<<i);k--)
                groups[pointer].push_back(k);

            help=help-(1<<i);
        }

    for(int i=0;i<20;i++)
        if((n&(1<<i)))pointer++;

    pointer--;

    while(pointer>1)
    {
        for(int i=1;i<=pointer;i++)
            if(groups[i-1].size()<groups[i].size())
                swap(groups[i-1],groups[i]);
        /*
        cout<<outp.size()<<" "<<pointer<<endl;
        for(int i=0;i<=pointer;i++)cout<<i<<" -> "<<groups[i].size()<<endl;
        */
        if(groups[pointer-1].size()==groups[pointer].size())
        {
            vector<int> help={};

            for(int j=0;j<groups[pointer].size();j++)
            {
                outp.push_back({groups[pointer][j],groups[pointer-1][j]});

                help.push_back(groups[pointer][j]);
                help.push_back(groups[pointer-1][j]);
            }

            pointer--;
            groups[pointer]=help;
        }
        else
        {
            vector<int> help={};

            int SZ=groups[0].size()-1;

            for(int j=0;j<groups[pointer].size();j++)
            {
                outp.push_back({groups[pointer][j],groups[0][SZ-j]});
                groups[0].pop_back();

                help.push_back(groups[pointer][j]);
                help.push_back(groups[0][SZ-j]);
            }

            groups[pointer]=help;
        }
    }

    assert(outp.size()<5e5);

    printf("%i\n",outp.size());
    for(auto k:outp)printf("%i %i\n",k.first,k.second);

    return 0;
}