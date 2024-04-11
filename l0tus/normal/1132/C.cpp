#include <bits/stdc++.h>
using namespace std;
#define va first
#define vb second
typedef long long ll;
typedef pair<int,int> pii;
using namespace std;
const int MN = 5010;
const int INF = 1e9;

int A[MN],B[MN],N,M,K,cnt,tmp,ans,val,D[MN][MN],C[MN];
string S;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> A[i] >> B[i];
    }
    cnt = N;
    for(int i=1; i<=N; i++){
        vector<int> V;
        for(int j=0; j<M; j++){
            if(A[j]<=i && i<=B[j]) V.push_back(j);
        }
        if(V.size()>2) continue;
        if(V.size()==2){
            D[V[0]][V[1]]++;
        }
        if(V.size()==1){
            C[V[0]]++;
        }
        if(V.size()==0) cnt--;
    }
    for(int i=0; i<M; i++)
    for(int j=i+1; j<M; j++){
        ans = max(ans,cnt-C[i]-C[j]-D[i][j]);
    }
    cout << ans;
}