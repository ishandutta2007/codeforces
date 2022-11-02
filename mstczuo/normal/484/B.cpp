# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

const int N = 2000000;
int M = 0;
int a[N + 10];
int main() {
    int n, x; cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> x; a[x] = x;
        M = max(M, x);
    }
    for(int i = 1; i <= M; ++i)
        if(a[i] == 0) a[i] = a[i - 1];
    
    int ans = 0;
    for(int i = 1; i <= M; ++i) if(a[i] == i){
        ans = max(ans, M % i);
        for(int j = i * 2 - 1; j <= M; j += i) {
            ans = max(ans, a[j] % i);
        }
    }
    cout << ans << endl;
}