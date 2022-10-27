#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long

using namespace std;

const int N = 1e5 + 100;
const int T = 350;
const int mod = 998244353;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool fl = 1;
        vector <int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i]--;
            if(a[i] % 2 != i % 2){
                fl = 0;
            }
        }
        if(!fl){
            cout << -1 << "\n";
            continue;
        }
        vector <int> ans;
        for(int i = n - 1; i > 0; i -= 2){
            if(a[i] == i && a[i - 1] == i - 1){
                continue;
            }
            for(int j = 0; j <= i; j++){
                if(a[j] == i){
                    ans.push_back(j + 1);
                    for(int k = 1; k <= (j + 1) / 2; k++){
                        swap(a[k - 1], a[j - k + 1]);
                    }
                    break;
                }
            }
            for(int j = 0; j <= i; j++){
                if(a[j] == i - 1){
                    ans.push_back(j);
                    for(int k = 1; k <= j / 2; k++){
                        swap(a[k - 1], a[j - k]);
                    }
                    break;
                }
            }
            for(int j = 0; j <= i; j++){
                if(a[j] == i - 1){
                    ans.push_back(j + 2);
                    for(int k = 1; k <= (j + 2) / 2; k++){
                        swap(a[k - 1], a[j + 1 - k + 1]);
                    }
                    break;
                }
            }
            ans.push_back(3);
            swap(a[0], a[2]);
            ans.push_back(i + 1);
            for(int k = 1; k <= (i + 1) / 2; k++){
                swap(a[k - 1], a[i - k + 1]);
            }
        }
        cout << sz(ans) << "\n";
        for(auto v : ans){
            cout << v << " ";
        }
        cout << "\n";
    }
    return 0;
}