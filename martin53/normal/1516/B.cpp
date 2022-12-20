#include<bits/stdc++.h>
using namespace std;

const int nmax=2e3+42;

int n,inp[nmax];

int pref[nmax];

bool test(int val)
{
    //cout<<"test "<<val<<endl;

    int prv=0;
    for(int i=1;i<=n;i++)
    {
        if(prv&&(pref[n]^pref[prv])==val)return 1;

        if((pref[i]^pref[prv])==val)prv=i;
    }
    return prv==n;
}
void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)pref[i]=pref[i-1]^inp[i];

    for(int i=1;i<n;i++)
        if(test(pref[i]))
        {
            printf("YES\n");
            return;
        }
    printf("NO\n");
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}