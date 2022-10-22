#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a!=int(c); a++)

const int MX = 60;

int N, e;
bitset<MX> M[2][MX];
bitset<MX> found[2][MX][MX][MX];
bitset<MX> mem  [2][MX][MX][MX];

bool possible(bool a, int x1, int x2, int y1, int y2) {
    if(x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0 ||
       x1 > e || x2 > e || y1 > e || y2 > e) return 0;
    if(!found[a][x1][x2][y1][y2]) {
        if(M[a][x1][y1] != M[a][x2][y2] || x1 > x2 || y1 > y2) {
            mem[a][x1][x2][y1][y2] = 0;
        } else {
            if(x1 + 1 == x2 && y1 == y2) mem[a][x1][x2][y1][y2] = 1;
            else if(y1 + 1 == y2 && x1 == x2) mem[a][x1][x2][y1][y2] = 1;
            else mem[a][x1][x2][y1][y2] =
                possible(a, x1+1, x2-1, y1, y2) ||
                possible(a, x1+1, x2, y1, y2-1) ||
                possible(a, x1, x2, y1+1, y2-1) ||
                possible(a, x1, x2-1, y1+1, y2);
        }
        found[a][x1][x2][y1][y2] = 1;
    }
    return mem[a][x1][x2][y1][y2];
}
bool getValue(bool value, int y1, int y2, int x1, int x2) {
    cout<<"? "<<x1+1<<" "<<y1+1<<" "<<x2+1<<" "<<y2+1<<endl;
    cout.flush();
    bool ans=0;
    cin>>ans;
    return ans?value:!value;
}
int main() {
    cin>>N;
    e = N-1;
    M[0][0][0] = 1;
    M[0][e][e] = 0;

    //black
    for(int j=2; j<=e; j+=2)
        M[0][0][j] = getValue(M[0][0][j-2], 0, 0, j-2, j);
    for(int i=1; i<=e; i+=2) {
        for(int j=1; j<=e; j+=2)
            M[0][i][j] = getValue(M[0][i-1][j-1], i-1, i, j-1, j);
        for(int j=0; j<=e; j+=2)
            if(i+1!=e || j!=e)
                M[0][i+1][j] = getValue(M[0][i-1][j], i-1, i+1, j, j);
    }

    //white
    for(int j=3; j<=e; j+=2)
        M[0][0][j] = getValue(M[0][0][j-2], 0, 0, j-2, j);
    for(int i=1; i<=e; i++) {
        for(int j=2; j<=e; j+=2)
            M[0][i][j] = getValue(M[0][i-1][j-1], i-1, i, j-1, j);
        M[0][i][0] = getValue(M[0][i][2], i, i, 0, 2);
        i++;
        for(int j=1; j<=e; j+=2)
            M[0][i][j] = getValue(M[0][i-1][j-1], i-1, i, j-1, j);
    }

    //two possible
    REP(i,0,N)
        REP(j,0,N)
            M[1][i][j] = ((i+j)%2==0 ? M[0][i][j] : !M[0][i][j]);

    //dp
    REP(a,0,2)
        REP(i,0,N)
            REP(j,0,N)
                REP(k,0,N)
                    mem[a][i][j][k].reset(), found[a][i][j][k].reset();

    REP(x1,0,N) {
        REP(x2,x1,N) {
            REP(y1,0,N) {
                REP(y2,y1,N) {
                    if(x1+y1+2>x2+y2) continue;
                    if(possible(0,x1,x2,y1,y2) != possible(1,x1,x2,y1,y2)) {
                        bool ans = possible(0,x1,x2,y1,y2) ^ getValue(1,x1,x2,y1,y2);
                        cout<<"!"<<endl;
                        REP(i,0,N) {
                            REP(j,0,N) {
                                cout<<M[ans][j][i];
                            }
                            cout<<endl;
                        }
                        return 0;
                    }
                }
            }
        }
    }

    REP(i,0,N) {
        REP(j,0,N) {
            cout<<M[0][j][i];
        }
        cout<<endl;
    }
}