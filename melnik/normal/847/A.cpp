#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second

const int N = 1e5 + 10;

int n;
int r[N], l[N], used[N];

void dfs(int v) {
    used[v] = 1;
    if(r[v] == 0) {
        for(int i = 1; i <= n; i++) {
            if(l[i] == 0 && !used[i]) {
                l[i] = v;
                r[v] = i;
                dfs(v);
                break;
            }
        }
    } else {
        dfs(r[v]);
    }
}

int main() {
//    ifstream cin( "input.txt" );
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    for(int i = 1; i <= n; i++) {
        if(l[i] == 0) {
            dfs(i);
            break;
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << l[i] << ' ' << r[i] << endl;
    }
}