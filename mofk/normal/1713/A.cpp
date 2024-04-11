#include<bits/stdc++.h>

using namespace std;

int main(void) {
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        int mxa = 0, mxb = 0, mna = 0, mnb = 0;
        while (n--) {
            int a, b;
            cin >> a >> b;
            mxa = max(mxa, a);
            mna = min(mna, a);
            mxb = max(mxb, b);
            mnb = min(mnb, b);
        }
        cout << (mxa - mna + mxb - mnb) * 2 << '\n';
    }
    return 0;
}