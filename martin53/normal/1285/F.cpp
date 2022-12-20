#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;
int n,inp[nmax];

vector<int> seen[nmax],divs[nmax];

bool cmp(int a,int b)
{
    return a>b;
}

int mobuis[nmax],cnt[nmax];

stack<int> active,idle;

void update(int cur,int coeff)
{
    for(auto w:divs[cur])
        cnt[w]+=coeff;
}

int coprime(int val)
{
    int ret=0;

    for(auto w:divs[val])
        ret=ret+cnt[w]*mobuis[w];

    return ret;
}

long long solve(int g)
{
    for(auto &k:seen[g])
        k=k/g;

    sort(seen[g].begin(),seen[g].end(),cmp);

    if(seen[g].size()<=1)return 0;

    //cout<<"g: "<<g<<" -> ";for(auto k:seen[g])cout<<k<<" ";cout<<endl;

    long long ret=0;
    //max a*b, (a,b)=1
    for(auto cur:seen[g])
    {
        while(coprime(cur))
        {
            //cout<<"cur= "<<cur<<" "<<coprime(cur)<<endl;

            if(__gcd(active.top(),cur)==1)ret=max(ret,1LL*cur*active.top());

            update(active.top(),-1);
            active.pop();
        }

        update(cur,1);
        active.push(cur);
    }

    while(active.size())
    {
        update(active.top(),-1);
        active.pop();
    }

    return ret;
}

void calc()
{
    for(int i=1;i<nmax;i++)
        for(int j=i;j<nmax;j=j+i)
            divs[j].push_back(i);

    for(int i=1;i<=n;i++)
        for(int j=1;j*j<=inp[i];j++)
            if(inp[i]%j==0)
            {
                seen[j].push_back(inp[i]);
                if(j!=inp[i]/j)seen[inp[i]/j].push_back(inp[i]);
            }

    for(int i=1;i<nmax;i++)
    {
        bool zero=0;

        int deg=0;

        int mem=i;

        for(int j=2;j*j<=mem;j++)
            if(mem%j==0)
            {
                if(mem%(j*j)==0)zero=1;

                while(mem%j==0)
                {
                    mem=mem/j;
                    deg++;
                }
            }

        if(mem!=1)deg++;

        if(zero==0)
        {
            if(deg%2==0)mobuis[i]=1;
            else mobuis[i]=-1;
        }
    }


}
int main()
{
    set<int> in={};

    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);

        in.insert(inp[i]);
    }
    n=0;
    for(auto k:in)
    {
        n++;
        inp[n]=k;
    }

    calc();

    long long outp=0;
    for(int i=1;i<=n;i++)
        if(inp[i]>outp)outp=inp[i];

    for(int g=1;g<nmax;g++)
        outp=max(outp,1LL*g*solve(g));

    printf("%lld\n",outp);
    return 0;
}