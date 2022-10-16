#include <iostream>
#include <vector>
#include <set>

#define endl '\n'

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t-->0) {
        int n; string s;
        cin >> n >> s;

        int answer = n;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                answer = max(answer, 2 * (i + 1));
                answer = max(answer, 2 * (n - i));
            }
        }

        cout << answer << endl;
    }

    return 0;
}