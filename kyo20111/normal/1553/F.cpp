#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 300000;
int n;

ll t1[300300]; // x  a[i] 

ll t2[300300]; // x  a[i] 

ll t3[300300]; // x  a[i] 
ll t4[300300]; // for(int i=k;i<=N;i+=k) update(i, N, k);

ll t5[300300], t6[300300];
ll t7[300300]; // r[x]  r[a[i]] 


ll ans;

void update(ll t[], int bit, int val){
    while(bit <= N) t[bit] += val, bit += bit & -bit;
}
ll find(ll t[], int bit){
    ll re = 0;
    while(bit) re += t[bit], bit -= bit & -bit;
    return re;
}
ll find(ll t[], int l, int r){
    return find(t, r) - find(t, l-1);
}


void update2(ll t[], int bit, int val){
    while(bit <= N) t[bit] += val, bit += bit & -bit;
}
ll find2(ll t[], int bit){
    ll re = 0;
    while(bit) re += t[bit], bit -= bit & -bit;
    return re;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        int x; cin >> x;

        ans += find(t1, 1, x); // OK

        ans += x * find(t2, x, N); // OK

        ans += x * find(t3, 1, x) - find(t4, 1, x);
        // cout << find(t3, 1, x) << " " << find(t4, 1, x) << "\n";

        int r = N - x + 1;
        ans += r * find2(t5, r) - find2(t6, r); // OK
        for(int i=r-x;i>=1;i-=x) ans -= find(t7, 1, i) * x;


        update(t1, x, x);

        update(t2, x, 1);

        update(t3, x, 1);
        for(int i=x;i<=N;i+=x) update(t4, i, x);

        update2(t5, r+1, 1);
        update2(t6, r+1, r);
        update(t7, r, 1);

        cout << ans << " ";
    }
}