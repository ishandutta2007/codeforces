#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

struct info
{
    int u,v,w;
};

info interesting[nmax*3];
int id;

void add(info current)
{
    id++;
    interesting[id]=current;
    //cout<<"added: "<<current.u<<" "<<current.v<<" "<<current.w<<endl;
}
int n;
int a[nmax],b[nmax],c[nmax];
map<int,int> seena,seenb,seenc;

bool cmp(info a,info b)
{
    return a.u<b.u;
}

set< pair<int/*v*/,int/*w*/> > active;

set< pair<int/*v[j]+w[j+1]*/,int/*w*/> > least;

void update(int v,int w)
{
    pair<int/*v*/,int/*w*/> now={v,w};
    set< pair<int/*v*/,int/*w*/> >::iterator it;
    it=active.lower_bound(now);

    if((*it).second>=w)return;//useless

    while(1)
    {
        it=active.lower_bound(now);
        pair<int/*v*/,int/*w*/> lower=*it;
        it--;
        pair<int/*v*/,int/*w*/> lower_before=*it;
        it--;
        pair<int/*v*/,int/*w*/> lower_before_before=*it;

        if(lower_before.second<=w)
        {
            active.erase(lower_before);

            least.erase({lower_before.first+lower.second,lower.second});
            least.erase({lower_before_before.first+lower_before.second,lower_before.second});

            least.insert({lower_before_before.first+lower.second,lower.second});
        }
        else break;
    }

    it=active.lower_bound(now);
    pair<int/*v*/,int/*w*/> lower=*it;
    it--;
    pair<int/*v*/,int/*w*/> lower_before=*it;

    least.erase({lower_before.first+lower.second,lower.second});

    least.insert({lower_before.first+now.second,now.second});
    least.insert({now.first+lower.second,lower.second});

    active.insert(now);
}

int query()
{
    int ret=3*n,prev=1e9;
    for(auto k:active)
    {
        ret=min(ret,k.second+prev);
        prev=k.first;
    }
    return ret;
}
int main()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    for(int i=n;i>=1;i--)seena[a[i]]=i;

    for(int i=1;i<=n;i++)scanf("%i",&b[i]);
    for(int i=n;i>=1;i--)seenb[b[i]]=i;

    for(int i=1;i<=n;i++)scanf("%i",&c[i]);
    for(int i=n;i>=1;i--)seenc[c[i]]=i;

    for(int i=1;i<=n;i++)
    {
       info current;

        current.u=3*n+1;
        if(seena.count(a[i]))current.u=seena[a[i]];

        current.v=3*n+1;
        if(seenb.count(a[i]))current.v=seenb[a[i]];

        current.w=3*n+1;
        if(seenc.count(a[i]))current.w=seenc[a[i]];

        if(current.u==i)add(current);
    }

    for(int i=1;i<=n;i++)
    {
       info current;

        current.u=3*n+1;
        if(seena.count(b[i]))current.u=seena[b[i]];

        current.v=3*n+1;
        if(seenb.count(b[i]))current.v=seenb[b[i]];

        current.w=3*n+1;
        if(seenc.count(b[i]))current.w=seenc[b[i]];

        if(current.u>n&&current.v==i)add(current);
    }

    for(int i=1;i<=n;i++)
    {
       info current;

        current.u=3*n+1;
        if(seena.count(c[i]))current.u=seena[c[i]];

        current.v=3*n+1;
        if(seenb.count(c[i]))current.v=seenb[c[i]];

        current.w=3*n+1;
        if(seenc.count(c[i]))current.w=seenc[c[i]];

        if(current.u>n&&current.v>n&&current.w==i)add(current);
    }

    active.insert({0,3*n+2});
    active.insert({3*n+2,0});
    least.insert({0,0});

    sort(interesting+1,interesting+id+1,cmp);

    for(int i=2;i<=id;i++)
        assert(interesting[i-1].u!=interesting[i].u||interesting[i-1].v!=interesting[i].v||interesting[i-1].w!=interesting[i].w);

    int ret=3*n;

    for(int u=n;u>=0;u--)
    {
        bool stop=0;
        while(id&&u<interesting[id].u)
        {
            if(interesting[id].v>n&&interesting[id].w>n)
            {
                //it is impossible now
                stop=1;
                break;
            }
            update(interesting[id].v,interesting[id].w);
            /*
            cout<<"just added "<<interesting[id].v<<" "<<interesting[id].w<<endl;
            cout<<"active: "<<endl;
            for(auto k:active)cout<<k.first<<" "<<k.second<<endl;
            cout<<"least: "<<endl;
            for(auto k:least)cout<<k.first<<" "<<k.second<<endl;
            cout<<"---"<<endl;
            */
            id--;
        }
        if(stop)break;
        int q=(*least.begin()).first;
        //cout<<"query= "<<u<<" -> "<<q<<endl;
        ret=min(ret,u+q);
    }

    printf("%i\n",ret);
    return 0;
}