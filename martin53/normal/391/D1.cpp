#include<bits/stdc++.h>
using namespace std;
const int nmax=5e4+42;

struct info
{
    int x1,y1,x2,y2;
};

int s;
info horizontal[nmax];

int t;
info vertical[nmax];

int x_id,x[nmax*4];

int id_active;
info active[nmax*4];

int id_other;
pair< pair<int/*x*/,int/*y*/>,int/*type of event*/> other[nmax*4];

int tree[16*nmax];
void update(int node,int l,int r,int pos,int val)
{
    if(l==r)
    {
        tree[node]+=val;
        return;
    }
    int av=(l+r)/2;
    if(pos<=av)update(node*2,l,av,pos,val);
    else update(node*2+1,av+1,r,pos,val);

    tree[node]=max(tree[node*2],tree[node*2+1]);
}

int where(int val)
{
    int ok=x_id,not_ok=0;
    while(ok-not_ok>1)
    {
        int av=(ok+not_ok)/2;
        if(x[av]>=val)ok=av;
        else not_ok=av;
    }
    return ok;
}

int query(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)return tree[node];
    int av=(l+r)/2;
    int ret=0;
    if(lq<=av)ret=max(ret,query(node*2,l,av,lq,min(av,rq)));
    if(av<rq)ret=max(ret,query(node*2+1,av+1,r,max(av+1,lq),rq));
    return ret;
}
bool cmp(info l,info r)
{
    return l.y1<r.y1;
}
bool cmp2(pair< pair<int/*x*/,int/*y*/>,int/*type of event*/> u,pair< pair<int/*x*/,int/*y*/>,int/*type of event*/> v)
{
    return u.first.second<v.first.second;
}
bool can(int test)
{
    x_id=0;
    memset(tree,0,sizeof(tree));

    for(int i=1;i<=s;i++)
    {
        if(horizontal[i].y1+test<=horizontal[i].y2-test)
        {
            x_id++;
            x[x_id]=horizontal[i].x1;
        }
    }

    for(int i=1;i<=t;i++)
    {
        if(vertical[i].x1+test<=vertical[i].x2-test)
        {
            x_id++;
            x[x_id]=vertical[i].x1+test;
            x_id++;
            x[x_id]=vertical[i].x2-test;
        }
    }

    sort(x+1,x+x_id+1);
    //cout<<"x: ";for(int i=1;i<=x_id;i++)cout<<x[i]<<" ";cout<<endl;

    id_other=0;
    for(int i=1;i<=s;i++)
    {
        if(horizontal[i].y1+test<=horizontal[i].y2-test)
        {
            pair< pair<int/*x*/,int/*y*/>,int/*type of event*/> current;
            current.first.first=where(horizontal[i].x1);
            current.first.second=horizontal[i].y1+test;
            current.second=1;
            id_other++;
            other[id_other]=current;

            current.first.first=where(horizontal[i].x1);
            current.first.second=horizontal[i].y2-test+1;
            current.second=-1;
            id_other++;
            other[id_other]=current;
        }
    }

    id_active=0;
    for(int i=1;i<=t;i++)
    {
        if(vertical[i].x1+test<=vertical[i].x2-test)
        {
            info now=vertical[i];
            now.x1=where(vertical[i].x1+test);
            now.x2=where(vertical[i].x2-test);
            id_active++;
            active[id_active]=now;
        }
    }

    sort(active+1,active+id_active+1,cmp);
    sort(other+1,other+id_other+1,cmp2);
    /*
    cout<<"test= "<<test<<endl;
    cout<<"active: "<<endl;for(int i=1;i<=id_active;i++)cout<<active[i].x1<<" "<<active[i].y1<<" "<<active[i].x2<<" "<<active[i].y2<<endl;
    cout<<"other: "<<endl;for(int i=1;i<=id_other;i++)cout<<other[i].first.first<<" "<<other[i].first.second<<" "<<other[i].second<<endl;
    cout<<"---"<<endl;
    */
    int j=1;
    for(int i=1;i<=id_active;i++)
    {
        while(j<=id_other&&other[j].first.second<=active[i].y1)
        {
            update(1,1,x_id,other[j].first.first,other[j].second);
            j++;
        }

        if(query(1,1,x_id,active[i].x1,active[i].x2))return 1;
    }
    return 0;
}
int main()
{
    scanf("%i%i",&s,&t);

    int x,y,l;

    for(int i=1;i<=s;i++)
    {
        scanf("%i%i%i",&x,&y,&l);
        info now;
        now.x1=x;
        now.y1=y;
        now.x2=x;
        now.y2=y+l;
        horizontal[i]=now;
    }

    for(int i=1;i<=t;i++)
    {
        scanf("%i%i%i",&x,&y,&l);
        info now;
        now.x1=x;
        now.y1=y;
        now.x2=x+l;
        now.y2=y;
        vertical[i]=now;
    }

    int ok=0,not_ok=100000000+42;

    while(not_ok-ok>1)
    {
        int av=(ok+not_ok)/2;
        if(can(av))ok=av;
        else not_ok=av;
    }

    printf("%i\n",ok);
    return 0;
}