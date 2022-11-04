#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define mid ((l + r) >> 1)
int n;
vector<pair<int, int>> v;

void find(int l, int r){
    if(l+1 == r){
        v.push_back({l, r});
        return;
    }

    find(l, mid);
    find(mid+1, r);

    for(int i=l;i<=mid;i++){
        v.push_back({i, i+(mid-l+1)});
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;

    if(n <= 2){
        cout << 0;
        return 0;
    }

    int k = 1;
    while(k * 2 < n) k *= 2;

    find(1, k);
    find(n-k+1, n);

    cout << v.size() << "\n";
    for(auto [x, y] : v) cout << x << " " << y << "\n";
}