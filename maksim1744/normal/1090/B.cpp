/*
    26.03.2019 19:20:19
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#define TAG_LENGTH 45
#define LR_LEFT left
#define LR_RIGHT right
#define LR_VALUE value
#define LR_SECOND_VALUE mn
#include "C:/C++ libs/print.cpp"
#define showl cout << endl;
#define shows cout << string(5, ' ') + string(TAG_LENGTH, '-') << endl;
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

int main() {
    int cnt = 0;
    map<string, int> num;
    string s = "0";
    while (s != "\\begin{thebibliography}{99}") {
        while (s.substr(0, 6) != "\\cite{" && s != "\\begin{thebibliography}{99}") {
            cin >> s;
        }
        if (s == "\\begin{thebibliography}{99}")
            break;
        s = s.substr(6, s.size());
        while (s.back() != '}')
            s.pop_back();
        num[s] = cnt++;
        cin >> s;
    }
    // show(num);
    getline(cin, s);
    getline(cin, s);
    vector<string> refs;
    vector<int> must;
    while (s != "\\end{thebibliography}") {
        int i1 = 9;
        int i2 = i1;
        while (s[i2] != '}')
            ++i2;
        must.push_back(num[s.substr(i1, i2 - i1 + 1)]);
        refs.push_back(s);
        getline(cin, s);
    }
    // show(must, refs);
    bool ok = true;
    for (int i = 0; i < must.size(); ++i) {
        if (i != must[i]) {
            ok = false;
            break;
        }
    }
    if (ok) {
        cout << "Correct\n";
        return 0;
    }
    vector<string> okrefs(refs.size());
    for (int i = 0; i < refs.size(); ++i) {
        okrefs[must[i]] = refs[i];
    }
    cout << "Incorrect\n";
    cout << "\\begin{thebibliography}{99}\n";
    for (auto s : okrefs) {
        cout << s << '\n';
    }
    cout << "\\end{thebibliography}\n";
    return 0;
}