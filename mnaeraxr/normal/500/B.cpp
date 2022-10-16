#include <bits/stdc++.h>

using namespace std;

const int MAXN = 310;

int n;
int P[MAXN];
int M[MAXN][MAXN];

bool mk[MAXN];
int FR[MAXN];

int bfs(int t)
{
    memset(mk, false, sizeof mk);
    memset(FR, 0, sizeof FR);

    queue<int> Q;

    Q.push(t);
    mk[t] = true;
    int ans = t;


    while (!Q.empty())
    {
        int cur = Q.front(); Q.pop();
        for (int i = 0; i < n; ++i)
        {
            if (M[i][cur] && !mk[i])
            {
                mk[i] = true;
                Q.push(i);
                if (i > t && P[i] < P[ans])
                    ans = i;
            }
        }
    }

    if (ans != t){
        swap(P[ans], P[t]);
    }
    return P[t];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> P[i];
    }
    for (int i = 0; i < n; ++i){
        string s; cin >> s;
        for (int j = 0; j < n; ++j){
            M[i][j] = (s[j] == '1');
        }
    }

    for (int i = 0; i < n; ++i){
        cout << bfs(i) << " \n"[i == n - 1];
    }
}