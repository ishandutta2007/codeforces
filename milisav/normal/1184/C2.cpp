#include<bits/stdc++.h>

using namespace std;

const int maxi =1<<24;
const int add = 2e+6+10;
const int sz = 1<<23;
int n, r;
pair<int, pair<int, int>> events[1000000];
int tree[maxi], lazy[maxi];

void update(int node, int l, int r, int tl, int tr, int val)
{
    if (tl>r || tr<l){
         tree[node]+=lazy[node];
         if (r!=l)
         {
             lazy[2*node]+=lazy[node];
             lazy[2*node+1] +=lazy[node];
         }
         lazy[node] = 0;
         return;
    }

   if (tl<=l && tr>=r)
   {
       lazy[node]+=val;
       tree[node]+=lazy[node];
       if (r!=l)
       {
           lazy[2*node] +=lazy[node];
           lazy[2*node + 1] += lazy[node];
       }
       lazy[node] = 0;
       return;
   }

   lazy[2*node] += lazy[node];
   lazy[2*node+1] += lazy[node];
   lazy[node] = 0;
   update(2*node, l, (l+r)/2, tl, tr, val);
   update(2*node+1, (l+r)/2+1, r, tl, tr, val);
   tree[node] = max(tree[2*node], tree[2*node+1]);
}

int main()
{
    cin>>n>>r;

    int cnt = 0;
    for (int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        events[++cnt] = {x-y-r,{1, x+y + add}};
        events[++cnt] = {x-y+r+1, {-1, x+y + add}};
    }

    sort(events+1, events+cnt+1);

    int ans = 0;

    for (int i=1;i<=cnt;i++)
    {
        update(1, 1, sz, events[i].second.second, events[i].second.second + 2*r, events[i].second.first);
        ans = max (ans, tree[1]);
    }

    cout<<ans<<endl;

    return 0;
}