#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> ppi;
const int MN = 2e5+5;
pii P[MN];
ll ans;
bool ch[MN];

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> P[i].va;
        P[i].va = -P[i].va;
    }
    for(int i=1; i<=N; i++) cin >> P[i].vb;
    sort(P+1,P+N+1,greater<pii>());
    priority_queue<ll> PQ;
    PQ.emplace(P[1].vb);
    ll cur = P[1].va, pos = 1, sum = P[1].vb;
    while(1){
        while(pos<N&&P[pos+1].va==cur){
            ++pos;
            sum += P[pos].vb;
            PQ.emplace(P[pos].vb);
        }
        if(PQ.size()==1){
            sum -= PQ.top();
            PQ.pop();
            if(pos==N) break;
            ++pos;
            sum += P[pos].vb;
            PQ.emplace(P[pos].vb);
            cur = P[pos].va;
            continue;
        }
        sum -= PQ.top();
        ans += sum;
        --cur;
        PQ.pop();
    }
    cout << ans;
}