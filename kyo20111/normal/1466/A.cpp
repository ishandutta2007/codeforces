#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[500];

void solve_tc(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    set<int> s;
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) s.insert(a[j] - a[i]);
    cout << s.size();
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    int tc = 1;
    cin >> tc;

    while(tc--){
        solve_tc();
        cout << "\n";
    }
}