#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int pointtree[200010];
struct data
{
    int st, fin;
    LL sum;
}tree[2000010];
int x;
void maketree(int point, int num)
{
    if(num==1){
        pointtree[++x]=point;
        tree[point].st=tree[point].fin=x;
    }
    if(num<=1)return;
    maketree(point*2, num-num/2);
    maketree(point*2+1, num/2);
    tree[point].st=tree[point*2].st;
    tree[point].fin=tree[point*2+1].fin;
}
LL sumrange(int a, int b, int point)
{
    if(tree[point].st>=a&&tree[point].fin<=b)return tree[point].sum;
    if(tree[point].st>b||tree[point].fin<a)return 0;
    return sumrange(a, b, point*2)+sumrange(a, b, point*2+1);
}
void binupdate(int point)
{
    if(point<=0)return;
    tree[point].sum=tree[point*2].sum+tree[point*2+1].sum;
    binupdate(point/2);
}
void update(int num, LL p)
{
    tree[pointtree[num]].sum=p;
    binupdate(pointtree[num]/2);
}
int n;
pair<LL, LL> point[200010];
vector<LL> idx, idy;
LL ans;
bool comp(pair<LL, LL> a, pair<LL, LL> b)
{
    if(a.second!=b.second)return a.second>b.second;
    return a.first<b.first;
}
int main()
{
    scanf("%d", &n);
    maketree(1, n);
    for(int i=1; i<=n; i++){
        scanf("%lld %lld", &point[i].first, &point[i].second);
        idx.push_back(point[i].first);
        idy.push_back(point[i].second);
    }
    sort(idx.begin(), idx.end());
    sort(idy.begin(), idy.end());
    idx.erase(unique(idx.begin(), idx.end()), idx.end());
    idy.erase(unique(idy.begin(), idy.end()), idy.end());
    for(int i=1; i<=n; i++){
        point[i].first=lower_bound(idx.begin(), idx.end(), point[i].first)-idx.begin()+1;
        point[i].second=lower_bound(idy.begin(), idy.end(), point[i].second)-idy.begin()+1;
    }
    sort(point+1, point+n+1, comp);
    for(int i=1; i<=n; i++){
        int st=i, pv=0;
        while(1){
            if(point[i].second!=point[i+1].second)break;
            i++;
        }
        for(int j=st; j<=i; j++){
            update(point[j].first, 1);
        }
        for(int j=st; j<=i; j++){
            ans+=sumrange(pv+1, point[j].first, 1)*sumrange(point[j].first, n, 1);
            pv=point[j].first;
        }
    }
    printf("%lld", ans);
}