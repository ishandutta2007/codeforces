#include<bits/stdc++.h>
using namespace std;

const int nmax=1e3+42;

long long hsh_bit[nmax];

mt19937 rng(42);

long long hsh_switch[nmax];

vector< pair<long long,int> > LHS,RHS;

int n,s,q;

void gen_lhs(int pos,long long hsh,int used)
{
    if(pos>s/2)
    {
        LHS.push_back({hsh,used});
        return;
    }

    gen_lhs(pos+1,hsh,used);
    gen_lhs(pos+1,hsh^hsh_switch[pos],used+1);
}

void gen_rhs(int pos,long long hsh,int used)
{
    if(pos>s)
    {
        RHS.push_back({hsh,used});
        return;
    }

    gen_rhs(pos+1,hsh,used);
    gen_rhs(pos+1,hsh^hsh_switch[pos],used+1);
}

long long read_hsh()
{
    long long ret=0;

    int sz;
    scanf("%i",&sz);

    for(int j=1;j<=sz;j++)
    {
        int cur;

        scanf("%i",&cur);

        ret=ret^hsh_bit[cur];
    }
    return ret;
}

int main()
{
    scanf("%i%i%i",&n,&s,&q);

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<60;j++)
            hsh_bit[i]=hsh_bit[i]*2+rng()%2;
    }

    for(int i=1;i<=s;i++)
    {
        hsh_switch[i]=read_hsh();
    }

    gen_lhs(1,0,0);
    sort(LHS.begin(),LHS.end());

    gen_rhs(s/2+1,0,0);
    sort(RHS.begin(),RHS.end());

    /*
    cout<<"LHS: ";for(auto k:LHS)cout<<k.first<<" "<<k.second<<"\t";cout<<endl;
    cout<<"RHS: ";for(auto k:RHS)cout<<k.first<<" "<<k.second<<"\t";cout<<endl;
    */

    for(int i=1;i<=q;i++)
    {
        long long cur=read_hsh();

        int mini=s+1;

        for(auto k:LHS)
        {
            long long want=cur^k.first;

            int pos=lower_bound(RHS.begin(),RHS.end(),make_pair(want,0))-RHS.begin();

            if(pos<RHS.size()&&RHS[pos].first==want)
            {
                mini=min(mini,k.second+RHS[pos].second);
            }
        }

        if(mini>s)mini=-1;
        printf("%i\n",mini);
    }
    return 0;
}