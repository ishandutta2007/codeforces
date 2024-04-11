#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

pii ask(const string& num, const string& secret) {
    int bulls = 0;
    int cows = 0;
    for (int i = 0; i < 4; i++)
        if (num[i] == secret[i])
            bulls++;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (num[i] == secret[j])
                cows++;
    cows -= bulls;
    return pii(bulls, cows);
}

string guess = "0123";

pii do_ask(const string& num) {
    //cerr << num << endl;
    //return ask(num, guess);    
    cout << num << endl;
    int bulls, cows;
    cin >> bulls >> cows;
    if (bulls == 4)
        exit(0);
    return pii(bulls, cows);
}

vector<string> cur;

void gen_diff(string now, set<char> ds) {
    if (now.length() == 4) {
        cur.push_back(now);
        return;    
    }
    set<char> have = ds;
    for (auto x : have) {
        ds.erase(x);
        gen_diff(now + x, ds);
        ds.insert(x);
    } 
}

void solve(vector<string> have) {
    if (have.size() == 1) {
        pii res = do_ask(have[0]);
        assert (res == pii(4, 0));
        return;    
    }
    cur.clear();
    set<char> ds;
    for (const auto& row : have)
        for (auto c : row)
            ds.insert(c); 
    gen_diff("", ds);
    string best = have[0];
    int max_size = have.size();
    for (const auto& cand: cur) {
        map<pii, int> cnt;
        for (const auto& s : have)
            cnt[ask(cand, s)]++;
        int cur_size = 0;
        for (const auto& kv : cnt)
            cur_size = max(cur_size, kv.second);
        if (cur_size < max_size) {
            max_size = cur_size;
            best = cand;
        }           
    }   
    pii p = do_ask(best);
    vector<string> after;
    for (const auto& s : have)
        if (ask(best, s) == p)
            after.push_back(s);
    solve(after);         
} 


int main() {
    ios_base::sync_with_stdio(0);
    set<char> all;
    for (char c = '0'; c <= '9'; c++)
        all.insert(c);
    cur.clear();   
    gen_diff("", all);
    solve(cur);     
}