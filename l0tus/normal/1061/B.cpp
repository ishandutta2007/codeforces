#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
const int INF = 1e9;
const int mx = 2e5;
typedef long long ll;
struct C{
    int a,b;
    C(){};
    C(int a,int b):a(a),b(b){};
    bool operator < (const C &X) const{
        return a<X.a;
    }
};

ll N,M,A[mx],B[mx],sum=0,S=0;
vector<int> V;
queue<int> Q;
stack<int> s;
priority_queue<int> PQ;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin>>A[i];
        sum+=A[i];
    }
    sort(A,A+N,greater<ll>());
    A[N]=0;
    ll h = A[0];
    for(int i=0;i<N;i++){
        if(A[i]==0) break;
        S+=max(h-A[i+1],1ll);
        h-=max(h-A[i+1],1ll);
    }
    cout << sum-S;
}