#include<bits/stdc++.h>
using namespace std;
int T;

pair<int,int> uni(pair<int,int> u, pair<int,int> v)
{
    int a = u.first, b = u.second;
    int c = v.first, d = v.second;
    if(a>b) swap(a,b);
    if(c>d) swap(c,d);
    pair<int,int> cur = {min(a,c),max(b,d)};
    return cur;
}

bool intersect(pair<int,int> u, pair<int,int> v)
{
    int a = u.first, b = u.second;
    int c = v.first, d = v.second;
    if(a>b) swap(a,b);
    if(c>d) swap(c,d);
    if(a<c)
    {
        if(b<c)
            return false;
        else
            return true;
    }
    else if(c<a)
    {
        if(d<a)
            return false;
        else
            return true;
    }
    else
        return true;
}

int main()
{
    cin>>T;
    while(T--)
    {
        int n,m,x,i;
        cin>>n>>x>>m;
        pair<int,int> cur = {x,x};
        for(i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            pair<int,int> s = {a,b};
            if(intersect(cur,s))
                cur = uni(cur,s);
        }
        cout<<cur.second-cur.first+1<<"\n";
    }
}