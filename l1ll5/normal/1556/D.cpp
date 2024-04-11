#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 100000 + 5;
int ask_and(int i, int j) {
    cout << "and " << i << ' ' << j << endl;
    int x;
    cin >> x;
    return x;
}
int ask_or(int i, int j) {
    cout << "or " << i << ' ' << j << endl;
    int x;
    cin >> x;
    return x;
}
int main() {
    int t = 1;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        int a_and_b = ask_and(1, 2);
        int a_or_b = ask_or(1, 2);
        int a_and_c = ask_and(1, 3);
        int a_or_c = ask_or(1, 3);
        int b_and_c = ask_and(2, 3);
        int b_or_c = ask_or(2, 3);
        for (int i = 31; i >= 0; i -= 1) {
            if ((a_and_b >> i) & 1) {
                // a = b = 1
                a[0] ^= (1 << i);
                a[1] ^= (1 << i);
                if ((a_and_c >> i) & 1) {
                    //c = 1
                    a[2] ^= (1 << i);
                }
                continue;
            }
            if (((a_or_b >> i) & 1) == 0) {
                // a = b = 0
                if ((a_or_c >> i) & 1) {
                    //c = 1
                    a[2] ^= (1 << i);
                }
                continue;
            }
            if (((a_and_c >> i) & 1) + ((a_or_c >> i) & 1) == 2) {
                //a = 1, c = 1
                a[0] ^= (1 << i);
                a[2] ^= (1 << i);
                //b = 0
                continue;
            }
            if (((b_and_c >> i) & 1) + ((b_or_c >> i) & 1) == 2) {
                //b = 1, c = 1
                a[1] ^= (1 << i);
                a[2] ^= (1 << i);
                //a = 0
                continue;
            }
            if (((a_and_c >> i) & 1) + ((a_or_c >> i) & 1) == 0) {
                //a = 0, c = 0;
                //b = 1
                a[1] ^= (1 << i);
                continue;
            }
            //a = 1, c = 0, b = 0;
            a[0] ^= (1 << i);
        }
        //cout << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
        for (int i = 3; i < n; i += 1) {
            int AND = ask_and(1, i + 1);
            int OR = ask_or(1, i + 1);
            a[i] = OR ^ a[0] ^ AND;
        }
        sort(a.begin(), a.end());
        cout << "finish " << a[k - 1] << endl;
    }
}