#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
#include<vector>
#include<functional>
using namespace std;
typedef long long LL;
const int MAXN=100010;
int k,n,m,type,x;
LL a[MAXN],y;
pair<LL,int> ass[MAXN];
vector<pair<LL,pair<int,int> > > add[MAXN];
vector<pair<double,pair<int,int> > > all;
int main()
{
    scanf("%d%d%d",&k,&n,&m);
    for(int i=1;i<=k;i++) scanf("%I64d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%I64d",&type,&x,&y);
        if(type==1) ass[x]=max(ass[x],make_pair(y,i));
        else if(type==2) add[x].push_back(make_pair(y,make_pair(i,2)));
        else all.push_back(make_pair((double)y,make_pair(i,3)));
    }
    for(int i=1;i<=k;i++) if(ass[i].first>a[i]) add[i].push_back(make_pair(ass[i].first-a[i],make_pair(ass[i].second,1)));
    for(int i=1;i<=k;i++) sort(add[i].begin(),add[i].end(),greater<pair<LL,pair<int,int> > >());
    for(int i=1;i<=k;i++)
    {
        int len=add[i].size();
        for(int j=0;j<len;j++)
        {
            all.push_back(make_pair((add[i][j].first+a[i])*1.0/a[i],add[i][j].second));
            a[i]+=add[i][j].first;
        }
    }
    sort(all.begin(),all.end(),greater<pair<double,pair<int,int> > >());
    if(m>all.size()) m=all.size();
    printf("%d\n",m);
    for(int i=0;i<m;i++) if(all[i].second.second==1) printf("%d ",all[i].second.first);
    for(int i=0;i<m;i++) if(all[i].second.second==2) printf("%d ",all[i].second.first);
    for(int i=0;i<m;i++) if(all[i].second.second==3) printf("%d ",all[i].second.first);
    puts("");
    return 0;
}