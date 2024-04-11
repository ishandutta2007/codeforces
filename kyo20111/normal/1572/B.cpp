#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[200200];

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    int flag = -1, cnt = 0;
    for(int i=1;i<=n;i++){
        if(!a[i]) flag = i;
        else cnt++;
    }

    if(cnt == 0){
        cout << "YES\n0";
        return;
    }

    if(cnt%2 || cnt == n){
        cout << "NO";
        return;
    }

    int L = 1;
    while(!a[L]) L++;

    vector<int> ans;

    while(L+2 <= n){
        int R = L;

        while(R+2 <= n){
            int c = a[R] + a[R+1] + a[R+2];

            if(c == 2) break;
            if(c == 1) a[R] = a[R+1] = a[R+2] = 1, ans.push_back(R);

            R += 2;
        }

        if(R+2 > n) break;

        for(int i=R;i>=L;i-=2){
            a[i] = a[i+1] = a[i+2] = 0;
            ans.push_back(i);
        }

        L = R;
        while(L < n && !a[L]) L++;
    }

    for(int i=1;i<=n-2;i++) if(a[i] + a[i+1] + a[i+2] == 2){
        a[i] = a[i+1] = a[i+2] = 0;
        ans.push_back(i);
    }

    for(int i=1;i<=n;i++) if(a[i]){
        cout << "NO";
        return;
    }

    cout << "YES\n";
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x << " ";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}