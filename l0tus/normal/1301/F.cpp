#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
const int MN = 1005;
int N,M,K,A[MN][MN],D[MN][MN][41],F[MN][MN],Q,r1,c1,r2,c2,ans;
bool ch[41];
queue<ppi> Qu[41];
vector<pii> V[41];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++){
            for(int k=1; k<=K; k++)
                D[i][j][k] = 200;
            int c;
            cin >> c;
            A[i][j] = c;
            D[i][j][c] = 0;
            Qu[c].emplace(pii(i,j),0);
            V[c].emplace_back(i,j);
        }
    for(int k=1; k<=K; k++){
        for(int i=1; i<=K; i++) ch[i] = 0;
        while(Qu[k].size()){
            pii p = Qu[k].front().va;
            int c = A[p.va][p.vb], dis = Qu[k].front().vb;
            Qu[k].pop();
            if(!ch[c]){
                for(pii q: V[c]){
                    if(D[q.va][q.vb][k]!=200) continue;
                    D[q.va][q.vb][k] = dis+1;
                    Qu[k].emplace(q,dis+1);
                }
                ch[c] = 1;
            }
            if(p.vb<M&&D[p.va][p.vb+1][k]==200){
                D[p.va][p.vb+1][k] = dis+1;
                Qu[k].emplace(pii(p.va,p.vb+1),dis+1);
            }
            if(p.vb>1&&D[p.va][p.vb-1][k]==200){
                D[p.va][p.vb-1][k] = dis+1;
                Qu[k].emplace(pii(p.va,p.vb-1),dis+1);
            }
            if(p.va<N&&D[p.va+1][p.vb][k]==200){
                D[p.va+1][p.vb][k] = dis+1;
                Qu[k].emplace(pii(p.va+1,p.vb),dis+1);
            }
            if(p.va>1&&D[p.va-1][p.vb][k]==200){
                D[p.va-1][p.vb][k] = dis+1;
                Qu[k].emplace(pii(p.va-1,p.vb),dis+1);
            }
        }
    }
    cin >> Q;
    for(int i=1; i<=Q; i++){
        cin >> r1 >> c1 >> r2 >> c2;
        ans = abs(r2-r1)+abs(c2-c1);
        for(int k=1; k<=K; k++){
            ans = min(ans,D[r1][c1][k]+D[r2][c2][k]+1);
        }
        cout << ans << '\n';
    }
}