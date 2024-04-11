#include <iostream>
#include <string>
using namespace std;

const int Maxn = 10005;
const int Maxl = 26;

string s1, s2;
int nextpos[Maxl][Maxn];
int res;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> s1 >> s2;
    for (int i = 0; i < Maxl; i++) {
        nextpos[i][s1.length()] = -1;
        for (int j = s1.length() - 1; j >= 0; j--)
           if (s1[j] == 'a' + i) nextpos[i][j] = j;
           else nextpos[i][j] = nextpos[i][j + 1];
    }
    int i;
    for (i = 0; i < s2.length(); ) {
        res++;
        int pos = -1;
        if (nextpos[s2[i] - 'a'][pos + 1] == -1) break;
        while (i < s2.length() && (pos = nextpos[s2[i] - 'a'][pos + 1]) != -1) i++;
    }
    if (i < s2.length()) cout << "-1\n";
    else cout << res << endl;
    return 0;
}