#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,inp[nmax];
void print(vector<long long> out)
{
    printf("%i\n",out.size());
    for(auto k:out)
    {
        printf("%lld ",k);
    }
    printf("\n");
}
void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    long long sum=0,x=0;
    for(int i=1;i<=n;i++)
    {
        sum=sum+inp[i];
        x=x^inp[i];
    }

    vector<long long> out={x};
    sum=sum+x;
    x=x^x;

    out.push_back(sum);
    x=x^sum;
    sum=sum+sum;

    assert(sum==2*x);
    print(out);
}
int main()
{
    int t;
    scanf("%i",&t);
    while(t)
    {
        solve();
        t--;
    }
    return 0;
}