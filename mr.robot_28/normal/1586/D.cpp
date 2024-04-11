#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 5e5 + 100;
const int mod = 1e9 + 7;

signed main() {
//    ios_base::sync_with_stdio(0);
  //  cin.tie(0);
    //cout.tie(0);
    int n;
    cin >> n;
    vector <int> ans(n, 0);
    for(int i = 0; i < n - 1; i++){
        cout << "? ";
        for(int j = 0; j < n - 1; j++){
            cout << i + 2 << " ";
        }
        cout << 1 << " ";
        cout << endl;
        int k;
        cin >> k;
        if(k == 0){
            break;
        }
        else{
            ans[k - 1] = -(i + 1);
        }
    }
    for(int i = 0; i < n - 1; i++){
        cout << "? ";
        for(int j = 0; j < n - 1; j++){
            cout << 1 << " ";
        }
        cout << i + 2 << " ";
        cout << endl;
        int k;
        cin >> k;
        if(k == 0){
            break;
        }
        ans[k - 1] = i + 1;
    }
    int mina = 0;
    for(int i = 0; i < n; i++){
        mina = min(mina, ans[i]);
    }
    cout << "! ";
    for(int i =0 ; i < n; i++){
        cout << ans[i] - mina + 1 << " ";
    }
    cout << endl;
    return 0;
}