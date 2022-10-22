#include <iostream>
#include <string>
using namespace std;

const int Maxn = 1000;

int n;
string D[Maxn];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> D[i];
    int i;
    string lst = "1000";
    for (i = 0; i < n; i++) {
        bool change = false;
        string mn = "9999";
        for (int dig = 3; dig >= 0 && !change; dig--) {
            char save = D[i][dig];
            for (char c = '0'; c <= '9' && !change; c++) {
                D[i][dig] = c;
                if (D[i] >= lst && D[i] < mn) mn = D[i];
            }
            if (!change) D[i][dig] = save;
        }
        lst = D[i] = mn;
        if (lst > "2011") break;
    }
    if (i < n) cout << "No solution\n";
    else for (int i = 0; i < n; i++)
            cout << D[i] << endl;
    return 0;
}