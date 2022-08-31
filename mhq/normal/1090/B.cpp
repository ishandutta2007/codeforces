#include <bits/stdc++.h>
using namespace std;
string s;
map<string, string > mp;
vector<string> tokenize(string s) {
    vector<string> r;
    string cur = "";
    s += ' ';
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            cur += s[i];
        } else if (!cur.empty()) {
            r.push_back(cur);
            cur = "";
        }
    }
    return r;
}
int main() {
    ios_base::sync_with_stdio(0);
    bool open = 0;
    vector<string> lst;
    vector<string> ans;
    while (not cin.eof()) {
        getline(cin, s);
        if (s == "\\begin{thebibliography}{99}") {
            open = 1;
        } else if (s == "\\end{thebibliography}") {
            break;
        } else if (open) {
            vector<string> b = tokenize(s);
            string w = b[0];
            while (w.back() != '}') w.pop_back();
            lst.push_back(w);
            s.erase(s.begin(), s.begin() + w.size());
            mp[w] = s;
        } else {
            vector<string> b = tokenize(s);
            for (auto tmp: b) {
                if (tmp.size() > 4 && tmp.substr(0, 6) == "\\cite{") {
                    tmp.erase(tmp.begin(), tmp.begin() + 6);
                    while (tmp.back() != '}') tmp.pop_back();
                    ans.push_back("\\bibitem{" + tmp);
                }
            }
        }
    }
    if (ans == lst) {
        cout << "Correct\n";
        return 0;
    }
    else {
        cout << "Incorrect\n";
        cout << "\\begin{thebibliography}{99}\n";
        for (auto tmp: ans) {
            cout << tmp << mp[tmp];
            cout << "\n";
        }
        cout << "\\end{thebibliography}\n";
    }
    return 0;
}