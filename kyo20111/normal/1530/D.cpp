#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[200200], b[200200], c[200200], p[200200], t[200200], r[200200];

int find(int a){
    if(a == p[a]) return a;
    return p[a] = find(p[a]);
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) r[i] = b[i] = c[i] = 0, p[i] = t[i] = i;

    for(int i=1;i<=n;i++){ // i -> a[i]
        int A = find(i), B = find(a[i]);

        if(c[B]){ // a[i]     (i    )
            int P = r[a[i]];
            b[i] = a[i], r[a[i]] = i;
            b[P] = t[A], r[t[A]] = P;
            p[A] = B;
        }else if(A == B){ //  
            c[A] = 1;
            if(a[i] == t[A] || a[r[a[i]]] == a[i]){
                b[i] = t[A], r[t[A]] = i; // head -> tail
            }else{
                int P = r[a[i]];
                // r[a[P]] -> t[A]
                // P -> a[P]
                // i -> a[i]

                b[r[a[P]]] = t[A], r[t[A]] = r[a[P]];
                b[P] = a[P], r[a[P]] = P;
                b[i] = a[i], r[a[i]] = i;
            }
        }else if(t[B] == a[i]){
            b[i] = a[i], r[a[i]] = i;
            t[B] = t[A], p[A] = B;
        }else{ //    
            int P = r[a[i]];
            b[P] = t[A], r[t[A]] = P;
            b[i] = a[i], r[a[i]] = i;
            p[A] = B;
        }
    }

    for(int i=1;i<=n;i++) assert(i == b[r[i]]);

    int k = 0;
    for(int i=1;i<=n;i++) k += b[i] == a[i];

    vector<int> chk(n+1);
    for(int i=1;i<=n;i++) chk[a[i]] = 1;
    int sum = 0;
    for(int i=1;i<=n;i++) sum += chk[i];
    if(k != sum){
        while(1){
        }
    }

    cout << k << "\n";
    for(int i=1;i<=n;i++) cout << b[i] << " ";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}