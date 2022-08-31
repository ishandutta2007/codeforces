#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <bitset>
#include <cstdlib>

typedef long long ll;
typedef long double ld;

using namespace std;

const int MAX_N=301000;



typedef pair<int,int> pii;

int n,p;

map<pii,ll> mm;

ll rr[MAX_N];

ll arr[MAX_N];
ll arr2[MAX_N];


int main()
{
    ios_base::sync_with_stdio(false);

    cin>>n>>p;
    for (int i=1;i<=n;++i)
    {
        int a,b;
        cin>>a>>b;
        if (a>b)
            swap(a,b);
        ++rr[a];
        ++rr[b];
        ++mm[pii(a,b)];
    }

    for (int i=1;i<=n;++i)
        ++arr2[rr[i]];
    arr[n]=arr2[n];
    for (int i=n-1;i>=0;--i)
        arr[i]=arr[i+1]+arr2[i];


    ll ans=0;
    for (int i=1;i<=n;++i)
    {
        int x=max((ll)0,p-rr[i]);
        if (rr[i]<x)
            ans+=arr[x];
        else
            ans+=arr[x]-1;
    }
    ans/=2;
    for (pair<pii,ll> i:mm)
    {
        int a=i.first.first;
        int b=i.first.second;
        if (rr[a]+rr[b]>=p && rr[a]+rr[b]-i.second<p)
            --ans;
    }

    cout<<ans;

    return 0;
}