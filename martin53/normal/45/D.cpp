#include<bits/stdc++.h>
using namespace std;
const int nmax=1e2+42;
int n;
struct event
{
int l,r,ind;
};
event inp[nmax];
bool cmp(event a,event b)
{
return a.l<b.l;
}
int output[nmax];
priority_queue< pair<int/*end day*/,int/*index*/> > pq;
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)
{
    inp[i].ind=i;
    scanf("%i%i",&inp[i].l,&inp[i].r);
}
sort(inp+1,inp+n+1,cmp);
int day=1,i=1;
while(i<=n||pq.size())
{
    if(pq.size()==0)day=inp[i].l;
    while(i<=n&&inp[i].l==day)
    {
        pq.push({-inp[i].r,inp[i].ind});
        i++;
    }
    output[pq.top().second]=day;
    day++;
    pq.pop();
}
for(int i=1;i<=n;i++)
    printf("%i ",output[i]);
return 0;
}