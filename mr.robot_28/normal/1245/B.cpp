#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll rPow(ll n, ll k) {
    if (k <= 0) return 1;
    return n * rPow(n, --k);
}
int a[3];
 
int main() {
  //  freopen("in.txt", "r", stdin);
    //  freopen("outt.txt", "w  ", stdout);
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
 
    int q;
    cin>>q;
    while (q--) {
        int n;
        cin>>n;
        for (int i = 0; i < 3; i++) {
            cin >> a[i];
        }
        string s;
        cin>>s;
        int cntR = 0, cntS = 0, cntP = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') {
                cntR++;
            } else if (s[i] == 'P') {
                cntP++;
            } else
                cntS++;
        }
        int cnt = min(cntR, a[1]) + min(cntP, a[2]) + min(cntS, a[0]);
        int val = n / 2;
        if (n % 2 != 0) val++;
        if (cnt < val) {
            cout << "NO" << endl;
            continue;
        }
        char ans[n];
        for (int i = 0; i < n; i++)
            ans[i] = '0';
 
        //  for (int i = 0; i < n; i++)
        //    cout<<ans[i]<<endl;
        int i = 0;
        while (i < n) {
            if (s[i] == 'S' && ans[i] == '0') {
                if (a[0] > 0) {
                    ans[i] = 'R';
                    a[0]--;
                }
            }
            if (a[0] == 0) break;
            i++;
        }
        i = 0;
        while (i < n) {
            if (s[i] == 'R' && ans[i] == '0') {
                if (a[1] > 0) {
                    ans[i] = 'P';
                    a[1]--;
                }
            }
            if (a[1] == 0) break;
            i++;
        }
        i = 0;
        while (i < n) {
            if (s[i] == 'P' && ans[i] == '0') {
                if (a[2] > 0) {
                    ans[i] = 'S';
                    a[2]--;
                }
            }
            if (a[2] == 0) break;
            i++;
        }
       // for (int i = 0; i<n; i++)
         //   cout << ans[i] << endl;
        for (int i = 0; i < n; i++) {
            if (ans[i] == '0') {
                if (s[i] == 'R') {
                    if (a[0] > 0) {
                        ans[i] = 'R';
                        a[0]--;
                    } else if (a[2] > 0) {
                        ans[i] = 'S';
                        a[2]--;
                    }
                } else if (s[i] == 'P') {
                    if (a[1] > 0) {
                        ans[i] = 'P';
                        a[1]--;
                    } else if (a[0] > 0) {
                        ans[i] = 'R';
                        a[0]--;
                    }
                }
                else{
                    if (a[2] > 0) {
                        ans[i] = 'S';
                        a[2]--;
                    } else if (a[1] > 0) {
                        ans[i] = 'P';
                        a[1]--;
                    }
                    
                }
            }
        }
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << ans[i];
        }
        cout << endl;
 
    }
 
 
    return 0;
}