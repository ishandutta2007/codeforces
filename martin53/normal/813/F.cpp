#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
map< pair<int,int>,int> seen;
vector< pair<int,int> > tree[4*nmax];
int n,q;
bool yes[nmax];

int parent[nmax],SZ[nmax];

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

void run(int node,int l,int r,bool broken)
{
    /*
    cout<<"---"<<endl;
    cout<<"run "<<node<<" "<<l<<" "<<r<<" "<<broken<<endl;
    */
    if(broken)return;
    vector< pair<int,int> > performed={};
    bool bad=0;
    int av=(l+r)/2;

    //cout<<"predi ";for(int i=1;i<=n;i++)cout<<parent[i]<<" ";cout<<endl;


    for(auto &k:tree[node])
    {

        //cout<<"k "<<k.first<<" "<<k.second<<endl;

        if(root(k.first)==root(k.second))
        {
        if(height(k.first)%2==height(k.second)%2){bad=1;break;}
        continue;
        }
        if(SZ[k.first]<SZ[k.second])swap(k.first,k.second);


        //for(int j=1;j<=n;j++)cout<<parent[j]<<" ";cout<<endl;
        //cout<<":) "<<k.first<<" "<<k.second<<endl;

        while(parent[parent[k.first]]!=parent[k.first])k.first=parent[parent[k.first]];
        while(parent[parent[k.second]]!=parent[k.second])k.second=parent[parent[k.second]];

        if(k.first==parent[k.first]&&k.second==parent[k.second])merg(k.first,k.second);

        else if(k.first==parent[k.first]&&k.second!=parent[k.second]){swap(k.first,k.second);merg(k.first,k.second);}

        else if(k.first!=parent[k.first]&&k.second==parent[k.second])merg(k.first,k.second);

        else if(k.first!=parent[k.first]&&k.second!=parent[k.second]){k.first=parent[k.first],k.second=parent[k.second];merg(k.first,k.second);}
        performed.push_back({k.first,k.second});
    }

    /*for(auto k:performed)
        cout<<"performed: "<<k.first<<" "<<k.second<<endl;
    */
    //cout<<"stava ";for(int i=1;i<=n;i++)cout<<parent[i]<<" ";cout<<endl;

    if(l==r)
    {
    //for(int i=1;i<=n;i++)cout<<parent[i]<<" ";cout<<"->"<<bad<<endl;
    yes[l]=(!bad);
    }
    else
    {
    run(node*2,l,av,bad);
    run(node*2+1,av+1,r,bad);
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
    //cout<<l<<" "<<r<<" "<<lq<<" "<<rq<<endl;
    //system("pause");
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
int main()
{
int u,v;
scanf("%i%i",&n,&q);
for(int i=1;i<=q;i++)
{
    scanf("%i%i",&u,&v);
    if(u>v)swap(u,v);
    if(seen.count({u,v})==0)seen[{u,v}]=i;
    else if(seen[{u,v}]==-1)seen[{u,v}]=i;
    else
    {
        //cout<<seen[{u,v}]<<" "<<i<<endl;
        update(1,1,q,seen[{u,v}],i-1,{u,v});
        seen[{u,v}]=-1;
    }
}

for(auto k:seen)
    if(k.second!=-1)
    update(1,1,q,k.second,q,k.first);

for(int i=1;i<=n;i++)parent[i]=i,SZ[i]=1;

run(1,1,q,0);

for(int i=1;i<=q;i++)
    if(yes[i])printf("YES\n");
    else printf("NO\n");
return 0;
}