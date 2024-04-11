#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

pair<int,string> parse(string s){
    int i = 0, j = s.length() - 1, v = 0;

    while (s[i] == '&'){
        v--;
        i++;
    }

    while (s[j] == '*'){
        v++;
        j--;
    }

    string S = "";
    while (i <= j){
        S += s[i++];
    }

    return {v, S};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    map<string,int> M;
    M["void"] = 0;

    for (int i = 0; i < n; ++i){
        string com; cin >> com;

        if (com == "typedef"){
            string a, b; cin >> a >> b;

            pair<int,string> p = parse(a);

            a = p.second;

            int v = p.first;
            int V = M.count(a) ? M[a] : -1;

            if (V == -1 || V + v < 0){
                M[b] = -1;
            }
            else{
                M[b] = V + v;
            }
        }
        else{
            string a; cin >> a;
            pair<int,string> p = parse(a);

            a = p.second;

            int v = p.first;
            int V = M.count(a) ? M[a] : -1;

            if (V == -1 || V + v < 0) cout << "errtype" << endl;
            else{
                cout << "void";
                for (int i = 0; i < V + v; ++i) cout << "*";
                cout << endl;
            }
        }
    }

    return 0;
}