#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
typedef long long ll;

const int max_n = 100005;
int n;
int l[max_n], r[max_n];

int main()
{
    cin>>n;
    int kl=0, kr = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>l[i]>>r[i];
        kl+=l[i];
        kr+=r[i];
    }
    int maxb = abs(kl - kr);
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        int kl1 = kl - l[i] + r[i];
        int kr1 = kr - r[i] + l[i];
        if (abs(kl1 - kr1) > maxb)
        {
            maxb = abs(kl1 - kr1);
            ans = i;
        }
    }
    cout<<ans+1;
    return 0;
}