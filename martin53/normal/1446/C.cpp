#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

int high[nmax];

int outp=1e9;

void solve(vector<int> active,int bit,int removed)
{
    if(active.size()==0)
    {
        outp=min(outp,removed);
        return;
    }

    if(bit<0)
    {
        outp=min(outp,removed);
        return;
    }

    vector<int> groups[2]={{},{}};

    for(auto k:active)
        if((inp[k]&(1<<bit)))groups[1].push_back(k);
        else groups[0].push_back(k);

    int kick[2];

    if(groups[0].size()==0)kick[0]=0;
    else kick[0]=groups[0].size()-1;

    if(groups[1].size()==0)kick[1]=0;
    else kick[1]=groups[1].size()-1;


    //remove all 0
    solve(groups[1],bit-1,removed+kick[0]);
    //remove all 1
    solve(groups[0],bit-1,removed+kick[1]);
}
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    vector<int> active={};
    for(int i=1;i<=n;i++)active.push_back(i);

    solve(active,30,0);

    printf("%i\n",outp);

    return 0;
}