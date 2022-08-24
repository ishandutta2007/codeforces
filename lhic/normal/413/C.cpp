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

int n,m;

bool bd[1000];

ll arr[1000];

int main()
{
    ios_base::sync_with_stdio(false);


    cin>>n>>m;

    for (int i=0;i<n;++i)
        cin>>arr[i];
    for (int i=0;i<m;++i)
    {
        int a;
        cin>>a;
        --a;
        bd[a]=true;
    }
    ll now=0;
    vector<ll> vv;
    for (int i=0;i<n;++i)
    {
        if (!bd[i])
            now+=arr[i];
        else
            vv.push_back(arr[i]);
    }
    sort(vv.begin(),vv.end());
    reverse(vv.begin(),vv.end());
    for (int i=0;i<vv.size();++i)
        now+=max(now,vv[i]);
    cout<<now;
    return 0;
}