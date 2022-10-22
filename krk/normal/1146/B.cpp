#include <bits/stdc++.h>
using namespace std;

string t;
vector <int> seq;

int main()
{
    cin >> t;
    for (int i = 0; i < t.length(); i++)
        if (t[i] != 'a') seq.push_back(i);
    if (seq.size() % 2) { printf(":(\n"); return 0; }
    int hf = int(seq.size()) / 2;
    for (int i = 0; i < hf; i++)
        if (t[seq[i]] != t[seq[hf + i]]) { printf(":(\n"); return 0; }
    for (int i = 1; i <= hf; i++)
        if (t[int(t.length()) - i] == 'a') { printf(":(\n"); return 0; }
    printf("%s\n", t.substr(0, int(t.length()) - hf).c_str());
    return 0;
}