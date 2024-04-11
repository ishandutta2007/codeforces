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

const int N = 2000 + 10;

int main(){
    int k; 
    cin >> k; 

    int n = 2000; 
    int val = k + n; 
    cout << n << endl;
    cout << -1 ;
    for(int i = 1; i < n; i++) { 
        int now = min(1000*1000, val); 
        val -= now;
        cout << " " << now;
    }
    cout << endl;
    return 0;
}