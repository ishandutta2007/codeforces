#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define int long long
#define ll long long
#define sz(a) (int)a.size()
const ll mod = 1e9 + 7;
const ll mod2 = 1e9 + 7;
const int K = 1e7;
const int N = 1e6 + 1;
const int T = 350;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int allc = 0;
    vector <int> min_val1(T, 1e9), min_val2(T, 1e9);
    vector <int> pref_a(n + 1), pref_b(n + 1), pref_c(n + 1);
    for(int i = 0; i < n; i++){
        pref_a[i + 1] = pref_a[i] + (s[i] == 'a');
        pref_b[i + 1] = pref_b[i] + (s[i] == 'b');
        pref_c[i + 1] = pref_c[i] + (s[i] == 'c');
    }
    allc = pref_c[n];
    vector <int> ans(T, 1e9);
    for(int i = 0; i < T; i++){
        int left = i * T;
        int right = min(n, i * T + T - 1);
        int val1 = 1e9;
        for(int j = left; j <= right; j++){
            val1 = min(val1, pref_a[j] - pref_b[j]);
            min_val1[i] = min(min_val1[i], pref_b[j] - pref_c[j]);
            min_val2[i] = min(min_val2[i], pref_a[j] - pref_b[j]);
            ans[i] = min(ans[i], val1 + pref_b[j] - pref_c[j]);
        }
    }
    vector <int> upd_pref_a(T), upd_pref_b(T), upd_pref_c(T);
    for(int i = 0; i < q; i++){
        int idx;
        cin >> idx;
        char t;
        cin >> t;
        idx--;
        char prev = s[idx];
        allc -= (prev == 'c');
        s[idx] = t;
        allc += (t == 'c');
        int block = (idx + 1) / T;
        int left_block = block * T;
        int right_block = min(n, left_block + T - 1);
      //  cout << left_block << " " << right_block << "\n";
        int a = 0, b = 0,c = 0;
        if (left_block) {
            a += pref_a[left_block - 1];
            b += pref_b[left_block - 1];
            c += pref_c[left_block - 1];
        }
        ans[block] = 1e9;
        int val1 = 1e9;
        min_val1[block] = min_val2[block] = 1e9;
        for(int j = left_block; j <= right_block; j++){
            if (j != 0) {
                a = a + (s[j - 1] == 'a');
                b = b + (s[j - 1] == 'b');
                c = c + (s[j - 1] == 'c');
            }
            val1 = min(val1, a - b); 
            ans[block] = min(ans[block], val1 + b - c);
            min_val1[block] = min(min_val1[block], b - c);
            min_val2[block] = min(min_val2[block], a - b);
        }
        for(int j = block + 1; j < T; j++){
            upd_pref_a[j] -= (prev == 'a');
            upd_pref_a[j] += (t == 'a');
            upd_pref_b[j] -= (prev == 'b');
            upd_pref_b[j] += (t == 'b');
            upd_pref_c[j] -= (prev == 'c');
            upd_pref_c[j] += (t == 'c');
        }
        int curval = 1e9;
        int curans = 1e9;
        for(int j = 0; j < T; j++){
            curans = min(curans, min_val1[j] + upd_pref_b[j] - upd_pref_c[j] + curval);
            curval = min(curval, min_val2[j] + upd_pref_a[j] - upd_pref_b[j]);
    //        cout << curval << " ";
            curans = min(curans, ans[j] + upd_pref_a[j] - upd_pref_c[j]);
         //   cout << curans + allc << " ";
        }
     //   cout << ans[0] << " " << allc << " ";
        cout << curans + allc << "\n";
    }   
    return 0;
}