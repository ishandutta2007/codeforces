#include<bits/stdc++.h>

using namespace std;

#define pb push_back
const int maxi = 4e6+10;
const int sz = 1<<20;
string s;
int n,m;
int a[maxi];
int b[maxi];
vector<int> v[maxi];
long long  tree[maxi];
long long  lazy[maxi];


void update(int node, int tl, int tr, int l , int r, int val)
{
    tree[node]+=lazy[node];
    if(tl!=tr) {
        lazy[2*node] +=lazy[node];
        lazy[2*node+1] +=lazy[node];
    }
    lazy[node] = 0;

    if (tr<l || tl>r) return;

    if (r>=tr && l<=tl)
    {
        tree[node]+=val;

        if(tl!=tr) {
            lazy[2*node] +=val;
            lazy[2*node+1] +=val;
        }
        return;
    }


    update(2*node, tl, (tr+tl)/2, l ,r, val);
    update(2*node+1, (tr+tl)/2 + 1, tr, l, r, val);

    tree[node] = min(tree[2*node], tree[2*node+1]);
}

int get_min(int node, int tl, int tr, int l, int r)
{
    tree[node]+=lazy[node];
    if(tl!=tr) {
        lazy[2*node] +=lazy[node];
        lazy[2*node+1] +=lazy[node];
    }
    lazy[node] = 0;

    if (tr<l || tl>r) return 1e9;

    if (l<=tl && tr<=r) return tree[node];

    int mi1 = get_min(2*node, tl, (tl+tr)/2, l ,r);
    int mi2 = get_min(2*node+1, (tl+tr)/2+1, tr, l ,r);

    return min(mi1, mi2);

}

int main()
{
    scanf("%d %d",&n,&m);

    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    for (int i=1;i<=m;i++)
        scanf("%d",&b[i]);

    for (int i=1;i<=n;i++)
        update(1,1,sz,1, a[i], -1);

    for (int i=1;i<=m;i++)
        update(1,1,sz,1, b[i], 1);

    int q;
    scanf("%d",&q);


    while(q--)
    {
        int tip,x,y;
        scanf("%d%d%d",&tip,&x,&y);
        if (tip==1)
        {
            update(1,1,sz,1,a[x],1);
            update(1,1,sz,1,y,-1);
            a[x]=y;
        } else
        {
             update(1,1,sz,1,b[x],-1);
             update(1,1,sz,1,y,1);
             b[x] = y;
        }

        int l = 0;
        int r = sz;

        while(l<r)
        {
            int mid = (l+r+1)/2;
            if (get_min(1,1,sz,mid,sz)<0) l = mid;
            else r = mid-1;
        }
        //cout<<get_min(1,1,sz,100,sz)<<endl;
        if (l==0) printf("-1\n");
        else printf("%d\n",l);
    }
    return 0;
}