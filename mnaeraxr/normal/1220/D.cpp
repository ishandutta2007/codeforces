#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

int64 gcd(int64 a, int64 b){
    while (b){
        int64 t = b;
        b = a % b;
        a = t;
    }

    return a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int64 g = 0;

    vector<vector<int64>> buck(60);

    for (int i = 0; i < n; ++i){
        int64 v; cin >> v;
        int64 u = v;
        int t = 0;

        while (u % 2 == 0){
            u >>= 1;
            t++;
        }

        buck[t].push_back(v);
    }

    int x = 0;

    for (int i = 1; i < 60; ++i){
        if (buck[i].size() > buck[x].size()){
            x = i;
        }
    }

    vector<int64> answer;

    for (int i = 0; i < 60; ++i){
        if (i == x) continue;

        for (auto v : buck[i])
            answer.push_back(v);
    }

    cout << answer.size() << endl;
    for (auto x : answer){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}