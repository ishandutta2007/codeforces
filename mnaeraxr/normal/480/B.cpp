#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 1<<30;
const double EPS = 1e-9;
const int MAXN = (int)5e3 + 10;
const int MOD = 1000000007;

map<int, int> M;
vector<int> V, LX, LY;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, L, X, Y;
    cin >> N >> L >> X >> Y;

    if (Y < X)
        swap(X, Y);

    for (int i = 0; i < N; ++i)
    {
        int v;
        cin >> v;
        M[v] = true;
        V.push_back(v);
    }

    bool bx = false, by = false;

    for (int i = 0; i < N; ++i)
    {
        if (V[i] + X <= L)
            LX.push_back(V[i] + X);
        if (V[i] - X >= 0)
            LX.push_back(V[i] - X);

        if (V[i] + Y <= L)
            LY.push_back(V[i] + Y);
        if (V[i] - Y >= 0)
            LY.push_back(V[i] - Y);

        if (!bx && (M[V[i] + X] || M[V[i] - X]))
            bx = true;
        if (!by && (M[V[i] + Y] || M[V[i] - Y]))
            by = true;
    }
    if (bx)
    {
        if (!by)
            cout << 1 << endl << Y << endl;
        else
            cout << 0 << endl;
        return 0;
    }
    else
    {
        if (by)
        {
            cout << 1 << endl << X << endl;
            return 0;
        }
    }

    sort(LX.begin(), LX.end());
    sort(LY.begin(), LY.end());

    int ANS = -1;

    for (int p1 = 0, p2 = 0; p1 < (int)LX.size() && p2 < (int)LY.size();)
    {
        if (LX[p1] == LY[p2])
        {
            ANS = LX[p1];
            break;
        }
        else if (LX[p1] < LY[p2])
            p1++;
        else
            p2++;
    }

    if (ANS == -1)
        cout << 2 << endl << X << " " << Y << endl;
    else
        cout << 1 << endl << ANS << endl;

    return 0;
}