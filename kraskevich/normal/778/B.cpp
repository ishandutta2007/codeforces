#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

vector<string> parse(const string& line) {
    istringstream is(line);
    string var;
    is >> var;
    string foo;
    is >> foo;
    string first_op;
    is >> first_op;
    vector<string> res{var, foo, first_op};
    string op;
    if (is >> op) {
        string second_op;
        is >> second_op;
        res.push_back(op);
        res.push_back(second_op);
    }
    return res;
}

const int N = 1001;

bitset<N> eval_one(const string& s, map<string, bitset<N>>& vars, const bitset<N>& x) {
    if (s[0] == '0' || s[0] == '1')
        return bitset<N>(s);
    if (s == "?")
        return x;
    return vars[s];
}


vector<int> eval_bit(const vector<vector<string>>& expr, const bitset<N>& x) {
    vector<int> cnt(N);
    map<string, bitset<N>> vars;
    for (auto s : expr) {
        bitset<N> res;
        if ((int)s.size() == 3) 
            res = eval_one(s[2], vars, x);
        else {
            auto a = eval_one(s[2], vars, x);
            auto b = eval_one(s[4], vars, x);
            if (s[3] == "AND")
                res = a & b;
            else if (s[3] == "OR")
                res = a | b;
            else
                res = a ^ b;
        }
        vars[s[0]] = res;
        for (int i = 0; i < N; i++)
            cnt[i] += res[i];
    }
    return cnt;
}
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string line;
    getline(cin, line);
    vector<vector<string>> expr;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        expr.push_back(parse(line));
    }
    string low;
    string high;
    bitset<N> x;
    vector<int> bs0 = eval_bit(expr, x);
    x.set();
    vector<int> bs1 = eval_bit(expr, x);
    for (int i = 0; i < m; i++) {
        int b0 = bs0[m - i - 1];
        int b1 = bs1[m - i - 1];
        if (b0 >= b1)
            high += '0';
        else
            high += '1';
        if (b0 <= b1)
            low += '0';
        else
            low += '1';
    }
    cout << low << endl << high << endl;
}