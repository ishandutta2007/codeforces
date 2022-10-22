#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

enum TokenType {
    RESERVED,
    NUMBER,
    WORD
};

struct Token {
    TokenType tokenType;
    string value;

    void print() {
        cout << tokenType << " " << value << "\n";
    }
};

bool is_good_for_word(char c) {
    if ('a' <= c && c <= 'z') return true;
    if ('A' <= c && c <= 'Z') return true;
    if (isdigit(c)) return true;
    if (c == '_' || c == '$') return true;
    return false;
}

bool is_good_for_word(string s) {
    for (char c : s) {
        if (!is_good_for_word(c)) {
            return false;
        }
    }
    return true;
}

string get_next(string t) {
    for (int i = (int) t.size() - 1; i >= 0; i--) {
        if (t[i] != 'z') {
            t[i]++;
            for (int j = i + 1; j < (int) t.size(); j++) {
                t[j] = 'a';
            }
            return t;
        }
    }
    return string(t.size() + 1, 'a');
}

bool is_number_f(string s) {
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

set<string> reserved;

vector<Token> parse(string codeline) {
    vector<Token> tokens;

    for (int i = 0; i < (int) codeline.size(); i++) {
        if (codeline[i] == '#') {
            codeline = codeline.substr(0, i);
        }
    }
    for (int i = 0; i < (int) codeline.size(); i++) {
        if (codeline[i] == ' ') continue;

        int reserved_j;

        {
            int j = -1;
            for (int q = i; q < (int) codeline.size(); q++) {
                if (reserved.count(codeline.substr(i, q - i + 1))) {
                    j = q;
                }
            }
            reserved_j = j;
        }

        int number_j;

        {
            int j = i;
            while (j < (int) codeline.size() && isdigit(codeline[j])) {
                j++;
            }
            number_j = j - 1;
        }

        int word_j;

        {
            int j = i;
            while (is_good_for_word(codeline[j])) {
                j++;
            }
            word_j = isdigit(codeline[i]) ? -1 : j - 1;
        }

        if (reserved_j >= number_j && reserved_j >= word_j) {
            tokens.push_back({RESERVED, codeline.substr(i, reserved_j - i + 1)});
            i = reserved_j;
        } else if (word_j >= number_j) {
            tokens.push_back({WORD, codeline.substr(i, word_j - i + 1)});
            i = word_j;
        } else {
            tokens.push_back({NUMBER, codeline.substr(i, number_j - i + 1)});
            i = number_j;
        }
    }

    return tokens;
}
bool check(const vector<Token> &a, const vector<Token> &b) {
    if (a.size() != b.size()) {
        return false;
    }
    for (int i = 0; i < (int) a.size(); i++) {
        if (a[i].value != b[i].value) {
            return false;
        }
        if (a[i].tokenType != b[i].tokenType) {
            return false;
        }
    }
    return true;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string buf;
    int n;
    cin >> n;
    getline(cin, buf);

    for (int i = 0; i < n; i++) {
        cin >> buf;
        reserved.insert(buf);
    }

    getline(cin, buf);

    int m;
    cin >> m;
    getline(cin, buf);

    vector<string> code(m);

    for (int i = 0; i < m; i++) {
        getline(cin, code[i]);
    }

    vector<Token> tokens, add_tokens;

    for (const string& codeline : code) {
        add_tokens = parse(codeline);
        for (const auto &token : add_tokens) {
            tokens.push_back(token);
        }
    }

    unordered_map<string, string> for_words;

    string cur_short_word;

    for (Token &token : tokens) {
        if (token.tokenType == WORD) {
            if (!for_words.count(token.value)) {
                while (true) {
                    cur_short_word = get_next(cur_short_word);
                    if (!reserved.count(cur_short_word)) {
                        break;
                    }
                }
                for_words[token.value] = cur_short_word;
            }
            token.value = for_words[token.value];
        }
    }

    vector<int> sp(tokens.size());

    for (int i = 1; i < (int) tokens.size(); i++) {
        if (is_number_f(tokens[i - 1].value) && is_number_f(tokens[i].value)) sp[i - 1] = 1;
        if (!isdigit(tokens[i - 1].value.front())
            && is_good_for_word(tokens[i - 1].value)
            && is_good_for_word(tokens[i].value.front())) sp[i - 1] = 1;
        if (is_number_f(tokens[i - 1].value) && isdigit(tokens[i].value.front())) sp[i - 1] = 1;
    }

    string total_string = "";

    for (const auto& token : tokens) {
        total_string += token.value;
    }

    vector<pii> segs;

    for (const string &r : reserved) {
        int sum = 0;
        for (int i = 0; i + 1 < (int) tokens.size(); sum += (int) tokens[i].value.size(), i++) {
            if ((int) r.size() <= (int) tokens[i].value.size()) continue;
            if (total_string.substr(sum, (int) r.size()) == r) {
                int acc = (int) tokens[i].value.size();
                int j = i;
                while (j + 1 < (int) tokens.size() && acc + (int) tokens[j + 1].value.size() < (int) r.size()) {
                    acc += (int) tokens[j + 1].value.size();
                    j++;
                }
                segs.emplace_back(i, j);
            }
        }
    }

    sort(segs.begin(), segs.end(), [&](const pii &p1, const pii &p2) {
        return p1.second < p2.second;
    });

    int last = -inf;

    for (const pii &p : segs) {
        if (p.first > last) {
            last = p.second;
            sp[p.second] = 1;
        }
    }

    for (int i = 0; i < (int) tokens.size(); i++) {
        cout << tokens[i].value;
        if (sp[i]) {
            cout << ' ';
        }
    }

    return 0;
}