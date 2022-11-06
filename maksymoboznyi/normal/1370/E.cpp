#include <iostream>

using namespace std;

int main()
{
    string s, t;
    int n;
    cin >> n >> s >> t;
    int k[2][2];
    k[0][0] = 0;
    k[1][1] = 0;
    k[0][1] = 0;
    k[1][0] = 0;
    int ks = 0, kt = 0;
    for (int i = 0; i < n; i++){
        ks += s[i] - '0';
        kt += t[i] - '0';
        if (s[i] == t[i])
            continue;
        if (s[i] == '0') {
            if (k[1][1] != 0)
                k[1][1]--, k[1][0]++;
            else if (k[0][1] != 0)
                k[0][1]--, k[0][0]++;
            else
                k[0][0]++;
        } else
            if (k[0][0] != 0)
                k[0][0]--, k[0][1]++;
            else if (k[1][0] != 0)
                    k[1][0]--, k[1][1]++;
            else
                k[1][1]++;
    }
    if (ks != kt)
        cout << -1;
    else
        cout << k[0][1] + k[1][0];
    return 0;
}