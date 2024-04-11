#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n;
struct dish
{
    int a,b,m;
    int id;
    int same_as;
};
dish inp[nmax];

int root(int node)
{
    if(node==inp[node].same_as)return node;
    inp[node].same_as=root(inp[node].same_as);
    return inp[node].same_as;
}

map<int, vector<dish> > seen;

pair<int,int> get_interval(dish cur)
{
    return {max(0,cur.a-cur.m),min(cur.a,cur.a+cur.b-cur.m)};
}

bool cmp(dish a,dish b)
{
    pair<int,int> is_a=get_interval(a);
    pair<int,int> is_b=get_interval(b);

    if(is_a.second!=is_b.second)return is_a.second<=is_b.second;
    return is_a.first>is_b.first;
}

int cnt=0;
pair<int,int> outp[nmax];//what the final state is


void go(vector<dish> cur)
{
    sort(cur.begin(),cur.end(),cmp);

    vector<dish> in={};

    for(int i=0;i<cur.size();i++)
    {
        dish w=cur[i];

        if(in.size())
        {
            pair<int,int> was=get_interval(in.back());
            pair<int,int> is=get_interval(w);

            if(is.first<=was.first&&was.second<=is.second)
            {
                inp[w.id].same_as=in.back().same_as;
                continue;
            }
        }

        in.push_back(w);

        pair<int,int> now;
        now.first=get_interval(w).second;
        now.second=w.a+w.b-w.m-now.first;

        cnt++;
        while(i<cur.size()&&cur[i].b>=now.second)
        {
            outp[cur[i].id]=now;
            i++;
        }

        i--;
    }
}

void solve()
{
    seen={};

    scanf("%i",&n);

    for(int i=1;i<=n;i++)
    {
        int a,b,m;

        scanf("%i%i%i",&a,&b,&m);

        dish cur;
        cur.a=a;
        cur.b=b;
        cur.m=m;
        cur.id=i;
        cur.same_as=i;

        inp[i]=cur;

        seen[a+b-m].push_back(cur);
    }

    cnt=0;

    for(auto w:seen)
        go(w.second);

    printf("%i\n",cnt);

    for(int i=1;i<=n;i++)
    {
        int j=root(inp[i].same_as);

        printf("%i %i\n",inp[j].a-outp[j].first,inp[j].b-outp[j].second);

    }
}

int main()
{
    int t;

    scanf("%i",&t);

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}