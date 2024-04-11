#include <iostream>
#include <string>
using namespace std;

const int Maxn = 205;

int k, a, b;
string s;
bool canbe[Maxn][Maxn];
int p[Maxn][Maxn];

void Print(int i, int j)
{
     if (i) {
            int len = p[i][j];
            Print(i - 1, j - len);
            cout << s.substr(j - len, len) << endl;
     }
}

int main()
{
    cin >> k >> a >> b;
    cin >> s;
    canbe[0][0] = true;
    for (int i = 0; i < k; i++)
        for (int j = 0; j + a <= s.length(); j++)
            if (canbe[i][j])
               for (int l = a; l <= b && j + l <= s.length(); l++) {
                   canbe[i + 1][j + l] = true;
                   p[i + 1][j + l] = l;
               }
    if (canbe[k][s.length()]) Print(k, s.length());
    else cout << "No solution\n";
    return 0;
}