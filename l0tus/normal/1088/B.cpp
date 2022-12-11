#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
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
int n,k,A[200000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i=0; i<n; i++)
    cin >> A[i];
    sort(A,A+n);
    int x = unique(A,A+n) - A;
    cout << A[0] << '\n';
    for(int i=1; i<min(x,k); i++)
    cout << A[i]-A[i-1] << '\n';
    for(int i=0; i<k-x; i++)
    cout << '0' << '\n';
}