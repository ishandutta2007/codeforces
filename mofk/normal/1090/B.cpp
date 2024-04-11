#include <bits/stdc++.h>

using namespace std;

const string sig = "\\begin{thebibliography}{99}";
const string sige = "\\end{thebibliography}";
const string cite = "\\cite";
const string bib = "\\bibitem";

bool match(string p, string s, int fr) {
    for (int i = 0; i < p.size(); ++i) if (fr + i >= s.size() || s[fr + i] != p[i]) return false;
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string text;
    vector<string> items;
    while (getline(cin, text)) {
        if (text == sig) break;
        for (int i = 0; i < text.size(); ++i) if (match(cite, text, i)) {
            i += cite.size() + 1;
            string item = "";
            while (text[i] != '}') item += text[i], ++i;
            items.push_back(item);
        }
    }
    vector<string> item2;
    map<string, string> ss;
    while (getline(cin, text)) {
        if (text == sige) break;
        int i = bib.size() + 1;
        string item = "";
        while (text[i] != '}') item += text[i], ++i;
        string desc = text.substr(i + 1);
        ss[item] = desc;
        item2.push_back(item);
    }
    if (items == item2) {
        cout << "Correct" << endl;
    }
    else {
        cout << "Incorrect" << endl;
        cout << sig << endl;
        for (auto item: items) cout << bib << "{" << item << "}" << ss[item] << endl;
        cout << sige << endl;
    }
    return 0;
}