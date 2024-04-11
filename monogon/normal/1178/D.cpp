
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1005;
int n;
vector<int> adj[N];

bool isPrime(int x) {
    if(x == 2 || x == 3) {
        return true;
    }
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        adj[i].push_back((i + 1) % n);
    }
    int k = n;
    int idx = 0;
    while(true) {
        if(isPrime(k)) break;
        adj[idx].push_back((idx + 2) % n);
        idx++;
        k++;
        if(isPrime(k)) break;
        adj[idx].push_back((idx + 2) % n);
        idx += 3;
        k++;
    }
    cout << k << endl;
    for(int i = 0; i < n; i++) {
        for(int j : adj[i]) {
            cout << (i + 1) << " " << (j + 1) << endl;
        }
    }
}