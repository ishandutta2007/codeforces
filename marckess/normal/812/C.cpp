#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )
#define LSB(S) (S & (-S))

ll n, res, s;
ll v[100005];

ll esPos(ll k) {
    priority_queue<ll> pq;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        pq.push(v[i] + i * k);
        sum += v[i] + i * k;
        if ( pq.size() > k ){
            sum -= pq.top();
            pq.pop();
        }
    }
    return sum;
}

int bb () {
    ll i = 0, j = n + 1, m = (i + j) / 2;
    for (int k = 0; k < 18; k++) {
        ll aux = esPos(m);
        if ( aux <= s ){
            res = aux;
            i = m;
        }
        else
            j = m;
        m = (i + j) / 2;
    }
    return m;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s;
    for(int i = 1; i <= n; i++)
        cin >> v[i];

    res = bb();
    cout << res << " " << esPos(res) << endl;

    return 0;
}