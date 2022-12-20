#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42,block=512,MX=1e6+42;
int n,q;
long long arr[nmax];
struct query
{
    int l,r,id;
};
query inp[nmax];
bool cmp(query a,query b)
{
    if(a.l/block!=b.l/block)return a.l<b.l;
    if((a.l/block)%2==0)return a.r<b.r;
    return a.r>b.r;
}
int l_=1,r_=0;
long long score;
long long seen[MX];

void add(int pos)
{
    score=score-arr[pos]*seen[arr[pos]]*seen[arr[pos]];
    seen[arr[pos]]++;
    score=score+arr[pos]*seen[arr[pos]]*seen[arr[pos]];
}
void take(int pos)
{
    score=score-arr[pos]*seen[arr[pos]]*seen[arr[pos]];
    seen[arr[pos]]--;
    score=score+arr[pos]*seen[arr[pos]]*seen[arr[pos]];
}
long long output[nmax];
int main()
{
scanf("%i%i",&n,&q);
for(int i=1;i<=n;i++)scanf("%i",&arr[i]);

for(int i=1;i<=q;i++)
{
    scanf("%i%i",&inp[i].l,&inp[i].r);
    inp[i].id=i;
}

sort(inp+1,inp+q+1,cmp);

for(int i=1;i<=q;i++)
{
    int l=inp[i].l,r=inp[i].r;
    while(l_>l)
    {
        l_--;
        add(l_);
    }

    while(r_<r)
    {
        r_++;
        add(r_);
    }

    while(l_<l)
    {
        take(l_);
        l_++;
    }

    while(r_>r)
    {
        take(r_);
        r_--;
    }
    output[inp[i].id]=score;
}

for(int i=1;i<=q;i++)
    printf("%lld\n",output[i]);
return 0;
}