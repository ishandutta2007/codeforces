#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define mod (ll(1e9+7))
#define MAXN 100005

ll f[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    f[0]=1;
    f[1]=1;
    f[2]=2;
    for(int i=3;i<MAXN;i++)
        f[i]=(f[i-1]+f[i-2])%mod;

    string s;
    cin >> s;
    ll res=1,sz=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='m' || s[i]=='w')
            res=0;
        if(i && s[i]!=s[i-1] && (s[i-1]=='n' || s[i-1]=='u'))
            res=(res*f[sz])%mod;
        if(i && s[i]!=s[i-1])
            sz=0;
        sz++;
    }
    if(s[s.size()-1]=='n' || s[s.size()-1]=='u')
        res=(res*f[sz])%mod;
    db(res)

    return 0;
}