#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node{
    int sz, vl, nxt[26], go[26], link;
} blank;

struct Aho{
    vector<int> link, sz, vl;
    vector<vector<int> > nxt, go;
    vector<string> have;
    int cnt=0;

    void reset()
    {
        have.clear();
        link.clear(); link.push_back(0);
        sz.clear(); sz.push_back(0);
        vl.clear(); vl.push_back(0);
        nxt.clear(); nxt.push_back({{}}); nxt[0].resize(26);
        go.clear(); go.push_back({{}}); go[0].resize(26);
        cnt=0;
    }

    int newnode()
    {
        cnt++;
        link.push_back(0);
        sz.push_back(0);
        vl.push_back(0);
        nxt.push_back({{}}); nxt[cnt].resize(26);
        go.push_back({{}}); go[cnt].resize(26);
        return cnt;
    }

    void add(string s)
    {
        have.push_back(s);
        int node=0;
        for(auto ch:s)
        {
            int i=ch-'a';
            if(!nxt[node][i])
            {
                nxt[node][i]=newnode();
            }
            node=nxt[node][i];
        }
        sz[node]++;
    }

    void bfs()
    {
        queue<int> q;
        q.emplace(0);
        while(q.size())
        {
            int node=q.front();
            q.pop();
            vl[node]=vl[link[node]]+sz[node];
            for(int i=0; i<26; i++)
            {
                go[node][i]=go[link[node]][i];
                int u=nxt[node][i];
                if(u)
                {
                    link[u]=go[node][i];
                    go[node][i]=u;
                    q.emplace(u);
                }
            }
        }
        //cout<<link[3]<<endl;
    }
};

struct DynamicAho{
    Aho ah[20];

    DynamicAho(){
        for(int i=0; i<20; i++)
        {
            ah[i].reset();
        }
    }

    void add(string s)
    {
        vector<string> cac;
        cac.push_back(s);
        for(auto i:ah[0].have) cac.push_back(i);
        ah[0].reset();
        for(auto i:cac) ah[0].add(i);
        ah[0].bfs();
        if(ah[0].have.size()==2)
        {
            for(int i=1; i<20; i++)
            {
                if(ah[i].have.size())
                {
                    for(auto str:ah[i].have) ah[i-1].have.push_back(str);
                    ah[i].reset();
                    for(auto str:ah[i-1].have) ah[i].add(str);
                    ah[i-1].reset();
                }
                else
                {
                    for(auto str:ah[i-1].have)
                    {
                        ah[i].add(str);
                    }
                    ah[i].bfs();
                    ah[i-1].reset();
                    break;
                }
            }
        }
    }

    int get(string s)
    {
        int node[20], sum=0;
        memset(node, 0, sizeof(node));
        for(auto ch:s)
        {
            int nx=ch-'a';
            for(int i=0; i<20; i++)
            {
                node[i]=ah[i].go[node[i]][nx];
                //cout<<node[i]<<" ";
                sum+=ah[i].vl[node[i]];
            }
            //cout<<sum<<endl;
        }
        return sum;
    }
} Dora, Dangyeu;

signed main()
{
    // freopen("stringset.inp", "r", stdin);
    // freopen("stringset.out", "w", stdout);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int tp;
        string s;
        cin>>tp>>s;
        if(tp==1)
        {
            Dora.add(s);
        }
        else if(tp==2)
        {
            Dangyeu.add(s);
        }
        else if(tp==3)
        {
            cout<<Dora.get(s)-Dangyeu.get(s)<<endl;
        }
    }
}