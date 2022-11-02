#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b, c, A[200010], seg[800010];
void update(int id, int s, int e, int x)
{
    if(e<x||x<s)return;
    if(s==e)
    {
        seg[id]=1;
        return;
    }
    int m=s+e>>1;update(id*2, s, m, x);update(id*2+1, m+1, e, x);seg[id]=seg[id*2]+seg[id*2+1];
}
int get(int id, int s, int e, int l, int r)
{
    if(l>r)return 0;
    if(e<l||r<s)return 0;
    if(l<=s&&e<=r)return seg[id];
    int m=s+e>>1;return get(id*2, s, m, l, r)+get(id*2+1, m+1, e, l, r);
}
main()
{
    for(scanf("%d", &t);t--;)
    {
        map<int, int>mp;
        scanf("%d", &n);for(i=0;i++<n;)scanf("%d", &A[i]),mp[A[i]]++;
        map<int, int>::iterator it;a=0;
        for(it=mp.begin();it!=mp.end();it++)it->second=++a;
        for(i=0;i++<n;)A[i]=mp[A[i]];
        for(i=0;i++<4*a;)seg[i]=0;
        for(i=0;i++<n;)
        {
            update(1, 1, a, A[i]);if(i==1)continue;int x=A[i-1];int y=A[i];if(x>y)swap(x, y);
            if(get(1, 1, a, x+1, y-1))
            {
                puts("NO");goto w;
            }
        }puts("YES");w:;
    }
}