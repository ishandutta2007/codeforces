# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

void perm(int n) {
    int l = 1, r = n, k = n;
    bool flag = true;
    while(k -- ) {
        if(flag) cout << l++ << ' ';
        else cout << r-- << ' ';
        flag = !flag;
    }
}

int main() {
    int k, n;
    cin >> n >> k;
    perm(k + 1);
    for(int i = k + 2; i <= n; ++i)
        cout << i << ' ';
    cout << endl;
}