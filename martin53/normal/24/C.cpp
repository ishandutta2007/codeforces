#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
pair<long long,long long>m,inp[nmax],m_;
long long n,j;

int main()
{
scanf("%lld%lld",&n,&j);
scanf("%lld%lld",&m.first,&m.second);
for(int i=0;i<n;i++)scanf("%lld%lld",&inp[i].first,&inp[i].second);
m_=m;
int cycle=-1;
for(int i=0;i<j;i++)
{
    m_.first=2*inp[i%n].first-m_.first;
    m_.second=2*inp[i%n].second-m_.second;
    if(i%n==n-1&&m_==m){cycle=i+1;break;}
}
if(cycle!=-1)
{
    m_=m;
    j=j%cycle;
    for(int i=0;i<j;i++)
    {
    m_.first=2*inp[i%n].first-m_.first;
    m_.second=2*inp[i%n].second-m_.second;
    }
}
printf("%lld %lld\n",m_.first,m_.second);
return 0;
}