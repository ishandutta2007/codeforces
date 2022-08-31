#include <bits/stdc++.h>
using namespace std;
#define forn(i,x,n) for(int i = x; i < n; ++i)
typedef long long ll;

vector<ll> a;
unordered_map<ll,int> ml, mr;

ll gcd(ll a, ll b) {
    return b? gcd(b,a%b): a;
}

int calc(int l, int r){

    if(l==r)
        return a[l]!=1;

    int mid = (l+r)/2, ans = max(calc(l, mid), calc(mid+1, r));

    ml.clear(), mr.clear();

    ll gc = 0, i = mid;

    while(i >= l){
        gc = gcd(gc, a[i]);
        if(gc > 1)
            ml[gc] = i;
        else
            break;
        i--;
    }

    gc = 0, i = mid + 1;

    while(i <= r){
        gc = gcd(gc, a[i]);
        if(gc > 1)
            mr[gc] = i;
        else
            break;
        i++;
    }

    for(auto [y, i]: mr)
        for(auto [x, j]: ml)
            if(gcd(y, x) > 1 && ans < i-j+1)
                ans = i-j+1;
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    cin>>t;

    while(t--){
        cin>>n;
        a.assign(n,0);
        forn(i,0,n)
            cin>>a[i];
        if (n == 1) { cout << "1\n"; continue; }
        n--;
        forn(i,0,n)
            a[i]=abs(a[i]-a[i+1]);

        cout<<calc(0,n-1) + 1<<'\n';
    }
    return 0;
}