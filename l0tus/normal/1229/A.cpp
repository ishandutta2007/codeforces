#include <bits/stdc++.h>
using namespace std;
#define first va
#define second vb
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 7e3+5;
ll N,A[MN],B[MN],C[MN],cnt,pos,tmp,ans;
bool ch[MN];
vector<ll> V;
int main()
{
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> A[i];
        V.push_back(A[i]);
    }
    for(int i=1; i<=N; i++) cin >> B[i];
    sort(V.begin(),V.end());
    pos = 0;
    while(pos<N){
        cnt = V[pos];
        tmp = upper_bound(V.begin(),V.end(),cnt)-V.begin();
        if(tmp>pos+1){
            for(int i=1; i<=N; i++){
                if((A[i]|cnt)==cnt){
                    ch[i] = 1;
                }
            }
        }
        pos = tmp;
    }
    cnt = 0;
    for(int i=1; i<=N; i++){
        if(A[i]==0) ch[i] = 1;
        if(ch[i]){
            cnt++;
            ans += B[i];
        }
    }
    if(cnt>1) cout << ans;
    else cout << 0;
}