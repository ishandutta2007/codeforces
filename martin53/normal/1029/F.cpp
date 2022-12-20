#include<bits/stdc++.h>
using namespace std;
vector< pair<long long,long long> > take(long long x)
{
    vector< pair<long long,long long> > now={};
    for(long long i=1;i*i<=x;i++)
        if(x%i==0)
        {
            now.push_back({i,x/i});
            now.push_back({x/i,i});
        }
    return now;
}
int main()
{
long long a,b;
scanf("%lld%lld",&a,&b);
vector< pair<long long,long long> > n=take(a+b),m=take(a),k=take(b);
long long mini=(a+b+1)*2;
for(auto p:n)
    for(auto q:m)
    if(p.first>=q.first&&p.second>=q.second)
    {
        mini=min(mini,(p.first+p.second)*2);
    }
for(auto p:n)
    for(auto q:k)
    if(p.first>=q.first&&p.second>=q.second)
    {
        mini=min(mini,(p.first+p.second)*2);
    }

printf("%lld\n",mini);
return 0;
}