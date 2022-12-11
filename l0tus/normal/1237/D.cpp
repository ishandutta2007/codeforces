#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 3e5+5;
const int INF = 1e9;
int N,A[MN],T[4*MN];

void upt(int s, int e, int x, int val, int pos)
{
    if(e<x || x<s) return;
    if(s==e){
        T[pos] = val;
        return;
    }
    int m = (s+e)/2;
    upt(s,m,x,val,2*pos);
    upt(m+1,e,x,val,2*pos+1);
    T[pos] = min(T[2*pos],T[2*pos+1]);
}

int act(int s, int e, int x, int y, int pos)
{
    if(e<x || y<s) return INF;
    if(x<=s && e<=y) return T[pos];
    int m = (s+e)/2;
    return min(act(s,m,x,y,2*pos),act(m+1,e,x,y,2*pos+1));
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> A[i];
        A[i+N] = A[i+2*N] = A[i];
    }
    priority_queue<pii> PQ;
    for(int i=1; i<=3*N; i++){
        while(PQ.size()&&PQ.top().va>2*A[i]){
            upt(1,3*N,PQ.top().vb,i-1,1);
            PQ.pop();
        }
        PQ.emplace(A[i],i);
    }
    while(PQ.size()){
        upt(1,3*N,PQ.top().vb,INF,1);
        PQ.pop();
    }
    //for(int i=1; i<=N; i++) cout << act(1,3*N,i,i,1) << '\n';
    int s,e,m;
    for(int i=1; i<=N; i++){
        s = i, e = 3*N+1;
        while(s<e){
            m = (s+e)/2;
            if(act(1,3*N,i,m,1)>m) s = m+1;
            else e = m;
        }
        if(s==3*N+1) cout << -1 << ' ';
        else cout << s-i+1 << ' ';
    }
}