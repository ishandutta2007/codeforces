#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int N = 1048576;

struct trip{
    int a,b,c;
};

struct segmentTree{
private:
    int n;
    vector<trip> v;
    vector<pii> range;
public:
    segmentTree(int n)
    {
        int i;
        this -> n = n;
        trip t;
        t.a = 0; t.b = 0; t.c = 0;
        for(i=0;i<2*n;i++)
        {
            v.push_back(t);
            range.push_back({0,0});
        }
        range[1] = {1,n};
        queue<int> qu;
        qu.push(2);
        qu.push(3);
        while(!qu.empty())
        {
            int node = qu.front();
            qu.pop();
            int siz = range[node/2].second - range[node/2].first >> 1;
            int mid = range[node/2].second + range[node/2].first >> 1;
            if(node%2==0)
                range[node] = {range[node/2].first,mid};
            else
                range[node] = {mid+1,range[node/2].second};
            if(siz >= 1)
                qu.push(2*node),qu.push(2*node+1);
        }
    }
    void add(char c, int r)
    {
        if(c == '(')
            v[n-1+r].b =1;
        else
            v[n-1+r].c =1;
        r+=n; r--;
        r/=2;

        while(r>0)
        {
            int cur = min(v[2*r].b,v[2*r+1].c);
            v[r].a = v[2*r].a + v[2*r+1].a + cur;
            v[r].b = v[2*r].b + v[2*r+1].b - cur;
            v[r].c = v[2*r].c + v[2*r+1].c - cur;
            r/=2;
        }
    }
    trip query(int l, int r, int idx)
    {
        trip t;
        t.a = 0; t.b = 0; t.c = 0;
        if(l>=range[idx].first && r<=range[idx].second)
        {
            if(l==range[idx].first && r==range[idx].second)
                return v[idx];
            trip t,fi;
            t.a = 0; t.b = 0; t.c = 0;
            trip q = t,w = t;
            int mid = range[idx].first + range[idx].second >> 1;
            if(l<=mid)
                q = query(l,min(r,mid),2*idx);
            if(r>=mid+1)
                w = query(max(l,mid+1),r,2*idx+1);
            int cur = min(q.b,w.c);
            fi.a = q.a+w.a+cur;
            fi.b = q.b+w.b-cur;
            fi.c = q.c+w.c-cur;
            return fi;
        }
    }
    void print()
    {
        int i;
        for(i=1;i<2*n;i++)
            cout<<i<<" "<<range[i].first<<" "<<range[i].second<<" "<<v[i].a<<" "<<v[i].b<<" "<<v[i].c<<"\n";
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,i;
    string s;
    cin>>s;
    cin>>m;
    segmentTree thisTree(N);
    n = s.size();
    for(i=0;i<n;i++)
        thisTree.add(s.at(i),i+1);
    for(i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        trip node = thisTree.query(a,b,1);
        cout<<2*node.a<<"\n";
    }
    return 0;
}