#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

int main() {
    int i, res1 = 0, res2 = 0;
    string a, b;
    cin >> a >> b;
    vector<int> aup(26, 0);
    vector<int> adown(26, 0);
    vector<int> bup(26, 0);
    vector<int> bdown(26, 0);
    for (i = 0; i < a.size(); i++)
        if (a[i] >= 'a')
            adown[a[i] - 'a']++;
        else
            aup[a[i] - 'A']++;
    for (i = 0; i < b.size(); i++)
        if (b[i] >= 'a')
            bdown[b[i] - 'a']++;
        else
            bup[b[i] - 'A']++;
    for (i = 0; i < 26; i++) {
        while (aup[i] && bup[i]) {
            aup[i]--;
            bup[i]--;
            res1++;
        }
        while (adown[i] && bdown[i]) {
            adown[i]--;
            bdown[i]--;
            res1++;
        }
        while (adown[i] && bup[i]) {
            adown[i]--;
            bup[i]--;
            res2++;
        }
        while (aup[i] && bdown[i]) {
            aup[i]--;
            bdown[i]--;
            res2++;
        }
    }
    cout << res1 << ' ' << res2;
    return 0;
}