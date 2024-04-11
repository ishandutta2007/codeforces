#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];
    string patt = "<3";
    for (auto word : words)
    {
        patt += word;
        patt += "<3";
    }
    //cerr << patt << endl;
    int ptr = 0;
    string mess;
    cin >> mess;
    for (int i = 0; i < mess.length() && ptr < patt.length(); i++)
        if (mess[i] == patt[ptr])
            ptr++;
    if (ptr == patt.length())
        cout << "yes";
    else
        cout << "no";

    return 0;
}