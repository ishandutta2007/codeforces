#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool chk(int s){
    for(int i=2;i*i<=s && i<s;i++) if(s % i == 0) return true;
    return false;
}

int n, a[111];

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    int s = 0;
    for(int i=1;i<=n;i++) s += a[i];

    if(chk(s)){
        cout << n << "\n";
        for(int i=1;i<=n;i++) cout << i << " ";
        return;
    }

    cout << n-1 << "\n";

    bool flag = 0;
    for(int i=1;i<=n;i++){
        if(!flag && chk(s - a[i])){
            flag = 1;
        }else{
            cout << i << " ";
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}