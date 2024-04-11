#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppp;
const int MN = 2e5+5;
int N,A[MN],B[MN],W[MN],S[MN],E[MN];
ll ST[4*MN],L[4*MN],ans=1e18;
priority_queue<ppp,vector<ppp>,greater<ppp>> PQ;

void upt(int s, int e, int x, int y, int c, int pos)
{
    if(e<x||y<s) return;
    int m = (s+e)/2;
    if(s!=e&&L[pos]){
        L[2*pos]+=L[pos];
        L[2*pos+1]+=L[pos];
        ST[2*pos]+=L[pos];
        ST[2*pos+1]+=L[pos];
        L[pos]=0;
    }
    if(x<=s&&e<=y){
        L[pos]+=c;
        ST[pos]+=c;
        return;
    }
    upt(s,m,x,y,c,2*pos);
    upt(m+1,e,x,y,c,2*pos+1);
    ST[pos] = min(ST[2*pos],ST[2*pos+1]);

}


int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
        B[i] = A[i];
    }
    sort(B,B+N);
    for(int i=0; i<N; i++){
        S[A[i]] = i;
        E[B[i]] = i;
    }
    for(int i=0; i<N; i++){
        int c;
        cin >> c;
        W[A[i]] = c;
    }
    int cnt = 0;
    for(int i=1; i<=N; i++){
        PQ.emplace(pii(1,W[i]),pii(E[i]+1,N));
        PQ.emplace(pii(S[i]+1,-W[i]),pii(E[i]+1,N));
        PQ.emplace(pii(S[i]+1,W[i]),pii(0,E[i]));
        //PQ.emplace(pii(N,-W[i]),pii(0,E[i]));
    }
    for(int i=1; i<N; i++){
        int x,c,l,r;
        while(PQ.size()&&PQ.top().va.va==i){
            c = PQ.top().va.vb;
            l = PQ.top().vb.va;
            r = PQ.top().vb.vb;
            //cout << c << ' ' << l << ' ' << r << '\n';
            upt(0,N,l,r,c,1);
            PQ.pop();
        }
        //cout << ST[1] << '\n';
        ans = min(ans,ST[1]);
    }
    cout << ans;
}