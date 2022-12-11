#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 3e5+5;
const int INF = 1e9+5;
int N,P[MN],Q[MN],A[MN],D[MN],S[4*MN],T[4*MN],L[4*MN];

void bomb(int s, int e, int x, int i)
{
    int m = (s+e)/2;
    if(s==e){
        S[i]++;
        return;
    }
    if(x<=m) bomb(s,m,x,2*i);
    else bomb(m+1,e,x,2*i+1);
    S[i] = S[2*i]+S[2*i+1];
}

int sum(int s, int e, int x, int y, int i)
{
    if(e<x||y<s) return 0;
    if(x<=s&&e<=y) return S[i];
    int m = (s+e)/2;
    return sum(s,m,x,y,2*i)+sum(m+1,e,x,y,2*i+1);
}

void init(int s, int e, int i)
{
    if(s==e){
        T[i] = INF;
        S[i] = 0;
        return;
    }
    int m = (s+e)/2;
    init(s,m,2*i);
    init(m+1,e,2*i+1);
    T[i] = min(T[2*i],T[2*i+1]);
    S[i] = S[2*i]+S[2*i+1];
}

void prop(int s, int e, int i)
{
    if(s==e||L[i]==0) return;
    int v = L[i];
    L[i] = 0;
    L[2*i] += v;
    L[2*i+1] += v;
    T[2*i] += v;
    T[2*i+1] += v;
}


void upt(int s, int e, int x, int y, int v, int i)
{
    if(e<x||y<s) return;
    prop(s,e,i);
    if(x<=s&&e<=y){
        T[i] += v;
        L[i] += v;
        return;
    }
    int m = (s+e)/2;
    upt(s,m,x,y,v,2*i);
    upt(m+1,e,x,y,v,2*i+1);
    T[i] = min(T[2*i],T[2*i+1]);
}

void ass(int s, int e, int x, int v, int i)
{
    int m = (s+e)/2;
    prop(s,e,i);
    if(s==e){
        T[i] = v;
        return;
    }
    if(x<=m) ass(s,m,x,v,2*i);
    else ass(m+1,e,x,v,2*i+1);
    T[i] = min(T[2*i],T[2*i+1]);
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> P[i];
        A[P[i]] = i;
    }
    for(int i=1; i<=N; i++) cin >> Q[i];
    for(int i=N; i>=1; i--){
        bomb(1,N,A[i],1);
        D[i] = sum(1,N,A[i],N,1);
    }
    int ans = N;
    init(1,N,1);
    ass(1,N,A[ans],-D[ans],1);
    //cout << 1 << '\n';
    for(int i=1; i<=N; i++){
        //cout << T[1] << '\n';
        while(ans>1&&T[1]>=0){
            ans--;
            upt(1,N,1,A[ans]-1,-1,1);
            int v = sum(1,N,A[ans],N,1);//;
            ass(1,N,A[ans],v-D[ans],1);
        }
        upt(1,N,1,Q[i],1,1);
        bomb(1,N,Q[i],1);
        cout << ans << ' ';
    }
}