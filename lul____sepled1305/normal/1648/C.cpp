//
// Created by Nitit Jongsawatsataporn on 16/3/2022 AD.
//
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 998244353;

int add(int a,int b) {
    return (a+b)%mod;
}

int mul(int a,int b) {
    ll g = (1LL*a*b)%mod;
    return (int) g;
}

int pow(int b, int p) {
    if(p == 0) return 1;
    int g = pow(b,p/2);
    g = mul(g,g);
    if(p&1) g = mul(g,b);
    return g;
}

int inv(int b) {
    return pow(b,mod-2);
}

int fac(int n) {
    if(n == 0) return 1;
    return mul(n,fac(n-1));
}

const int N = 2e5+10;

struct fenwick {
    int bit[N];

    fenwick() {
        for(int i=0;i<N;i++) bit[i] = 0;
    }

    void upt(int idx, int v) {
        for(;idx < N;idx = (idx | (idx+1)))
            bit[idx] += v;
    }

    int sum(int r) {
        int cur = 0;
        for(;r >= 0;r = (r&(r+1))-1)
            cur = add(cur,bit[r]);
        return cur;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l-1);
    }
};

int main() {
    int n,m; cin>>n>>m;
    int a[n], b[m];
    map<int,int> ct;
    fenwick tree = fenwick();
    for(int i=0;i<n;i++)
        cin>>a[i], ct[a[i]]++;
    for(int i=0;i<m;i++)
        cin>>b[i];
    //Make a compress array of a
    vector<int> v;
    for(auto it: ct)
        v.push_back(it.first);
    //Make fenwick tree out of this
    for(auto it: v) {
        tree.upt(it,ct[it]);
    }
    //cout<<tree.sum(2)<<' '<<tree.sum(1)<<endl;
    //cout<<fac(10)<<endl;
    //Now let's compute the multiplication factor.
    int factor = 1;
    factor = fac(n);
    for(auto it: v) {
        factor = mul(factor,inv(fac(ct[it])));
    }
    //cout<<factor<<endl;
    //Compute ans
    int ans = 0;
    for(int i=0;i<max(m,n);i++) {
        //cout<<i<<endl;
        if(i == m) {
            break;
        }
        if(i == n) {
            ans = add(ans, 1);
            break;
        }
        if(ct.count(b[i]) == 0 || ct[b[i]] == 0) {
            //Last turn!
            ans = add(ans,mul(mul(factor,inv(n-i)),tree.sum(b[i]-1)));
            break;
        }
        else {
            //Continue
            //Case 1: we do not use the ct
            ans = add(ans,mul(mul(factor,inv(n-i)),tree.sum(b[i]-1)));
            //cout<<factor<<' '<<n-i<<' '<<inv(n-i)<<' '<<tree.sum(b[i]-1)<<endl;
            factor = mul(factor,mul(inv(n-i),ct[b[i]]));
            //cout<<"F "<<factor<<' '<<n-i<<' '<<inv(n-i)<<' '<<tree.sum(b[i]-1)<<endl;
            ct[b[i]]--;
            tree.upt(b[i],-1);
        }
        //cout<<ans<<endl;
    }
    cout<<ans;
    return 0;
}