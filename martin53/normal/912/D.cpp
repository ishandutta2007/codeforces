#include<bits/stdc++.h>
using namespace std;
int r;
long long g(int p,int q)
{
    int i_min=max(1,p+r-q);
    int i_max=min(r,p);
    return i_max-i_min+1;
}
int n,m,k;
long long take(int x,int y)
{
    return g(x,n)*g(y,m);
}
map< pair<int,int>, bool> seen;
int main()
{
scanf("%i%i%i%i",&n,&m,&r,&k);
priority_queue< pair< long long, pair<int,int> > > pq;
pq.push({take((n+1)/2,(m+1)/2),{(n+1)/2,(m+1)/2}});
long long sum=0;
for(int i=1;i<=k;i++)
{
    pair< long long, pair<int,int> > now=pq.top();
    pq.pop();
    int x=now.second.first,y=now.second.second;
    if(1>x||x>n||1>y||y>m||seen.count({x,y})){i--;continue;}
    seen[{x,y}]=1;
    sum=sum+now.first;
    pq.push({take(x+1,y),{x+1,y}});
    pq.push({take(x-1,y),{x-1,y}});
    pq.push({take(x,y+1),{x,y+1}});
    pq.push({take(x,y-1),{x,y-1}});
}

printf("%.18f\n",1.0*sum/(n-r+1)/(m-r+1));
return 0;
}