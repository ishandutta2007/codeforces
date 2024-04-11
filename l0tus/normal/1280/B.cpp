#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const int MN = 2e5+5;
int T,R,C,r[100],c[100],A;
char x;
string S;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> T;
    while(T--){
        cin >> R >> C;
        A = 0;
        bool side = 0, qu = 0;
        for(int i=0; i<R; i++) r[i]=0;
        for(int j=0; j<C; j++) c[j]=0;
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++){
                cin >> x;
                if(x=='A'){
                    if(i==0||i==R-1||j==0||j==C-1) side = 1;
                    if(i==0&&j==0||i==0&&j==C-1||i==R-1&&j==0||i==R-1&&j==C-1) qu = 1;
                    A++;
                    r[i]++;
                    c[j]++;
                }
            }
        if(A==R*C) cout << "0\n";
        else if(A==0) cout << "MORTAL\n";
        else{
            bool lin = 0, sidelin = 0;
            for(int i=0; i<R; i++) if(r[i]==C) lin = 1;
            for(int i=0; i<C; i++) if(c[i]==R) lin = 1;
            if(r[0]==C||r[R-1]==C||c[0]==R||c[C-1]==R) sidelin = 1;
            if(sidelin) cout << "1\n";
            else if(lin||qu) cout << "2\n";
            else{
                if(side) cout << "3\n";
                else cout << "4\n";
            }
        }
    }
}