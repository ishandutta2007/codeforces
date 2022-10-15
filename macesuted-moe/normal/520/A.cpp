#include <bits/stdc++.h>
using namespace std;

string str;

bool vis[1000];

int main() {
    int len;
    cin >> len >> str;
    for (int i = 0; i < len; i++) vis[str[i] <= 'Z' ? str[i] - 'A' + 'a' : str[i]]++;
    bool check = true;
    for (int i = 'a'; i <= 'z'; i++)
        if (!vis[i]) check = false;
    puts(check ? "YES" : "NO");
    return 0;
}