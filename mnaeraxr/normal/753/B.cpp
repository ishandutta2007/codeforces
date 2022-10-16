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

set<string> valid_str(){
    set<string> VAL;
    for (int i = 0; i < 10000; ++i){
        string s = toint(i);
        if (good(s)) VAL.insert(s);
    }
    return VAL;
}

pii play(string s){
    cout << s << endl;

    int bull, cows;
    cin >> bull >> cows;

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

void start(){
    auto VAL = valid_str();

    while (true){
        string move = *VAL.begin();
        pii value = play(move);
        if (value.first == 4) break;

        VAL = filter(VAL, move, value);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    start();

    return 0;
}