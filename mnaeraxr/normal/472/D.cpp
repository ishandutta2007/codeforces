/*
    Author: MarX
    School: UH
 */

#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 1<<30;
const double EPS = 1e-9;
const int MAXN = (int)2e3 + 10;

struct Node{
    int v, n1, n2;
    Node (int V, int N1, int N2)
    {
        v = V, n1 = N1, n2 = N2;
    }
    const bool operator <(const Node &other) const
    {
        return v > other.v;
    }
};

int F[MAXN];
int C[MAXN];

int getFather(int a){
    return (a == F[a]) ? a : F[a] = getFather(F[a]);
}

bool join(int a, int b)
{
    int fa = getFather(a), fb = getFather(b);
    if (fa == fb)return false;
    if (C[fb] > C[fa])  swap(fa,fb);
    C[fa]++;
    F[fb] = fa;
    return true;
}

int64 M[MAXN][MAXN];
int64 R[MAXN][MAXN];
vi ady[MAXN];
bool P[MAXN];

void BFS(int n)
{
    //cout << "BFS" << n << endl;
    memset(P,false,sizeof P);
    queue<int> Q;
    Q.push(n);
    P[n] = true;
    R[n][n] = 0;
    while (!Q.empty())
    {
        int cur = Q.front(); Q.pop();
        for (int i = 0; i < (int)ady[cur].size(); ++i)
        {
            int nx = ady[cur][i];
            if (!P[nx])
            {
                P[nx] = true;

                if (cur < nx)
                    R[n][nx] = R[n][cur] + M[cur][nx];
                else
                    R[n][nx] = R[n][cur] + M[nx][cur];

                //cout << nx << ":" << R[n][nx] << endl;

                Q.push(nx);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
        F[i] = i;

    priority_queue<Node> PQ;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> M[i][j];
        }

    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
            PQ.push(Node(M[i][j],i,j));
    }

    bool valid = true;
    int conn = 0;

    while (!PQ.empty() && conn < N - 1)
    {
        Node cur = PQ.top(); PQ.pop();
        if (join(cur.n1, cur.n2))
        {
            //cout << "JOIN " << cur.n1 << " " << cur.n2 << endl;
            R[cur.n1][cur.n2] = R[cur.n2][cur.n1] = cur.v;
            ady[cur.n1].push_back(cur.n2);
            ady[cur.n2].push_back(cur.n1);
            conn++;
        }
    }



    for (int i = 0; i < N; ++i)
        BFS(i);

    /*
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cout << R[i][j] << " ";
        cout << endl;
    }
    */


    for (int i = 0; i < N && valid; ++i)
        for (int j = 0; j < N && valid; ++j)
            if (R[i][j] != M[i][j] || (i != j && R[i][j] == 0))
                valid = false;

    if (valid)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}