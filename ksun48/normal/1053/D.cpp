#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    
    vector<int> used(n, 0);
    
    vector<vector<pair<int,int> > > pfact(n);
    
    map<int,int> f;
    map<int,int> ffreq;
    
    for(int i = 0; i < n; i++){
        if(f[a[i]] == 0){
            f[a[i]] = 1;
            used[i] = 1;
            ffreq[a[i]] = 1;
        } else {
            a[i]--;
            for(int p = 2; p * p <= a[i]; p++){
                if(a[i] % p == 0){
                    int k = 0;
                    while(a[i] % p == 0){
                        a[i] /= p;
                        k++;
                    }
                    pfact[i].push_back({p, k});
                    if(k > f[p]){
                        f[p] = k;
                        ffreq[p] = 0;
                    }
                    if(k == f[p]){
                        ffreq[p]++;
                    }
                }
            }
            if(a[i] > 1){
                int p = a[i];
                int k = 1;
                pfact[i].push_back({p, k});
                if(k > f[p]){
                    f[p] = k;
                    ffreq[p] = 0;
                }
                if(k == f[p]){
                    ffreq[p]++;
                }
            }
        }
    }
    const LL MOD = 1000000007;
    LL num = 1;
    for(auto x : f){
        for(int j = 0; j < x.second; j++){
            num = (num * (LL) x.first) % MOD;
        }
    }
    int ok = 0;
    for(int i = 0; i < n; i++){
        if(!used[i]){
            int can_delete = 1;
            for(pair<int,int> x : pfact[i]){
                int p = x.first;
                int k = x.second;
                if(f[p] == k && ffreq[p] == 1){
                    can_delete = 0;
                }
            }
            if(can_delete == 1) ok = 1;
        }
    }
    num = (num + ok) % MOD;
    cout << num << '\n';
}