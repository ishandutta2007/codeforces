//be naame khodaa
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

inline int in(){ int x, y; y = scanf("%d", &x); return x; }

const int N = 300 * 1000 + 100; 

string a[N];
char ch[] = {'A', 'C', 'T', 'G'};
int n, m;
int mnAns;

bool pr;

int state[N];

int solve_row() {
    char c[2][2] = { {ch[0],ch[1]}, {ch[2], ch[3]} };
    int sum = 0;
    for(int i = 0; i < n; i++) { 
        char* d = c[i%2]; 
        int diff[2] = {0,0}; 
        for(int j = 0; j < m; j++) 
            diff[0] += ( a[i][j] != d[j%2] ); 
        for(int j = 0; j < m; j++) 
            diff[1] += ( a[i][j] != d[(1+j)%2] ); 
        state[i] = (diff[0] >= diff[1]);
        sum += min(diff[0], diff[1]);
    }

    if( pr && sum == mnAns ) {
        for(int i = 0; i < n; i++) { 
            char* d = c[i%2]; 
            for(int j = 0; j < m; j++) 
                cout << d[(state[i]+j)%2];
            cout << '\n';
        }
        exit(0);
    }

    return sum;
}

int solve_col() {
    char c[2][2] = { {ch[0],ch[1]}, {ch[2], ch[3]} };
    int sum = 0;
    for(int j = 0; j < m; j++) { 
        char* d = c[j%2]; 
        int diff[2] = {0,0}; 
        for(int i = 0; i < n; i++) 
            diff[0] += ( a[i][j] != d[i%2] ); 
        for(int i = 0; i < n; i++) 
            diff[1] += ( a[i][j] != d[(1+i)%2] ); 
        state[j] = (diff[0] >= diff[1]);
        sum += min(diff[0], diff[1]);
    }

    if( pr && sum == mnAns ) {
        for(int j = 0; j < m; j++) { 
            char* d = c[j%2]; 
            for(int i = 0; i < n; i++) 
                a[i][j] = d[(state[j]+i)%2];
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) 
                cout << a[i][j];
            cout << '\n';
        }
        exit(0);
    }

    return sum;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); 

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    mnAns = n * m + 1; 

    do {
        mnAns = min(mnAns, solve_row());
        mnAns = min(mnAns, solve_col());
    } while( next_permutation(ch, ch + 4) );


    pr = true;

    do {
        solve_row();
        solve_col();
    } while( next_permutation(ch, ch + 4) );

    return 0;
}