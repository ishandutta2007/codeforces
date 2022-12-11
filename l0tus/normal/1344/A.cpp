#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> ppi;
const int MN = 2e5+5;

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        int a;
        bool pos = 1;
        set<int> S;
        for(int i=0; i<N; i++){
            cin >> a;
            a += i;
            a = (a%N+N)%N;
            if(S.find(a)!=S.end()) pos = 0;
            S.insert(a);
        }
        if(pos) cout << "YES\n";
        else cout << "NO\n";
    }
}