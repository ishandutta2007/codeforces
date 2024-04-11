#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=6e5;
int q;
ll n, m, cmax, c;
ll t[MX], a[MX], b[MX], T[MX], A[MX], B[MX], SA[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>q;
    while(q--) {
        cin>>n>>m>>cmax>>c;
        RE(i,n) cin>>T[i]>>A[i]>>B[i], SA[i]=i;
        sort(SA, SA+n, [](ll a, ll b) {
            return T[a] < T[b];
        });
        RE(i,n) t[i]=T[SA[i]], a[i]=A[SA[i]], b[i]=B[SA[i]];
        t[n] = m, a[n]=0, b[n]=0;
        ll payed=0, i=0;
        map<int, int> pq; pq[0] += c;
        int sum = c;
        while(i <= n) {
            int moved = t[i] - (i==0 ? 0 : t[i-1]);
            sum -= moved;
            while(moved != 0 && !pq.empty()) {
                auto it = pq.begin();
                if(it->se > moved) {
                    payed += (ll)it->fi*(ll)moved;
                    it->se -= moved;
                    moved = 0;
                } else {
                    payed += (ll)it->fi*(ll)it->se;
                    moved -= it->se;
                    pq.erase(it);
                }
            }
            if(moved != 0) {
                payed = -1;
                break;
            }
            pq[b[i]] += a[i];
            sum += a[i];
            while(sum > cmax) {
                auto it = --pq.end();
                if(sum - it->se < cmax) {
                    it->se -= sum-cmax;
                    sum = cmax;
                } else {
                    sum -= it->se;
                    pq.erase(it);
                }
            }
            i++;
        }
        cout<<payed<<endl;
    }
}