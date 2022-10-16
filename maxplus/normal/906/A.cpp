#include <iostream>

using namespace std;

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    int msk = (1 << 26) - 1, win = 0, save = 0;
    char t;
    string w;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t >> w;
        bool with = t == '!' || (t == '?' && i == n - 1);
        for (char l = 'a'; l <= 'z'; ++l) {
            if ((w.find(l) == string::npos) == with) {
                msk &= ~(1 << (l - 'a'));
            }
        }
        if (win) {
            save += t == '!' || (t == '?' && i != n - 1);
        }
        win |= __builtin_popcount(msk) == 1;
    }
    cout << save;
    return 0;
}