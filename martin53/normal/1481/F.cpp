#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n,a,b;

vector<int> adj[nmax];

int depth[nmax];

vector<int> seen[nmax];

int d_max=0;

void dfs(int node,int d)
{
    //cout<<"dfs "<<node<<" "<<d<<endl;

    d_max=max(d_max,d);

    depth[node]=d;

    seen[depth[node]].push_back(node);

    for(auto w:adj[node])
        dfs(w,d+1);
}

pair< vector<int>, vector<int> > active[nmax];

void push(int SZ,vector<int> cur)
{
    //cout<<"push "<<SZ<<" cur: ";for(auto w:cur)cout<<w<<" ";cout<<endl;

    if(active[SZ].first.size()==0)
    {
        active[SZ].first=cur;
        return;
    }

    if(active[SZ].second.size()==0)
    {
        active[SZ].second=cur;
        return;
    }

    for(auto w:active[SZ].second)
        cur.push_back(w);

    active[SZ].second={};

    push(2*SZ,cur);
}

bitset<nmax> possible[650];

int pointer=0;

vector<int> mem[nmax];

void add(int SZ,vector<int> cur)
{
    pointer++;

    mem[pointer]=cur;

    //cout<<"add "<<SZ<<" -> ";for(auto w:cur)cout<<w<<" ";cout<<endl;

    possible[pointer]=possible[pointer-1]|(possible[pointer-1]<<SZ);
}

int colour_depth[nmax];

void direct()
{
    while(a)
    {
        if(possible[pointer-1][a])pointer--;
        else
        {
            for(auto w:mem[pointer])
            {
                colour_depth[w]=1;
                a=a-seen[w].size();
            }

            pointer--;
        }
    }

    a=n-b;

    printf("%i\n",d_max);
    for(int i=1;i<=n;i++)
        if(colour_depth[depth[i]])
        {
            printf("a");
            a--;
        }
        else printf("b");

    printf("\n");

    assert(a==0);

    exit(0);
}

char outp[nmax];

set< string > all;

void gaz(int node,string cur)
{
    cur.push_back(outp[node]);

    all.insert(cur);

    for(auto w:adj[node])
        gaz(w,cur);
}
int dumb()
{
    gaz(1,"");

    return all.size();
}

mt19937 rng(42);

int main()
{
    scanf("%i%i",&n,&a);
    /*
    n=200;
    a=100;
    */
    b=n-a;

    for(int i=2;i<=n;i++)
    {
        int p;
        scanf("%i",&p);
        /*
        p=rng()%(i-1)+1;

        if(p<=n/2)p=1;
        */

        adj[p].push_back(i);
    }

    dfs(1,1);

    for(int i=1;i<=d_max;i++)
    {
        push(seen[i].size(),{i});
    }

    possible[0][0]=1;

    for(int i=1;i<=n;i++)
    {
        if(active[i].first.size())add(i,active[i].first);
        if(active[i].second.size())add(i,active[i].second);
    }

    if(possible[pointer][a])
    {
        direct();
        return 0;
    }

    /*
    for(int i=1;i<=d_max;i++)
    {
        cout<<i<<" -> ";
        for(auto w:seen[i])cout<<w<<" ";cout<<endl;
    }
    */

    for(int i=1;i<=d_max;i++)
    {
        if(seen[i].size()<=a)
        {
            a=a-seen[i].size();

            for(auto w:seen[i])
                outp[w]='a';

            continue;
        }

        if(seen[i].size()<=b)
        {
            b=b-seen[i].size();

            for(auto w:seen[i])
                outp[w]='b';

            continue;
        }

        //a, b < seen[i].size()
        vector<int> leaf={},non_leaf={};

        for(int j=1;j<=n;j++)
            if(outp[j]==0&&depth[j]==i)
            {
                if(adj[j].size()==0)leaf.push_back(j);
                else non_leaf.push_back(j);
            }

        //cout<<leaf.size()<<" "<<non_leaf.size()<<endl;

        if(non_leaf.size()<=a)
        {
            for(auto w:non_leaf)
            {
                a--;
                outp[w]='a';
            }

            for(auto w:seen[i])
                if(a&&outp[w]==0)
                {
                    a--;
                    outp[w]='a';
                }
        }
        else
        {
            assert(non_leaf.size()<=b);

            for(auto w:non_leaf)
            {
                b--;
                outp[w]='b';
            }

            for(auto w:seen[i])
                if(b&&outp[w]==0)
                {
                    b--;
                    outp[w]='b';
                }

        }

            for(int w=1;w<=n;w++)
                if(outp[w]==0)
            {
                if(a)
                {
                    a--;
                    outp[w]='a';
                    continue;
                }

                b--;
                outp[w]='b';
            }

        break;
    }

    //cout<<"d_max= "<<d_max<<endl;

    assert(a==0);
    assert(b==0);

    printf("%i\n",d_max+1);
    for(int i=1;i<=n;i++)
        printf("%c",outp[i]);
    printf("\n");

    //cout<<dumb()<<endl;

    //assert(d_max+1==dumb());

    return 0;
}