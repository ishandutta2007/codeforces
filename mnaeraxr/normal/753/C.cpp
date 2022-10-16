#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

pii test(string a, string b){
    int bull = 0, cows = 0;

    for (int i = 0; i < 4; ++i)
        if (a[i] == b[i])
            bull++;

    for (int i = 0; i < 4; ++i){
        if (b.find(a[i]) != b.npos)
            cows++;
    }


    return {bull, cows - bull};
}

bool good(string a){
    for (int i = 0; i < 4; ++i)
        for (int j = i + 1; j < 4; ++j)
            if (a[i] == a[j]) return false;

    return true;
}

string toint(int a){
    string s = "";
    for (int i = 0; i < 4; ++i, a /= 10)
        s = (char)(a % 10 + '0') + s;
    return s;
}

string hidden;
int steps;

pii opponent(string s){
    return test(s, hidden);
}

set<string> valid_str(){
    set<string> VAL;
    for (int i = 0; i < 10000; ++i){
        string s = toint(i);
        if (good(s)) VAL.insert(s);
    }
    return VAL;
}

pii play(string s){
    int bull, cows;

    cout << s << endl;
    cin >> bull >> cows;

    // auto cur = opponent(s);
    // bull = cur.first, cows = cur.second;

    return {bull, cows};
}

set<string> filter(set<string> &A, string s, pii value){
    set<string> G;
    for (auto &a : A){
        if (test(a, s) == value)
            G.insert(a);
    }
    return G;
}

void smart(){
    auto VAL = valid_str();
    auto GOOD = VAL;
    set<string> BAD;

    steps = 0;

    vector<string> init = {"0123", "4567"};
    int pos = 0;

    while (true){
        string move;

        if (VAL.size() == 1)
            move = *VAL.begin();
        else if (pos < (int)init.size())
            move = init[pos++];
        else{
            int num = oo;

            for (auto a : GOOD){
                if (BAD.count(a)) continue;

                map<pii,int> M;

                for (auto v : VAL){
                    pii cur = test(a, v);
                    M[cur]++;
                }

                int val = 0;
                for (auto m : M)
                    val = max(val, m.second);

                if (val < num){
                    num = val;
                    move = a;
                }
            }
        }

        // cout << move << endl;

        auto cur = play(move);
        BAD.insert(move);
        steps++;

        if (cur.first == 4) break;

        VAL = filter(VAL, move, cur);

        // cout << VAL.size() << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // hidden = "0238";
    // smart();
    // exit(0);

    // for (int i = 10000 - 1; i; --i){
    //     string s = toint(i);
    //     if (good(s)){
    //         hidden = toint(i);
    //         smart();
    //     }
    // }

    smart();

    return 0;
}