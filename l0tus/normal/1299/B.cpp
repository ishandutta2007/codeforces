#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
const int MN = 1e5+5;
bool ch[MN];
pii P[MN];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int N;
    set<pii> S;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> P[i].va >> P[i].vb;
        S.insert(P[i]);
    }
    sort(P,P+N);
    int X = P[0].va+P[N-1].va;
    int Y = P[0].vb+P[N-1].vb;
    for(int i=0; i<N; i++){
        if(S.find(pii(X-P[i].va,Y-P[i].vb))==S.end()){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}