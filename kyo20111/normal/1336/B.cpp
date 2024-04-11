#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t, a, b, c, l, r;
ll f(ll k){
    return k * k;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&a,&b,&c);
        vector<ll> va, vb, vc;
        for(int i=1;i<=a;i++){
            ll d; scanf("%lld",&d);
            va.push_back(d);
        }
        for(int i=1;i<=b;i++){
            ll d; scanf("%lld",&d);
            vb.push_back(d);
        }
        for(int i=1;i<=c;i++){
            ll d; scanf("%lld",&d);
            vc.push_back(d);
        }
        sort(va.begin(), va.end());
        sort(vb.begin(), vb.end());
        sort(vc.begin(), vc.end());

        ll mn = LLONG_MAX;

        l = 0, r = 0;
        while(l < a){
            int m = lower_bound(vc.begin(), vc.end(), (va[l] + vb[r]) / 2) - vc.begin();

            for(int i=m-10;i<=m+10;i++){
                if(i < 0 || c <= i) continue;
                mn = min(mn, f(va[l] - vb[r]) + f(va[l] - vc[i]) + f(vb[r] - vc[i]));
            }

            if(r < b-1 && (l >= a-1 || va[l] > vb[r] || (va[l] == vb[r] && va[l+1] > vb[r+1]))) r++;
            else l++;
        }

        l = 0, r = 0;
        while(l < a){
            int m = lower_bound(vb.begin(), vb.end(), (va[l] + vc[r]) / 2) - vb.begin();

            for(int i=m-10;i<=m+10;i++){
                if(i < 0 || b <= i) continue;
                mn = min(mn, f(va[l] - vc[r]) + f(va[l] - vb[i]) + f(vc[r] - vb[i]));
            }

            if(r < c-1 && (l == a-1 || va[l] > vc[r] || (va[l] == vc[r] && va[l+1] > vc[r+1]))) r++;
            else l++;
        }


        l = 0, r = 0;
        while(l < c){
            int m = lower_bound(va.begin(), va.end(), (vc[l] + vb[r]) / 2) - va.begin();

            for(int i=m-10;i<=m+10;i++){
                if(i < 0 || a <= i) continue;
                mn = min(mn, f(vc[l] - vb[r]) + f(vc[l] - va[i]) + f(vb[r] - va[i]));
            }

            if(r < b-1 && (l == c-1 || vc[l] > vb[r] || (vc[l] == vb[r] && vc[l+1] > vb[r+1]))) r++;
            else l++;
        }

        printf("%lld\n",mn);
    }
}