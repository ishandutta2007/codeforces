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

char N,M,A[mx],B[mx];
int l,x,y;
int main()
{
    cin >> A;
    l = strlen(A);
    x = (l-1)/2;
    y = x+1;
    for(int i=1; i<=l; i++)
    {
        if(i%2) cout << A[x--];
        else cout << A[y++];
    }
}