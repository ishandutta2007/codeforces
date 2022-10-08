#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

const int mod = 1000000007;

int m, n;
char a[1111][1111];
bool mustver[255][255];
bool musthor[255][255];
bool okcol[255];
int col[255];
int F[255];

int main() {
    scanf("%d%d", &m, &n);
    gets(a[0]);
    Rep(i,4*m+1) gets(a[i]);
    Rep(i,m) Rep(j,n) {
        int x = 4 * i + 1;
        int y = 4 * j + 1;
        int c = 0;
        Rep(u,3) Rep(v,3) if(a[x+u][y+v] == 'O') ++c;   
        if(c == 6) {
            if(a[x][y+1] == 'O') musthor[i][j] = true;
            else mustver[i][j] = true;  
        }
        else if(c == 2 || c == 3) {
            if(a[x][y] == 'O') musthor[i][j] = true;
            else mustver[i][j] = true;  
        }
    }
    Rep(j,n) {
        okcol[j] = true;
        Rep(i,m) if(musthor[i][j]) okcol[j] = false;
        if(m % 2 == 1) okcol[j] = false;
    }   
    Rep(j,n-1) {
        memset(F,0,sizeof(F));
        F[0] = 1;
        Rep(i,m) {
            if(!mustver[i][j] && !mustver[i][j+1]) F[i+1] = (F[i+1] + F[i]) % mod;
            if(i > 0 && !musthor[i][j] && !musthor[i][j+1] && !musthor[i-1][j] && !musthor[i-1][j+1])
                F[i+1] = (F[i+1] + F[i-1]) % mod;   
        }
        col[j] = F[m];
        if(okcol[j] && okcol[j+1]) col[j] = (col[j] + mod - 1) % mod;
    }
//  cout << musthor[0][0] << " " << musthor[1][0] << endl;
//  Rep(j,n-1) cout << col[j] << " "; cout << endl;
    memset(F,0,sizeof(F));
    F[0] = 1;
    Rep(j,n) {
        if(okcol[j]) F[j+1] = (F[j+1] + F[j]) % mod;
        if(j > 0) F[j+1] = (F[j+1] + F[j-1] * 1LL * col[j-1]) % mod;
    }
//  Rep(j,n+1) cout << F[j] << " "; cout << endl;
    cout << F[n] << endl;
    return 0;   
}