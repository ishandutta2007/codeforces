#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,inp[nmax];

int solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int prv=-1e9,ret=0;

    for(int i=1;i<=n;i++)
    {
        if(prv<=inp[i]){prv=inp[i];continue;}
        int diff=prv-inp[i];

        //cout<<"diff= "<<diff<<endl;

        int now=1;
        while((1LL<<now)-1<diff)now++;

        ret=max(ret,now);
    }
    return ret;
}

int main()
{
    int t;
    scanf("%i",&t);

    for(int i=1;i<=t;i++)
        printf("%i\n",solve());
    return 0;
}