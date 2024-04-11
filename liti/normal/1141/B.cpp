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

const int N = 2*1000*100 + 100;

int a[2*N]; 

int main(){
    int n;
    cin >> n; 

    for(int i = 0; i < n; i++) 
        cin >> a[i]; 
    copy(a, a + n, a + n); 

    n *= 2; 
    int ans = 0; 
    for(int j, i = 0; i < n; i = j) { 
        for(j = i; j < n && a[i] == a[j]; j++); 
        if( a[i] == 1 ) 
            ans = max(ans, j - i); 
    }
    cout << ans << endl;

    return 0;
}