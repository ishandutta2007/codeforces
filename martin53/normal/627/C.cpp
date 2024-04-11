#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
int dist,volume,m;
pair<int/*position*/,int/*cost*/> inp[nmax];
int nx[nmax];
deque< int/*index*/ >q;
int main()
{
scanf("%i%i%i",&dist,&volume,&m);
for(int i=1;i<=m;i++)
{
    scanf("%i%i",&inp[i].first,&inp[i].second);
}
m++;
inp[m]={0,1e9};
m++;
inp[m]={dist,0};
sort(inp+1,inp+m+1);
for(int i=2;i<=m;i++)
    if(inp[i].first-inp[i-1].first>volume)
    {
        printf("-1\n");
        return 0;
    }
memset(nx,-1,sizeof(nx));
q.push_back(m);
for(int i=m-1;i>=1;i--)
{
    while(inp[q.back()].first-inp[i].first>volume)q.pop_back();
    while(q.size()&&inp[q.front()].second>=inp[i].second)q.pop_front();
    if(q.size())nx[i]=q.front();
    q.push_front(i);
    //cout<<i<<" -> "<<q.size()<<endl;
}
//for(int i=1;i<=m;i++)cout<<nx[i]<<" ";cout<<endl;
long long ans=0;
int now=volume;
for(int i=1;i<m;i++)
{
    if(nx[i]==-1)
    {
        ans=ans+1LL*(volume-now)*inp[i].second;
        now=volume;
    }
    else
    {
        if(inp[i].first+now<inp[nx[i]].first)//you can't go
        {
            ans=ans+1LL*(inp[nx[i]].first-inp[i].first-now)*inp[i].second;
            now=now+(inp[nx[i]].first-inp[i].first-now);
        }
    }
    now=now-(inp[i+1].first-inp[i].first);
    assert(now>=0);
}
printf("%lld\n",ans);
return 0;
}