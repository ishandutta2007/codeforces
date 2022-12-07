// Similar to matrix solution

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair

typedef pair<int, int> pii;
typedef vector<pii> vi;

const int MAXN = (int)3e5 + 10;

map<string, int> M;
string LST[MAXN];
int TOT;
vi ady[MAXN];
int ID[MAXN];
bool mk[MAXN];
int ptr[MAXN];
stack<int> S;

int getId(string &s){
    if (M.find(s) == M.end()){
        M[s] = TOT;
        LST[ TOT ] = s;
        ++TOT;
    }
    return M[s];
}

void dfs(int n){
    for (; ptr[n] < (int)ady[n].size(); ++ptr[n]){
        pii nx = ady[n][ ptr[n] ];
        if (mk[nx.second]) continue;
        mk[nx.second] = true;
        dfs(nx.first);
    }
    S.push(n);
}

string compose(char a, char b){
    string ans = "";
    ans += a;
    ans += b;
    return ans;
}

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; ++i){
        string s; cin >> s;
        string u = compose(s[0], s[1]);
        string v = compose(s[1], s[2]);
        int cu = getId(u), cv = getId(v);
        ady[cu].push_back( mp(cv, i) );
        ID[cv]++;
    }

    int src = 0, bd = 0;
    for (int i = 0; i < TOT; ++i){
        if ((int)ady[i].size() > ID[i]){
            bd += (int)ady[i].size() - ID[i];
            if (bd > 1)
            {
                cout << "NO" << endl;
                return 0;
            }
            src = i;
        }
    }

    dfs(src);

    if ((int)S.size() < n + 1){
        cout << "NO" << endl;
        return 0;
    }
    else{
        int v = S.top(); S.pop();
        cout << "YES" << endl;
        cout << LST[v];
        while (!S.empty()){
            int cur = S.top(); S.pop();
            cout << LST[cur][1];
        }
        cout << endl;
    }
}