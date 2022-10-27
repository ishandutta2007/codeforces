#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 5e5 + 100;
const int mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <int> a(n);
        int x  = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            x ^= a[i];
        }
        if(x == 1){
            cout << "NO\n";
            continue;
        }
        vector <int> ans;
        int cntlast = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == 0 && a[i - 1] == 0 && cntlast % 2 == 1){
                ans.push_back(i - 2);
                a[i] = a[i - 1] = 1;
                cntlast += 2;
            }
            else if(a[i] == 0 && cntlast > 0 && cntlast % 2 == 0){
                int j = i - 2;
                while(cntlast){
                    ans.push_back(j);
                    a[j] = a[j + 1] = 0;
                    j -= 2;
                    cntlast -= 2;
                }
            }
            else if(a[i] == 1 && i != 0 && a[i - 1] == 0){
                if(cntlast % 2 == 1){
                    ans.push_back(i - 2);
                    a[i - 2] = a[i] = 0;
                    cntlast--;
                    int j = i - 4;
                    while(cntlast > 0){
                        ans.push_back(j);
                        a[j] = a[j + 1] =0;
                        j -= 2;
                        cntlast -= 2;
                    }
                }
                else{
                    cntlast++;
                }
            }
            else if(a[i] == 1){
                cntlast++;
            }
        }
        if(cntlast % 2 == 1){
            cout << "NO\n";
            continue;
        }
        for(int i = 0; i + 2 < n; i++){
            if(a[i] == 0 && a[i + 1] == 1 && a[i + 2] == 1){
                ans.push_back(i);
                a[i + 1] = a[i + 2] = 0;
            }
        }
        for(int i = n - 1; i >= 2; i--){
            if(a[i] == 0 && a[i - 1] == 1 && a[i - 2] == 1){
                ans.push_back(i - 2);
                a[i - 1] = a[i - 2] = 0;
            }
        }
        bool fl = 0;
        for(int i = 0; i < n; i++){
            if(a[i]){
                fl = 1;
            }
        }
        if(fl){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        cout << sz(ans) << "\n";
        for(auto i : ans){
            cout << i + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}