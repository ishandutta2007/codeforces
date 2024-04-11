#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

const bool debug = false;
const string alf = "abcdefghijklmnopqrstuvwxyz";

struct item
{
    map<char, int> m;
    int p;
    int cnt = 0;
    bool last = false;
    item(){}
};

vector<item> its(1);

void show()
{
    cout << "=============\n";
    for (int y = 0; y < its.size(); y++) {
        cout << "Item #" << y << ":" << endl;
        cout << "Parent = " << its[y].p << endl;
        cout << "Last = ";
        if (its[y].last) {
            cout << "true";
        }
        else {
            cout << "false";
        }
        cout << endl;
        cout << "Count = " << its[y].cnt << endl;
        cout << "Children:" << endl;
        for (int x = 0; x < alf.size(); x++) {
            if (its[y].m.count(alf[x]) != 0) {
                cout << alf[x] << " - " << its[y].m[alf[x]] << endl;
            }
        }
        cout << "\n";
    }
    cout << "=============\n";
}

//#define cin fin

int main()
{
    //ifstream fin("input.txt");
    char c;
    int ans = 0;
    string s, text;
    vector<string> w;
    while (cin >> s) {
        text += s;
        text += '\n';
    }
    int ind = 0;
    s = "";
    char spec[] = {'.', ',', '?', '!', '\'', '-', '\n', ' '};
    while (ind < text.length()) {
        c = text[ind];
        bool sp = true;
        for (int i = 0; i < alf.size(); i++) {
            if (c == alf[i]) {
                sp = false;
                break;
            }
        }
        if (sp) {
            ans++;
            ind++;
            if (s.length() > 0) {
                w.push_back(s);
            }
            s.clear();
            continue;
        }
        else {
            s += c;
            ind++;
        }
    }
    item root;
    root.p = -1;
    its[0] = root;
    int lst = 1;
    if (debug) {
        cout << ans << endl;
    }
    for (int i = 0; i < w.size(); i++) {
        s = w[i];
        int v = 0;
        int j = 0;
        if (debug) {
            show();
        }
        while (j < s.length() && its[v].m.count(s[j]) > 0 && its[v].cnt > 1) {
            v = its[v].m[s[j]];
            j++;
            ans++;
        }
        if (its[v].cnt <= 1) {
            int u = j;
            while (u < s.length() && its[v].m.count(s[u]) > 0) {
                v = its[v].m[s[u]];
                u++;
            }
            if (its[v].last) {
                if (j == 0) {
                    ans++;
                    j = 1;
                    if (u == 0) {
                        u = 1;
                    }
                }
                if (j == u) {
                    ans--;
                }
                j = u;
                ans++;
            }
        }
        if (debug) {
            cout << s << " " << ans << endl;
        }
        ans += (int)s.length() - j;
        v = 0;
        j = 0;
        while (j < s.length() && its[v].m.count(s[j]) > 0) {
            v = its[v].m[s[j]];
            j++;
        }
        while (j < s.length()) {
            item it;
            its.push_back(it);
            its[v].m[s[j]] = lst;
            its[lst].p = v;
            v = lst;
            lst++;
            j++;
        }
        bool pl = true;
        if (its[v].last) {
            pl = false;
        }
        its[v].last = true;
        while (v != 0) {
            if (pl) {
                its[v].cnt++;
            }
            v = its[v].p;
        }
        if (pl) {
            its[0].cnt++;
        }
        if (debug) {
            cout << s << " " << ans << endl;
        }
    }
    if (debug) {
        show();
    }
    cout << ans << endl;
}