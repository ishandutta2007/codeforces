#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;
int n, m;
char g[maxn][maxn];
set<char> s;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> g[i][j];
    }
    int op = 0;
    for(int i = 1; i < m; i++) if(g[0][i] != g[0][1]) op = 1;
    if(op == 0){
        if(n % 3 != 0){
            cout << "NO";
            return 0;
        }
        for(int i = 0; i < n; i += n / 3){
            s.insert(g[i][0]);
        }
        if(s.size() != 3){
            cout << "NO";
            return 0;
        }
        int ok = 1;
        for(int i = 0; i < n; i += n / 3)
            for(int j = i; j < i + n / 3; j++)
            for(int k = 0; k < m; k++) if(g[j][k] != g[i][0]) {ok = 0;break;}
        if(ok){
            cout << "YES";
            return 0;
        }
        else{
            cout << "NO";
            return 0;
        }
    }
    else{
        if(m % 3 != 0){
            cout << "NO";
            return 0;
        }
        for(int i = 0; i < m; i += m / 3) s.insert(g[0][i]);
        if(s.size() != 3){
            cout << "NO";
            return 0;
        }

        int ok = 1;
        for(int i = 0; i < m; i += m / 3){
            for(int j = i; j < i + m / 3; j++)
            for(int k = 0; k < n; k++) if(g[k][j] != g[0][i]) {ok = 0;break;}
        }
        if(ok){
            cout << "YES";
            return 0;
        }
        else{
            cout << "NO";
            return 0;
        }
    }
}