#include <bits/stdc++.h>
using namespace std;

const string op = "+-*/";

struct pos {
    bool spec;
    char fir, lst;
    bool bad;
    pos(bool bad = false): bad(bad) { spec = false; fir = lst = '?'; }
};

map <string, pos> M;

pos getPos(const string &s, int l, int r)
{
    int lst = l;
    int st = 0;
    vector <pos> seq;
    vector <char> seqop;
    for (int i = l; i <= r; i++)
        if (s[i] == '(') st++;
        else if (s[i] == ')') st--;
        else if (st == 0 && op.find(s[i]) != string::npos) {
            seq.push_back(getPos(s, lst, i - 1));
            seqop.push_back(s[i]);
            lst = i + 1;
        }
    if (seqop.empty()) {
        if (s[l] == '(')
            return pos(getPos(s, l + 1, r - 1).bad);
        else if (isalpha(s[l])) {
            string tmp;
            int pnt = l;
            while (pnt <= r && isalpha(s[pnt]))
                tmp += s[pnt++];
            if (M.find(tmp) != M.end()) return M[tmp];
            return pos();
        } else return pos();
    } else {
        seq.push_back(getPos(s, lst, r));
        for (int i = 0; i < seq.size(); i++)
            if (seq[i].bad) return pos(true);
        for (int i = 0; i < seqop.size(); i++) {
            if ((seqop[i] == '*' || seqop[i] == '/') && seq[i].spec)
                return pos(true);
            if (seqop[i] == '-' && seq[i + 1].spec) return true;
            if (seqop[i] == '/' && seq[i + 1].fir != '?')
                return pos(true);
            if (seqop[i] == '*' && seq[i + 1].spec)
                return pos(true);
        }
        pos res;
        res.fir = seq[0].fir == '?'? seqop[0]: seq[0].fir;
        res.lst = seq.back().lst == '?'? seqop.back(): seq.back().lst;
        for (int i = 0; i < seq.size(); i++)
            if (seq[i].spec) res.spec = true;
        for (int i = 0; i < seqop.size(); i++)
            if (seqop[i] == '+' || seqop[i] == '-') res.spec = true;
        return res;
    }
}

pos solveExpression(const string &s)
{
    string rl;
    for (int i = 0; i < s.length(); i++)
        if (s[i] != ' ') rl += s[i];
    return getPos(rl, 0, int(rl.length()) - 1);
}

void Define()
{
    string lin; getline(cin, lin);
    stringstream ss(lin);
    string cur; ss >> cur;
    if (cur == "#") ss >> cur;
    string nam; ss >> nam;
    getline(ss, lin);
    M.insert(make_pair(nam, solveExpression(lin)));
}

int main()
{
    int n; scanf("%d", &n);
    string tmp; getline(cin, tmp);
    while (n--)
        Define();
    getline(cin, tmp);
    auto res = solveExpression(tmp);
    printf("%s\n", res.bad? "Suspicious": "OK");
    return 0;
}