#include <bits/stdc++.h>
#define va first
#define vb second
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;

const int MN = 3e5+5;
const int MOD = 1e9+7;
const int INF = 1e9;

int pos[MN],d[MN],A[MN],x[MN],y[MN],v[MN];

int main()
{
    #ifdef L0TUS
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\input.txt", "r", stdin);
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\output.txt", "w", stdout);
    #endif
    
    ios_base::sync_with_stdio(0),cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        int q = 0, sum = 0;
        priority_queue<pii,vector<pii>,greater<pii>> PQ;
        for(int i=1; i<=N; i++){
            cin >> A[i];
            sum += A[i];
        }
        if(sum%N){
            cout << -1 << '\n';
            continue;
        }

        int d = sum/N;

        for(int i=N; i>=1; i--){
            if(A[i]>=i){
                x[q] = i;
                y[q] = 1;
                v[q] = A[i]/i;
                A[i] -= v[q]*i;
                A[1] += v[q]*i;
                q++;
                break;
            }
        }

        for(int i=2; i<=N; i++){
            PQ.emplace(i-A[i]%i,i);
        }

        while(PQ.size()){
            pii p = PQ.top();
            //cout << p.va << '\n';
            PQ.pop();
            if(p.va<=A[1]){
                if(p.va>0){
                    x[q] = 1;
                    y[q] = p.vb;
                    v[q] = p.va;
                    A[p.vb] += v[q];
                    A[1] -= v[q];
                    q++;           
                }
                x[q] = p.vb;
                y[q] = 1;
                v[q] = A[p.vb]/p.vb;
                A[p.vb] -= v[q]*p.vb;
                A[1] += v[q]*p.vb;
                q++;
            }
        }
        //cout << A[1] << '\n';

        bool fail = 0;
        for(int i=2; i<=N; i++){
            if(A[i]>d){
                fail = 1;
                break;
            }
            x[q] = 1;
            y[q] = i;
            v[q] = d-A[i];
            A[i] += v[q];
            A[1] -= v[q];
            q++;
        }
        if(fail){
            cout << -1 << '\n';
            continue;
        }
        cout << q << '\n';
        for(int i=0; i<q; i++) cout << x[i] << ' ' << y[i] << ' ' << v[i] << '\n';
    }
}