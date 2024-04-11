# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    cout << 6 * k * n - k << endl;
    int num = 0;
    for(int i = 0; i < n; ++i) {
        ++num;
        cout << num*k << ' ';
        ++num;
        cout << num*k << ' ';
        ++num;
        cout << num*k << ' ';
        ++num;
        ++num;
        cout << num*k << endl;
        ++num;
    }
}