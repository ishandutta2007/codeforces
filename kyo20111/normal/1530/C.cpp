#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[100100], b[100100];

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];

    priority_queue<int, vector<int>, greater<int>> A, B;
    priority_queue<int> pB;

    ll sa = 0, sb = 0;
    for(int i=1;i<=n;i++) A.push(a[i]), B.push(b[i]), sa += a[i], sb += b[i];
    for(int i=4;i<=n;i+=4) sa -= A.top(), sb -= B.top(), pB.push(B.top()), A.pop(), B.pop();

    int k = n;
    while(sa < sb){
        A.push(100), sa += 100;
        if(!pB.empty()){
            B.push(pB.top()), sb += pB.top(), pB.pop();
            pB.push(0);
        }else{
            B.push(0);
        }
        if(++k % 4 == 0) sa -= A.top(), sb -= B.top(), pB.push(B.top()), A.pop(), B.pop();
    }

    cout << k - n;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}