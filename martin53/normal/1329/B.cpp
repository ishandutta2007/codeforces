#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int d,mod;

map<int,int> seen;

int rec(int last_bit)
{
    if(seen.count(last_bit))return seen[last_bit];

    int ret=(last_bit!=-1);

    for(int bit=last_bit+1;(1LL<<bit)<=d;bit++)
    {
        int nums=min(d,(1<<(bit+1))-1)-(1<<bit)+1;

        //cout<<bit<<" nums= "<<nums<<endl;
        ret=(ret+1LL*nums*rec(bit))%mod;
    }

    seen[last_bit]=ret;

    //cout<<last_bit<<" -> "<<ret<<endl;

    return ret;
}
int query()
{
    scanf("%i%i",&d,&mod);

    seen={};

    return rec(-1);
}
int main()
{
    int t;
    scanf("%i",&t);

    for(int i=1;i<=t;i++)
        printf("%i\n",query());
    return 0;
}