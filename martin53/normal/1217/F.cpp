#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;

int n,q;

int SZ[nmax],parent[nmax];

int root(int node)
{
    while(node!=parent[node])node=parent[node];
    return node;
}
pair<int,int> input[nmax][2];
int type[nmax];

pair<int,int> check(pair<int,int> ret)
{
    if(ret.first>ret.second)swap(ret.first,ret.second);
    return ret;
}

int nxt[nmax][2];

map< pair<int,int> ,int> seen;

int normal(pair<int,int> now)
{
    if(seen.count(now))return seen[now];
    return 0;
}

int last;

bool output[nmax];

vector< pair<int,int> > tree[nmax*4];

pair<int,int> current;

void note(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)
    {
        tree[node].push_back(current);
        return;
    }
    int av=(l+r)/2;
    if(lq<=av)note(node*2,l,av,lq,min(av,rq));
    if(av<rq)note(node*2+1,av+1,r,max(av+1,lq),rq);
}
void solve(int node,int l,int r)
{
    vector< pair<int/*big*/,int/*small*/> > added={};

    for(auto k:tree[node])
    {
        int u=root(k.first),v=root(k.second);
        if(u==v)continue;

        if(SZ[u]<SZ[v])swap(u,v);

        parent[v]=u;
        SZ[v]=SZ[v]+SZ[u];

        added.push_back({u,v});
    }

    if(l!=r)
    {
        int av=(l+r)/2;
        solve(node*2,l,av);
        solve(node*2+1,av+1,r);
    }
    else
    {
        if(type[l]==2)
        {
            int x_=(input[l][0].first+last-1)%n+1;
            int y_=(input[l][0].second+last-1)%n+1;

            //cout<<"ask "<<x_<<" "<<y_<<" -> ";

            output[l]=(root(x_)==root(y_));

            //cout<<output[l]<<endl;

            last=output[l];
        }
        else
        {
            int proper=last;
            int other=!proper;

            if(normal(input[l][proper])==0)
            {
                seen[input[l][proper]]=1;
                if(l+1<=nxt[l][proper])
                {
                    //cout<<"noting "<<input[l][proper].first<<" "<<input[l][proper].second<<" on "<<l+1<<" "<<nxt[l][proper]<<endl;
                    current=input[l][proper];
                    note(1,1,q,l+1,nxt[l][proper]);
                }
            }
            else
            {
                seen[input[l][proper]]=0;
            }

            if(normal(input[l][other]))
            {
                if(l+1<=nxt[l][other])
                {
                    //cout<<"noting "<<input[l][other].first<<" "<<input[l][other].second<<" on "<<l+1<<" "<<nxt[l][other]<<endl;
                    current=input[l][other];
                    note(1,1,q,l+1,nxt[l][other]);
                }
            }
        }
    }

    reverse(added.begin(),added.end());
    for(auto k:added)
    {
        SZ[k.first]=SZ[k.first]-SZ[k.second];
        parent[k.second]=k.second;
    }
}

int main()
{
    scanf("%i%i",&n,&q);

    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        SZ[i]=1;
    }
    for(int i=1;i<=q;i++)
    {
        scanf("%i%i%i",&type[i],&input[i][0].first,&input[i][0].second);
        if(type[i]==1)
        {
            input[i][1].first=(input[i][0].first)%n+1;
            input[i][1].second=(input[i][0].second)%n+1;
        }

        input[i][0]=check(input[i][0]);
        input[i][1]=check(input[i][1]);
    }

    for(int i=1;i<=q;i++)
    {
        nxt[i][0]=q;
        nxt[i][1]=q;
    }

    for(int i=q;i>=1;i--)
    {
        if(type[i]==2)continue;

        nxt[i][0]=normal(input[i][0]);
        nxt[i][1]=normal(input[i][1]);

        seen[input[i][0]]=i;
        seen[input[i][1]]=i;

        if(nxt[i][0]==0)nxt[i][0]=q;
        if(nxt[i][1]==0)nxt[i][1]=q;
    }

    seen={};

    solve(1,1,q);

    for(int i=1;i<=q;i++)
        if(type[i]==2)printf("%i",output[i]);
    printf("\n");
    return 0;
}