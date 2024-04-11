#include <bits/stdc++.h>
using namespace std;

const string lets = "RGB";

string s;

int main()
{
    int n; scanf("%d", &n);
    cin >> s;
    int difs = 0;
    for (int i = 0; i + 1 < s.length(); i++)
        if (s[i] == s[i + 1]) {
            difs++;
            int ind = lets.find(s[i]);
            int ind2 = i + 2 < s.length()? lets.find(s[i + 2]): ind;
            if (ind == ind2) {
                ind = (ind + 1) % 3;
                s[i + 1] = lets[ind];
            } else {
                ind = 3 - ind - ind2;
                s[i + 1] = lets[ind];
            }
        }
    printf("%d\n", difs);
    cout << s << endl;
    return 0;
}