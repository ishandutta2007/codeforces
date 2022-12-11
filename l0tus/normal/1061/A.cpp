#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
const int INF = 1e9;
const int mx = 1e5;

struct C{
    int a,b;
    C(){};
    C(int a,int b):a(a),b(b){};
    bool operator < (const C &X) const{
        return a<X.a;
    }
};

int N,S,A[mx],B[mx];
vector<int> V;
queue<int> Q;
stack<int> s;
priority_queue<int> PQ;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> S;
    cout << (S+N-1)/N;
}