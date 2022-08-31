// start 12:34


#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

struct obj {
    vector<string> v;
    int size() {
        return v.size();
    }
    string& operator[](int i) {
        return v[i];
    }
    void push_back(const string& s) {
        v.push_back(s);
    }
};

void prt(obj res) {
    cout << res.size() << ' ' << res[0].size() << endl;
    for (int i = 0; i < res.v.size(); ++i) {
        cout << res.v[i] << "\n";
    }
    cout << endl;
}

obj build_expr(string s);

obj build_atom(string s) {
    //cout << "atom " << s << endl;
    if (s.back() == '+') {
        s.pop_back();
        obj res = build_atom(s);
        for (int i = 0; i < res.size(); ++i) {
            if (i == 0) {
                res[i] = "   " + res[i] + "   ";
                continue;
            }
            if (i == 1) {
                res[i] = "+->" + res[i] + "->+";
                continue;
            }
            res[i] = "|  " + res[i] + "  |";
            continue;
        }
        string ss = string(res[0].size(), ' ');
        ss[0] = '|';
        ss.back() = '|';
        res.push_back(ss);
        ss = string(res[0].size(), '-');
        ss[0] = '+';
        ss[1] = '<';
        ss.back() = '+';
        res.push_back(ss);
        return res;
    }
    if (s.back() == '?') {
        s.pop_back();
        obj res = build_atom(s);
        int len = res[0].size() + 6;
        for (int i = 0; i < res.size(); ++i) {
            if (i == 0) {
                res[i] = "|  " + res[i] + "  |";
                continue;
            }
            if (i == 1) {
                res[i] = "+->" + res[i] + "->+";
                continue;
            }
            res[i] = "   " + res[i] + "   ";
            continue;
        }
        string ss = string(len, ' ');
        ss[0] = '|';
        ss.back() = '|';
        res.v.insert(res.v.begin(), ss);

        //res.push_back(string(len, ' '));
        ss = string(len, '-');
        ss[0] = '+';
        ss[ss.size() - 2] = '>';
        ss.back() = '+';
        //res.push_back(ss);
        res.v.insert(res.v.begin(), ss);
        res.v.insert(res.v.begin(), string(len, ' '));

        return res;
    }
    if (s.back() == '*') {
        s.pop_back();
        obj res = build_atom(s);
        int len = res[0].size() + 6;

        /*res.push_back(string(len, ' '));
        string ss = string(len, '-');
        ss[0] = '+';
        ss[ss.size() - 2] = '>';
        ss.back() = '+';
        res.push_back(ss);

        ss = string(len, ' ');
        ss[0] = '|';
        ss.back() = '|';
        res.push_back(ss);
*/

        for (int i = 0; i < res.size(); ++i) {
            if (i == 0) {
                res[i] = "|  " + res[i] + "  |";
                continue;
            }
            if (i == 1) {
                res[i] = "+->" + res[i] + "->+";
                continue;
            }
            res[i] = "|  " + res[i] + "  |";
            continue;
        }

        string ss = string(res[0].size(), ' ');
        ss[0] = '|';
        ss.back() = '|';
        res.push_back(ss);
        ss = string(res[0].size(), '-');
        ss[0] = '+';
        ss[1] = '<';
        ss.back() = '+';
        res.push_back(ss);



        ///////////////
        ss = string(len, ' ');
        ss[0] = '|';
        ss.back() = '|';
        res.v.insert(res.v.begin(), ss);

        //res.push_back(string(len, ' '));
        ss = string(len, '-');
        ss[0] = '+';
        ss[ss.size() - 2] = '>';
        ss.back() = '+';
        //res.push_back(ss);
        res.v.insert(res.v.begin(), ss);
        res.v.insert(res.v.begin(), string(len, ' '));
        return res;
    }
    if (s[0] == '(' && s.back() == ')') {
        s.pop_back();
        reverse(s.begin(), s.end());
        s.pop_back();
        reverse(s.begin(), s.end());
        return build_expr(s);
    }
    obj ans;
    string ss(s.size() + 4, '-');
    ss[0] = ss.back() = '+';
    ans.push_back(ss);
    ans.push_back("+ " + s + " +");
    ans.push_back(ss);
    return ans;
}

obj build_term(string s) {
    //cout << "term " << s << endl;
    vector<string> parts;
    reverse(s.begin(), s.end());
    while (!s.empty()) {
        string cur;
        char c = s.back();
        if (c == '(') {
            int ctr = 1;
            cur += s.back();
            s.pop_back();
            while (true) {
                cur += s.back();
                if (s.back() == '(') ++ctr;
                if (s.back() == ')') --ctr;
                s.pop_back();
                if (ctr == 0) {
                    break;
                }
            }
        } else {
            cur += c;
            s.pop_back();
            while (!s.empty() && (s.back() >= 'A' && s.back() <= 'Z')) {
                if (s.size() >= 2 && s[s.size() - 2] == '?' || s[s.size() - 2] == '+' || s[s.size() - 2] == '*') {
                    break;
                }
                cur += s.back();
                s.pop_back();
            }
        }
        while (!s.empty() && (s.back() == '+' || s.back() == '*' || s.back() == '?')) {
            cur += s.back();
            s.pop_back();
        }
        parts.push_back(cur);
    }
    if (parts.size() == 1) {
        return build_atom(parts[0]);
    }
    vector<obj> res;
    for (string p : parts) {
        res.push_back(build_atom(p));
        //prt(res.back());
    }
    int mxh = res[0].size();
    for (int i = 0; i < res.size(); ++i) {
        mxh = max(mxh, res[i].size());
    }
    obj ans;
    for (int i = 0; i < mxh; ++i) {
        string s;
        for (int j = 0; j < res.size(); ++j) {
            if (i >= res[j].size()) {
                s += string(res[j][0].size(), ' ');
            } else {
                s += res[j][i];
            }
            if (j + 1 == res.size()) {
                break;
            }
            if (i == 1) {
                s += "->";
            } else {
                s += "  ";
            }
        }
        ans.push_back(s);
    }
    //cout << "term built" << endl;
    return ans;
}

obj build_expr(string s) {
    //cout << "expr " << s << endl;
    vector<string> expr;
    string cur;
    int ctr = 0;
    for (char c : s) {
        if (c == '(') {
            ++ctr;
            cur += c;
            continue;
        }
        if (c == ')') {
            --ctr;
            cur += c;
            continue;
        }
        if (ctr > 0) {
            cur += c;
            continue;
        }
        if (c != '|') {
            cur += c;
            continue;
        }
        expr.push_back(cur);
        cur.clear();
        continue;
    }
    if (cur.size()) {
        expr.push_back(cur);
    }
    if (expr.size() == 1) {
        return build_term(s);
    }
    vector<obj> res;
    for (string cur : expr) {
        res.push_back(build_expr(cur));
    }
    int mxw = res[0][0].size();
    for (int i = 0; i < res.size(); ++i) {
        mxw = max<int>(mxw, res[i][0].size());
       // prt(res[i]);
    }
    obj ans;
    string empt = "|  " + string(mxw, ' ') + "  |";
    bool is_all = false;
    int I = -1;
    for (obj cur : res) {
        ++I;
        if (I) ans.push_back(empt);
        for (int i = 0; i < cur.size(); ++i) {
            bool arrow = false;
            if (i == 1) {
                arrow = true;
            }
            if (is_all || (I == 0 && i == 0)) {
                string s = "   ";
                s += cur[i];
                while (s.size() < mxw + 6) {
                    s += ' ';
                }
                ans.push_back(s);
                continue;
            }
            string s = (arrow ? "+->" : "|  ");
            s += cur[i];
            while (s.size() < mxw + 6) {
                s += arrow ? '-' : ' ';
            }
            if (arrow) {
                s.back() = '+';
                s[s.size() - 2] = '>';
            } else {
                s.back() = '|';
            }
            if (arrow && I + 1 == res.size()) {
                is_all = true;
            }
            ans.push_back(s);
            continue;
        }
    }
    return ans;
}

obj solve(string s) {
    obj res = build_expr(s);
    for (int i = 0; i < res.size(); ++i) {
        if (i == 1) {
            res[i] = "S->" + res[i] + "->F";
        } else {
            res[i] = "   " + res[i] + "   ";
        }
    }
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    obj res = solve(s);
    cout << res.v.size() << ' ' << res.v[0].size() << endl;
    for (int i = 0; i < res.v.size(); ++i) {
        cout << res.v[i] << "\n";
    }
    return 0;
}