#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int xmax,ymax,zmax,n,m,k;

struct point
{
    int x,y,z;
};
point inp[nmax];

bool in(int x,int y,int z,int min_x,int max_x,int min_y,int max_y,int min_z,int max_z)
{
    if(min_x<=x&&x<=max_x&&min_y<=y&&y<=max_y&&min_z<=z&&z<=max_z)return 1;
    return 0;
}

vector< pair<int,int> > mem[nmax];

vector< pair<int,int> > tree[4*nmax];

void build(int node,int l,int r)
{
    if(l==r)
    {
        sort(mem[l].begin(),mem[l].end());

        for(auto k:mem[l])
            tree[node].push_back(k);
        return;
    }

    int av=(l+r)/2;

    build(node*2,l,av);
    build(node*2+1,av+1,r);

    tree[node]=tree[node*2];
    for(auto k:tree[node*2+1])
        tree[node].push_back(k);

    sort(tree[node].begin(),tree[node].end());
}

bool query(int node,int l,int r,int lq,int rq,int min_x,int max_x,int min_y,int max_y)
{
    if(tree[node].size()==0)return 0;

    if(l==lq&&r==rq)
    {
        int low=lower_bound(tree[node].begin(),tree[node].end(),make_pair(min_x,0))-tree[node].begin();
        int high=upper_bound(tree[node].begin(),tree[node].end(),make_pair(max_x+1,0))-tree[node].begin()-1;

        for(int pos=low;pos<=high;pos++)
            if(min_y<=tree[node][pos].second&&tree[node][pos].second<=max_y)return 1;
        return 0;
    }

    int av=(l+r)/2;

    if(lq<=av)
    {
        if(query(node*2,l,av,lq,min(av,rq),min_x,max_x,min_y,max_y))return 1;
    }

    if(av<rq)
    {
        if(query(node*2+1,av+1,r,max(av+1,lq),rq,min_x,max_x,min_y,max_y))return 1;
    }

    return 0;
}
int main()
{
    scanf("%i%i%i%i%i%i",&xmax,&ymax,&zmax,&n,&m,&k);

    int min_x=1e9,max_x=0,min_y=1e9,max_y=0,min_z=1e9,max_z=0;

    for(int i=1;i<=n;i++)
    {
        int x,y,z;

        scanf("%i%i%i",&x,&y,&z);

        min_x=min(min_x,x);
        max_x=max(max_x,x);

        min_y=min(min_y,y);
        max_y=max(max_y,y);

        min_z=min(min_z,z);
        max_z=max(max_z,z);
    }

    for(int i=1;i<=m;i++)
    {
        int x,y,z;

        scanf("%i%i%i",&x,&y,&z);

        if(in(x,y,z,min_x,max_x,min_y,max_y,min_z,max_z))
        {
            printf("INCORRECT\n");
            return 0;
        }

        inp[i].x=x;
        inp[i].y=y;
        inp[i].z=z;

        mem[z].push_back({x,y});
    }

    build(1,1,zmax);

    //cout<<min_x<<" "<<max_x<<" "<<min_y<<" "<<max_y<<" "<<min_z<<" "<<max_z<<endl;

    printf("CORRECT\n");
    for(int i=1;i<=k;i++)
    {
        int x,y,z;

        scanf("%i%i%i",&x,&y,&z);

        if(in(x,y,z,min_x,max_x,min_y,max_y,min_z,max_z))
        {
            printf("OPEN\n");
            continue;
        }

        int new_min_x=min(min_x,x),new_max_x=max(max_x,x);
        int new_min_y=min(min_y,y),new_max_y=max(max_y,y);
        int new_min_z=min(min_z,z),new_max_z=max(max_z,z);

        if(query(1,1,zmax,new_min_z,new_max_z,new_min_x,new_max_x,new_min_y,new_max_y))printf("CLOSED\n");
        else printf("UNKNOWN\n");
    }
    return 0;
}