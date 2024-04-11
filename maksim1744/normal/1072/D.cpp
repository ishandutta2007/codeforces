/*
    21.10.2018 12:09:47
*/

#include <bits/stdc++.h>

using namespace std;
string to_string(const basic_string< char >& s) {
    return (string)s;
}

string to_string(const bool& b) {
    return b ? "true" : "false";
}

string to_string(const char& c) {
    string ans(1, c);
    return ans;
}

template< typename T1, typename T2 >
string to_string(const pair< T1, T2 >& p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template< typename T >
string to_string(const T& c) {
    string answer = "[";
    bool first = true;
    for (auto& item : c) {
        if (!first) {
            answer += ", ";
        }
        answer += to_string(item);
        first = false;
    }
    answer += "]";
    return answer;
}

template< typename T >
void print(const T& t, bool end = true) {
    cout << to_string(t);
    if (end) {
        cout << "\n";
    }
}

namespace printing {
    // up - bit0, right - bit1, down - bit2, left - bit4
    vector< string > symbols = {" ", " ", " ", "", " ", "", "", "",
                                " ", "", "", "", "", "", "", ""};
    int UP = 1, RIGHT = 2, DOWN = 4, LEFT = 8;
}
vector< string > to_tree(const vector< vector< int > >& g, set< int >& s,
                                                int root = 0, bool plus = false) {
    vector< string > answer;
    int width = 0;
    string emptyWidth = "";
    s.insert(root);
    for (auto item : g[root]) {
        if (s.find(item) == s.end()) {
            vector< string > add = to_tree(g, s, item, plus);
            for (int i = answer.size(); i < add.size(); ++i) {
                answer.push_back(emptyWidth);
            }
            if (width != 0) {
                for (int i = 0; i < answer.size(); ++i) {
                    answer[i].push_back(' ');
                }
                emptyWidth += ' ';
                ++width;
            }
            for (int i = 0; i < add.size(); ++i) {
                answer[i] += add[i];
            }
            string tempWidth(add[0].length(), ' ');
            for (int i = add.size(); i < answer.size(); ++i) {
                answer[i] += tempWidth;
            }
            emptyWidth += tempWidth;
            width += tempWidth.length();
        }
    }
    s.erase(root);
    if (answer.size() == 0) {
        if (plus) {
            ++root;
        }
        answer.push_back(to_string(root));
        return answer;
    }
    string rootLine = emptyWidth;
    if (plus) {
        ++root;
    }
    string rootS = to_string(root);
    if (rootS.length() > emptyWidth.length()) {
        int addL = (rootS.length() - emptyWidth.length()) / 2;
        int addR = rootS.length() - emptyWidth.length() - addL;
        string addLS(addL, ' ');
        string addRS(addR, ' ');
        width += addL + addR;
        for (int i = 0; i < answer.size(); ++i) {
            answer[i] = addLS + answer[i] + addRS;
        }
        emptyWidth = addLS + emptyWidth + addRS;
    }
    int startPos = (emptyWidth.length() - rootS.length()) / 2;
    for (int i = 0; i < rootS.length(); ++i) {
        rootLine[startPos + i] = rootS[i];
    }
    int rootPos = startPos + rootS.length() / 2;
    vector< int > posDown;
    int i = 0;
    while (i < width) {
        if (answer[0][i] != ' ') {
            int i1 = i;
            while (i1 < width && answer[0][i1] != ' ') {
                ++i1;
            }
            --i1;
            posDown.push_back((i + i1) / 2);
            i = i1;
        }
        ++i;
    }
    int k = 0;
    bool okRoot = false;
    string up(posDown[0], ' ');
    for (int i = posDown[0]; i <= posDown.back(); ++i) {
        int c = printing::RIGHT | printing::LEFT;
        if (i == posDown[k]) {
            c |= printing::DOWN;
            if (k == 0) {
                c ^= printing::LEFT;
            }
            if (k + 1 == posDown.size()) {
                c ^= printing::RIGHT;
            }
            ++k;
        }
        if (i == rootPos) {
            c |= printing::UP;
        }
        up += printing::symbols[c];
    }
    for (int i = 0; i < width - posDown.back() - 1; ++i) {
        up.push_back(' ');
    }
    vector< string > result;
    result.push_back(rootLine);
    result.push_back(up);
    for (auto& s : answer) {
        result.push_back(s);
    }
    return result;
}

void printTree(const vector< vector< int > >& g, int root = 0, bool plus = false) {
    set< int > s;
    vector< string > answer = to_tree(g, s, root, plus);
    for (auto& item : answer) {
        cout << item << '\n';
    }
}

template< typename T >
void printMatrix(const vector< vector< T > >& m, bool equivColumns = false, int space = 3) {
    vector< int > widths(m[0].size(), 0);
    int columns = 0;
    for (auto& row : m) {
        if (row.size() > columns) {
            columns = row.size();
        }
    }
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[i].size(); ++j) {
            int sz = to_string(m[i][j]).length();
            if (sz > widths[j]) {
                widths[j] = sz;
            }
        }
    }
    if (equivColumns) {
        int mx = 0;
        for (auto item : widths) {
            if (item > mx) {
                mx = item;
            }
        }
        for (auto& item : widths) {
            item = mx;
        }
    }
    for (auto& row : m) {
        bool first = true;
        for (int i = 0; i < row.size(); ++i) {
            if (!first) {
                cout << string(space, ' ');
            }
            first = false;
            string s = to_string(row[i]);
            cout << string(widths[i] - s.length(), ' ') + s;
        }
        cout << '\n';
    }
}

typedef pair<int, int> pi;

const bool debug = true;

int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;
    vector< string > f(n);
    for (auto& item : f) {
        cin >> item;
    }
    // if (k >= 2 * n - 1) {
    //     cout << string(2 * n - 1, 'a') << '\n';
    //     return 0;
    // }
    vector< vector< int > > mn(n);
    for (auto& line : mn) {
        line.assign(n, 0);
    }
    if (f[0][0] != 'a') {
        mn[0][0] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }
            mn[i][j] = 1000000000;
            if (i > 0) {
                mn[i][j] = mn[i - 1][j];
            }
            if (j > 0) {
                mn[i][j] = min(mn[i][j], mn[i][j - 1]);
            }
            if (f[i][j] != 'a') {
                ++mn[i][j];
            }
        }
    }
    if (mn[n - 1][n - 1] <= k) {
        cout << string(2 * n - 1, 'a') << '\n';
        return 0;
    }
    vector< pi > now;
    int mx = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mn[i][j] <= k && i + j > mx) {
                mx = i + j;
            }
        }
    }
    if (mx < n) {
        for (int i = 0; i <= mx; ++i) {
            int j = mx - i;
            if (mn[i][j] <= k) {
                now.push_back({i, j});
            }
        }
    } else {
        for (int i = mx - n + 1; i < n; ++i) {
            int j = mx - i;
            if (mn[i][j] <= k) {
                now.push_back({i, j});
            }
        }
    }
    cout << string(mx + 1, 'a');
    vector< vector< bool > > u(n);
    for (auto& line : u) {
        line.assign(n, false);
    }
    if (mx == -1) {
        cout << f[0][0];
        now.push_back({0, 0});
        ++mx;
    }
    // print(now);
    for (int i = 0; i < 2 * n - 1 - mx - 1; ++i) {
        vector< pi > next;
        char best = 'z';
        for (auto& cell : now) {
            if (cell.first + 1 < n) {
                best = min(best, f[cell.first + 1][cell.second]);
            }
            if (cell.second + 1 < n) {
                best = min(best, f[cell.first][cell.second + 1]);
            }
        }
        cout << best;
        for (auto& cell : now) {
            if (cell.first + 1 < n && f[cell.first + 1][cell.second] == best) {
                if (!u[cell.first + 1][cell.second]) {
                    next.push_back({cell.first + 1, cell.second});
                    u[cell.first + 1][cell.second] = true;
                }
            }
            if (cell.second + 1 < n && f[cell.first][cell.second + 1] == best) {
                if (!u[cell.first][cell.second + 1]) {
                    next.push_back({cell.first, cell.second + 1});
                    u[cell.first][cell.second + 1] = true;
                }
            }
        }
        // print(next);
        swap(now, next);
    }
    cout << '\n';
    return 0;
}