#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
int n;
priority_queue< long long > pq;
int main()
{
scanf("%i",&n);
long long x;
for(int i=1;i<=n;i++)
{
    scanf("%lld",&x);
    pq.push(-x);
}
if(n%2==0)pq.push(0);
long long ret=0;
while(pq.size()>1)
{
    long long p=pq.top();
    pq.pop();
    long long q=pq.top();
    pq.pop();
    long long s=pq.top();
    pq.pop();
    ret=ret+(-(p+q+s));
    pq.push(p+q+s);
}
printf("%lld\n",ret);
return 0;
}