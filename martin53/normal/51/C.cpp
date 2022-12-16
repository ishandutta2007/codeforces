#include<bits/stdc++.h>
#define int long long
using namespace std;
const int nmax=2e5+42;
int n,x[nmax];
vector<int> test(int now)
{
    int where=-(now+1);
    vector<int> ret={};
    for(int i=1;i<=n;i++)
        if(where+now<x[i])
        {
            ret.push_back(x[i]+now);
            where=x[i]+now;
        }
    return ret;
}
signed main()
{
scanf("%lld",&n);
for(int i=1;i<=n;i++)
{
    scanf("%lld",&x[i]);
    x[i]=x[i]*2;
}
sort(x+1,x+n+1);
int ok=1e9,not_ok=-1;
while(ok-not_ok>1)
{
    int av=(ok+not_ok)/2;
    if(test(av).size()<=3)ok=av;
    else not_ok=av;
}

vector<int> h=test(ok);
while(h.size()<3)h.push_back(0);

printf("%.9f\n",ok/2.0);
for(auto k:h)printf("%.9f ",k/2.0);
printf("\n");
return 0;
}