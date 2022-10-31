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

const int N = 1000*100 + 100; 

int a[N];

int main(){
    int b, k;
    cin >> b >> k; 

    for(int i = k-1; i >= 0; i--) 
        cin >> a[i]; 

    int z = 1; 

    int ans = 0;
    for(int i = 0; i < k; i++) { 
        ans = (ans + z*(a[i]%2))%2; 
        z = (z*b)%2;
    }
    cout << (ans?"odd":"even") << endl;
    return 0;
}