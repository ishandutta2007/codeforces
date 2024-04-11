#include <bits/stdc++.h>
using namespace std;

inline string next(string s) {
    int q = (int)s.size() - 1;
    while (q >= 0 && s[q] == 'z') {
        s[q] = 'a';
        --q;
    }
    if (q < 0) {
        s = 'a' + s;
    } else {
        ++s[q];
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    set<string> reservedToken;
    set<string> reservedTokenPref;

    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        reservedToken.insert(s);
        for (int j = 1; j <= (int)s.size(); ++j) {
            reservedTokenPref.insert(s.substr(0, j));
        }
    }

    auto isNumber = [&](string s) {
        for (char c : s) {
            if (c < '0' || c > '9') {
                return false;
            }
        }
        return true;
    };

    auto isWord = [&](string s) {
        if (s.empty()) {
            return false;
        }
        if ('0' <= s[0] && s[0] <= '9') {
            return false;
        }
        for (char c : s) {
            if ('0' <= c && c <= '9') continue;
            if ('a' <= c && c <= 'z') continue;
            if ('A' <= c && c <= 'Z') continue;
            if (c == '$' || c == '_') continue;
            return false;
        }
        return true;
    };

    auto tokenCanStart = [&](string s) {
        if (reservedTokenPref.count(s)) {
            return true;
        }
        if (s.empty()) {
            return true;
        }
        if ('0' <= s[0] && s[0] <= '9') {
            for (char c : s) {
                if (c < '0' || c > '9') {
                    return false;
                }
            }
            return true;
        }
        for (char c : s) {
            if ('0' <= c && c <= '9') continue;
            if ('a' <= c && c <= 'z') continue;
            if ('A' <= c && c <= 'Z') continue;
            if (c == '$' || c == '_') continue;
            return false;
        }
        return true;
    };

    auto tokenValid = [&](string s) {
        if (s.empty()) {
            return false;
        }
        if (reservedToken.count(s)) {
            return true;
        }
        if (isNumber(s)) {
            return true;
        }
        if (isWord(s)) {
            return true;
        }
        return false;
    };

    vector<string> tokens;
    map<string, string> words;
    string lastWord;

    auto tokenize = [&](string s) {
        vector<string> res;
        for (int pos = 0; pos < (int)s.size();) {
            if (s[pos] == ' ') {
                ++pos;
                continue;
            }
            int mr = pos;
            for (int r = pos+1; r <= pos+82 && r <= (int)s.size(); ++r) {
                if (tokenValid(s.substr(pos, r-pos))) {
                    mr = r;
                }
            }
            if (mr == pos) {
                return vector<string> {" "};
            }
            assert(mr != pos);
            res.push_back(s.substr(pos, mr-pos));
            pos = mr;
        }
        return res;
    };

    auto pushToken = [&](string token) {
        if (token.empty()) {
            return;
        }
        if (reservedToken.count(token) || isNumber(token)) {
            tokens.push_back(token);
            return;
        }
        if (words.count(token)) {
            tokens.push_back(words[token]);
            return;
        }
        do {
            lastWord = next(lastWord);
        } while (reservedToken.count(lastWord));
        words[token] = lastWord;
        tokens.push_back(lastWord);
    };

    int progmatic; cin >> progmatic;
    string musor; getline(cin, musor);
    for (int i = 0; i < progmatic; ++i) {
        string s; getline(cin, s);
        auto p = s.find('#');
        if (p != string::npos) {
            s.erase(p);
        }
        for (string token : tokenize(s)) {
            pushToken(token);
        }
    }

    if (tokens.empty()) {
        cout << endl;
        return 0;
    }

    /*for (string s: tokens) {
        cout << "got #" << s << "#" << endl;
    }*/

    string answr;
    vector<int> poses;
    int sz = 0;
    int lSpace = 0;
    for (int i = 0; i < (int)tokens.size(); ++i) {
        string newAns = answr + tokens[i];

        //cout << "adding " << tokens[i] << endl;

        bool ok = true;
        for (int j = lSpace; j < i; ++j) {
            for (int k = 0; k < (int)tokens[i].size(); ++k) {
                int left = poses[j], right = answr.size() + k;
                //cout << "!!! " << tokens[i] << " : " << newAns.substr(left, right-left+1) << endl;
                if (right-left+1 <= 82 && tokenValid(newAns.substr(left, right-left+1))) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                break;
            }
        }

        if (!ok) {
            answr += ' ';
            lSpace = i;
        }
        poses.push_back(answr.size());
        answr += tokens[i];

        sz += tokens[i].size();

    }

    cout << answr << endl;
    return 0;
}