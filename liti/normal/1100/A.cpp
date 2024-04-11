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

const int N = 100 + 10;

int a[N]; 

int main(){
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) 
        cin >> a[i]; 

    int ans = 0; 

    for(int i = 0; i < k; i++) {
        int sum = 0;
        for(int j = 0; j < n; j++) 
            if( j % k != i % k ) 
                sum += a[j];
        ans = max(ans, abs(sum));
    }
    cout << ans << endl;
    return 0;
}