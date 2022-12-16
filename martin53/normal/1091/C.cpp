#include<bits/stdc++.h>
using namespace std;
int n;
set<long long> output;
void run(int step)
{
    long long k=(n-1)/step;
    long long now=(k+1)+step*k*(k+1)/2;
    output.insert(now);
}
int main()
{
cin>>n;
for(int i=1;i*i<=n;i++)
    if(n%i==0)
    {
        run(i);
        run(n/i);
    }

for(auto k:output)
    printf("%lld ",k);
return 0;
}