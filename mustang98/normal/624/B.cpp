#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

ll m[100];

int main()
{
    ll n, res=0;
    cin>>n;
    for (int i=0;i<n;i++) cin>>m[i];
    //sort(m, m+n);
    for (int i=0;i<n;i++)
    {
        m1:
        if (m[i]==0) continue;
        for (int j=0;j<n;j++)
        {
            if (j==i) continue;
            if (m[i]==m[j]) {m[i]--; goto m1;}
        }
    }
    for (int i=0;i<n;i++) res+=m[i];
    cout<<res;
    return 0;
}