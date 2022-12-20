#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

long long n,s;

long long eval(int coeff,long long remain)
{
    long long ret=0,cur=1;

    for(int i=1;remain>0;i++)
    {
        ret=ret+i*min(remain,cur);

        remain=remain-cur;

        cur=cur*coeff;
    }
    return ret;
}

int branch;

set<int> adj[nmax];

set<int> seen[nmax];

int h[nmax];

int mx_h;

int parent[nmax];

void gen_dumb()
{
    h[1]=1;
    s=s-1;

    int pointer=1;

    for(int i=2;i<=n;i++)
    {
        if(adj[pointer].size()==branch)pointer++;

        h[i]=h[pointer]+1;

        //cout<<i<<" "<<pointer<<" -> "<<h[i]<<" "<<h[pointer]<<endl;

        s=s-h[i];

        adj[pointer].insert(i);

        parent[i]=pointer;
    }

    for(int i=1;i<=n;i++)
    {
        seen[h[i]].insert(i);
        mx_h=max(mx_h,h[i]);

        //cout<<i<<" -> "<<h[i]<<" "<<parent[i]<<endl;
    }
}

int main()
{
    scanf("%lld%lld",&n,&s);

    long long low=n+(n-1),high=n*(n+1)/2;

    if(low>s||s>high)
    {
        printf("No\n");
        return 0;
    }

    int ok=n,not_ok=1;

    while(ok-not_ok>1)
    {
        int av=(ok+not_ok)/2;

        if(eval(av,n)>s)not_ok=av;
        else ok=av;
    }

    branch=ok;

    //cout<<ok<<endl;

    gen_dumb();

    //cout<<"s= "<<s<<endl;

    for(int i=n;i>=1;i--)
        if(adj[i].size()==0)
        {
            for(int j=min(1LL*mx_h,s-1+h[i]);j>=h[i];j--)
            {
                for(auto w:seen[j])
                    if(w!=i&&adj[w].size()<branch)
                    {
                        //make i a child of w
                        adj[parent[i]].erase(i);
                        adj[w].insert(i);

                        s=s+h[i]-(h[w]+1);

                        seen[h[i]].erase(i);

                        h[i]=h[w]+1;

                        mx_h=max(mx_h,h[i]);

                        seen[h[i]].insert(i);

                        parent[i]=w;

                        //cout<<"moved "<<i<<" to "<<w<<" "<<h[i]<<endl;

                        break;
                    }
            }
        }

    //cout<<"s= "<<s<<endl;

    assert(s==0);

    printf("YES\n");
    for(int i=2;i<=n;i++)
        printf("%i ",parent[i]);
    printf("\n");

    return 0;
}