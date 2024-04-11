#include<bits/stdc++.h>
using namespace std;
const int nmax=5e5+42;

vector< pair<int,int> > tree[4*nmax];

int n,q;

bool yes[nmax];

int parent[nmax],SZ[nmax];

int outp[nmax];

vector< pair<int, pair<int,int> > > edges[nmax];

vector< pair<int,int> > to_solve[nmax];

int root(int x)
{
    if(parent[x]==x)return x;
    return root(parent[x]);
}
int height(int x)
{
    if(x==parent[x])return 0;
    return height(parent[x])+1;
}

void merg(int p,int q)
{
    //cout<<"merging "<<p<<" "<<q<<endl;
    SZ[p]+=SZ[q];
    parent[q]=p;
}

void run(int node,int l,int r)
{
    /*
    cout<<"---"<<endl;
    cout<<"run "<<node<<" "<<l<<" "<<r<<endl;
    */
    vector< pair<int,int> > performed={};
    int av=(l+r)/2;

    //cout<<"predi ";for(int i=1;i<=n;i++)cout<<parent[i]<<" ";cout<<endl;

    for(auto &k:tree[node])
    {
        //cout<<"k "<<k.first<<" "<<k.second<<endl;

        k.first=root(k.first);
        k.second=root(k.second);

        if(root(k.first)==root(k.second))continue;

        if(SZ[k.first]<SZ[k.second])swap(k.first,k.second);

        merg(k.first,k.second);

        performed.push_back({k.first,k.second});
    }
    /*
    for(auto k:performed)
        cout<<"performed: "<<k.first<<" "<<k.second<<endl;

    cout<<"stava ";for(int i=1;i<=n;i++)cout<<parent[i]<<" ";cout<<endl;
    cout<<"stava ";for(int i=1;i<=n;i++)cout<<SZ[root(i)]<<" ";cout<<endl;
    */
    if(l==r)
    {
        for(auto w:to_solve[l])
        {
            //cout<<"solve "<<w.first<<" "<<w.second<<" -> "<<root(w.second)<<endl;

            outp[w.first]=SZ[root(w.second)];
        }
    }
    else
    {
        run(node*2,l,av);
        run(node*2+1,av+1,r);
    }

    reverse(performed.begin(),performed.end());
    for(auto k:performed)
    {
        //cout<<"unmerge "<<k.first<<" "<<k.second<<endl;

        parent[k.second]=k.second;
        SZ[k.first]=SZ[k.first]-SZ[k.second];
    }

}
void update(int node,int l,int r,int lq,int rq,pair<int,int> now)
{
    /*
    cout<<l<<" "<<r<<" "<<lq<<" "<<rq<<endl;
    system("pause");
    */
    if(l==lq&&r==rq)
    {
        //cout<<node<<" -> "<<now.first<<" "<<now.second<<endl;
        tree[node].push_back(now);
        return;
    }
    int av=(l+r)/2;
    if(lq<=av)update(node*2,l,av,lq,min(rq,av),now);
    if(av<rq)update(node*2+1,av+1,r,max(lq,av+1),rq,now);
}

int en[nmax];

int main()
{
    int u,v,k;
    scanf("%i%i%i",&n,&q,&k);

    int days=1,id=0;

    for(int i=1;i<=q;i++)
    {
        int type;
        scanf("%i",&type);

        id++;

        if(type==1)
        {
            scanf("%i%i",&u,&v);
            edges[days].push_back({id,{u,v}});
        }
        else if(type==2)
        {
            int node;

            scanf("%i",&node);

            to_solve[id].push_back({id,node});
        }
        else
        {
            en[days]=id;
            days++;
        }
    }

    en[days]=id;

    for(int i=1;i<=days;i++)
        for(auto w:edges[i])
            update(1,1,q,w.first,en[min(days,i+k-1)],w.second);

    for(int i=1;i<=n;i++)parent[i]=i,SZ[i]=1;

    run(1,1,q);

    for(int i=1;i<=q;i++)
       if(outp[i])printf("%i\n",outp[i]);
    return 0;
}