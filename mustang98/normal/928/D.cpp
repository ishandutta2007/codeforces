#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 300111, let_num = 26, inf = 1000111222;

struct node {
    int children[let_num];
    int counter = 0;
    int ch_num = 0;
    node() {
        memset(children, -1, sizeof(children));
    }
};

node nd[max_n];
int nd_len = 1;
vector<string> words;
set<string> used_words;

bool is_letter(char a) {
    return a >= 'a' && a <= 'z';
}

int parse_words(const string& str) {
    int keys = 0;
    int start = -1;
    for (int i = 0; i < str.size(); ++i) {
        if (is_letter(str[i])) {
            if (start == -1) {
                start = i;
            }
        } else {
            ++keys;
            if (start != -1) {
                words.PB(str.substr(start, i - start));
                start = -1;
            }
        }
    }
    if (start != -1) {
        words.PB(str.substr(start, str.size() - start));
    }
    return keys;
}

int read_text() {
    int keys = 0;
    string str;
    while(getline(cin, str)) {
        if (str == "") break;
        keys += parse_words(str);
        ++keys;
    }
    return keys;
}

void add_word(const string& str) {
    int curr_node = 0;
    for (int i = 0; i < str.size(); ++i) {
        int curr_sym = str[i];
        if (nd[curr_node].children[curr_sym - 'a'] != -1) {
            curr_node = nd[curr_node].children[curr_sym - 'a'];
        } else {
            nd[curr_node].children[curr_sym - 'a'] = nd_len;
            ++nd[curr_node].ch_num;
            curr_node = nd_len++;
        }
        nd[curr_node].counter++;
    }
}

int type_word(const string& str) {
    int curr_node = 0;
    int first_alone = -1;
    for (int i = 0; i < str.size(); ++i) {
        char let = str[i];
        if (nd[curr_node].children[let - 'a'] == -1) return str.size();
        curr_node = nd[curr_node].children[let - 'a'];
        if (nd[curr_node].counter == 1) {
            first_alone = i;
            break;
        }
    }
    if (first_alone == -1 || first_alone == str.size() - 1) return str.size();

    int last_alone = -1;
    for (int i = first_alone + 1; i < str.size(); ++i) {
        char let = str[i];
        if (nd[curr_node].children[let - 'a'] == -1) {
            if (nd[curr_node].ch_num != 0) return str.size();
            last_alone = i - 1;
            break;
        }
        curr_node = nd[curr_node].children[let - 'a'];
    }
    if (last_alone == -1) {
        if (nd[curr_node].ch_num) {
            return str.size();
        } else {
            last_alone = str.size() - 1;
        }
    }
    if (first_alone == last_alone) return str.size();
    return str.size() - (last_alone - first_alone - 1);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    nd[0].counter = inf;
    int keys = read_text();
    for (int i = 0; i < words.size(); ++i) {
        keys += type_word(words[i]);
        if (used_words.count(words[i]) == 0) {
            used_words.insert(words[i]);
            add_word(words[i]);
        }
    }
    cout << keys;
    return 0;
}