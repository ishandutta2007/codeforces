/**Nephren is the best girl**/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int MOD = 1e9+7;
const int chtholly = 0;
int T;

int GCD(int a,int b)
{
    if(a>b)
        swap(a,b);
    if(a==0)
        return b;
    if(b%a==0)
        return a;
    else
        return GCD(b%a,a);
}

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/

    cin>>T;
    while(T--)
    {
        int m,d,w;
        cin>>m>>d>>w;
        int gc = GCD(w,d-1);
        w/=gc;
        int mi = min(m,d);
        if(mi==1)
        {
            cout<<"0\n";
            continue;
        }
        int val = mi/w;
        int left = mi%w;
        long long ans = 0;
        ans = (1LL*w*val*(val-1))/2;
        ans += 1LL*val*left;
        cout<<ans<<"\n";
    }
    return chtholly;
}

/**
    I lied. Ithea is better than Nephren.
    JK
**/