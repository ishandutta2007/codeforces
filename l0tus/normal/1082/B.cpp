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

int N,B[mx],tmp,cnt,ans,S;
char A[mx];
vector<int> V;
queue<int> Q;
stack<int> s;
priority_queue<int> PQ;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> A;
    for(int i=0; i<N; i++)
    {
        if(A[i]=='G') S++;
    }
    if(S==0)
    {
        cout << 0;
        return 0;
    }
    for(int i=0; i<N; i++)
    {
        if(A[i]=='G') cnt++;
        else{
            if(i>=1 && i<N-1 && A[i-1]=='G' && A[i+1]=='G') tmp=cnt;
            else tmp = 0;
            cnt=0;
        }
        ans = max(ans,tmp+cnt+1);
    }
    cout << min(ans,S);
}