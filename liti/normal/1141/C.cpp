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

const int N = 5*100*1000 + 100;

int a[N];
int mark[N];

void die() { 
    cout << -1 << endl;
    exit(0); 
}

int main(){
    int n; 
    cin >> n; 

    for(int i = 0; i < n-1; i++) { 
        cin >> a[i+1]; 
        a[i+1] += a[i]; 
    }

    int mn = *min_element(a, a + n); 

    for(int i = 0; i < n; i++) {
        if( a[i] - mn >= N || mark[a[i]-mn] ) 
            die();
        mark[a[i]-mn] = 1; 
    }

    int mx = *max_element(a, a + n); 
    if( mx - mn != n-1 ) die(); 
    
    for(int i = 0; i < n; i++) 
        cout << 1 + a[i] - mn << ' ';
    cout << endl;


    return 0;
}