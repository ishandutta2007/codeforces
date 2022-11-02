
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
using namespace std;

class PathGame
{
public:
    int getVal(bool *mex)
    {
        rep(i,0,1002)
        if (!mex[i])
            return i;
        return 1001;
    }
    string judge(vector <string> board)
    {
        int D[1003][4]={0};
        D[1][0] = 1;
        D[1][1] = 1;
        D[1][2] = 1;
        D[1][3] = 0;
        int n = board[0].size();
        rep(len,2,n+1)
        {
            {
                bool mex[1002]={0};
                mex[D[len-1][2]] = 1;
                mex[D[len-1][3]] = 1;
                mex[D[len-1][0]] = 1;
                rep(j,1,len-1)
                {
                    int val = D[j][0] ^ D[len-j-1][3];
                    mex[val] = 1;
                    val = D[j][0] ^ D[len-j-1][2];
                    mex[val] = 1;
                }
                D[len][0] = getVal(mex);
            }
            {
                bool mex[1002] = {0};
                mex[D[len-1][0]] = 1;
                rep(j,1,len-1)
                {
                    int val = D[j][0] ^ D[len-j-1][0];
                    mex[val] = 1;
                }
                D[len][1] = getVal(mex);
            }
            {
                bool mex[1002] = {0};
                mex[D[len-1][2]] = 1;
                rep(j,1,len-1)
                {
                    int val = D[j][3] ^ D[len-1-j][3];
                    mex[val] = 1;
                    val = D[j][2] ^ D[len-1-j][2];
                    mex[val] = 1;
                }
                D[len][2] = getVal(mex);
            }
            {
                bool mex[1002] = {0};
                mex[D[len-1][3]] = 1;
                rep(j,1,len-1)
                {
                    int val = D[j][3] ^ D[len-1-j][2];
                    mex[val] = 1;
                    val = D[j][2] ^ D[len-1-j][3];
                    mex[val] = 1;
                }
                D[len][3] = getVal(mex);
            }
        }
        int res = 0;
        for(int i = 0; i < n;)
            if (board[0][i] == '.' && board[1][i] == '.')
            {
                int st = i;
                while (i < n && board[0][i]=='.' && board[1][i]=='.')
                    ++i;
                int v = -1;
                if (st == 0 && i == n)
                    v = 1;
                else if (st==0 || i == n)
                    v = 0;
                else if (board[0][st-1] == board[0][i])
                    v = 2;
                else
                    v = 3;
                //cout<<v<<' '<<i-st<<' '<<D[v][i-st]<<endl;
                res ^= D[i-st][v];
            }
            else
                i++;
        return res ? "Snuke" : "Sothe";
    }
};





//Powered by [KawigiEdit] 2.0!


int main()
{
    PathGame test;
    //    test.judge({"....","........"});
    int n, m;
    scanf("%d%d", &n, &m);
    vector<string> board;
    board.resize(2);
    rep(i, 0, 2) {
        board[i].resize(n, '.');
    }
    
    rep(i, 0, m) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        board[b][a] = '#';
    }
    string tt = test.judge(board);
    if (tt == "Snuke")
        printf("WIN\n");
    else
        printf("LOSE\n");
    return 0;
}