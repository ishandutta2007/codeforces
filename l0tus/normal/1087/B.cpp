#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef pair<int,int> pii;
const int INF = 2e9;
const int mx = 1e5;

struct C{
    int a,b;
    C(){};
    C(int a,int b):a(a),b(b){};
    bool operator < (const C &X) const{
        return a<X.a;
    }
};

int N,K;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> K;
    int i=K-1;
    while(N%i) i--;
    cout << N/i*K+i;
}