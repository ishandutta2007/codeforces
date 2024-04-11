#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, p, q;
int possible[101] = {};

int main()
{
    string s;
    cin >> n >> p >> q;
    cin >> s;

    possible[0] = true;
    for (int i = 0; i + p <= n; i++) possible[i + p] |= possible[i];
    for (int i = 0; i + q <= n; i++) possible[i + q] |= possible[i];

    if (possible[n]) {
        vector<string> answer;
        while (n > 0) {
            if (n - p >= 0 && possible[n - p]) {
                answer.push_back(s.substr(n - p, p));
                s = s.substr(0, n - p);
                n -= p;
            } else if (n - q >= 0 && possible[n - q]) {
                answer.push_back(s.substr(n - q, q));
                s = s.substr(0, n - q);
                n -= q;
            }
        }
        cout << answer.size() << endl;
        for (int i = answer.size(); i--; ) {
            cout << answer[i] << endl;
        }
    } else {
        cout << "-1" << endl;
    }
    return 0;
}