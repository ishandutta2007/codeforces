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

const int MX=3e5, MXK=120;
int n, k, perms, Pij, P[MX];
vi toPerm[MXK], P_[MX];
int combinePerm[MXK][MXK];
int first[MX][MXK];
map<vi, int> permToI;

void fillToPerm() {
    vi perm; RE(i,k) perm.pb(i);
    int i=0;
    do {
        toPerm[i] = perm;
        permToI[perm] = i;
        i++;
    } while(next_permutation(perm.begin(), perm.end()));
    perms = i;
}
void fillCombinePerm() {
    RE(i,perms) {
        vi permA = toPerm[i];
        RE(j,perms) {
            vi permB = toPerm[j];
            vi permC;
            RE(l,k)
                permC.pb(permA[permB[l]]);
            combinePerm[i][j] = permToI[permC];
        }
    }
}
void fillFirst() {
    int cFirst[MXK];
    RE(i,perms) cFirst[i] = -1;
    REV(i,0,n) {
        RE(j,perms) first[i][j] = cFirst[j];
        cFirst[P[i]] = i;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    fillToPerm();
    RE(i,n) RE(j,k) cin>>Pij, Pij--, P_[i].pb(Pij);
    RE(i,n) P[i] = permToI[P_[i]];
    fillCombinePerm();
    fillFirst();

    ll ans=0;
    RE(l,n) {
        //set normal bitset
        bitset<MXK> bs; bs.reset();
        int p = 0;
        while(bs[p] == 0) {
            bs[p] = 1;
            p = combinePerm[p][P[l]];
        }

        //get firsts
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        RE(i,perms)
            if(first[l][i] != -1)
                pq.push({first[l][i], i});

        //do the regions
        int r = l;
        vi helpfull; helpfull.pb(P[l]);
        while(!pq.empty()) {
            ii pr = pq.top(); pq.pop();
            if(bs[combinePerm[0][pr.se]]) continue; // it can be done from previous permutations

            //it does make a difference
            ans += bs.count()*(pr.fi-r);
            helpfull.pb(pr.se);
            queue<int> newPerms;
            RE(i,perms) if(bs[i]) newPerms.push(i);
            while(!newPerms.empty()) {
                int p = newPerms.front(); newPerms.pop();
                RE(i,helpfull.size()) {
                    int np = combinePerm[p][helpfull[i]];
                    if(!bs[np])
                        bs[np]=1, newPerms.push(np);
                }
            }
            r = pr.fi;
        }
        ans += bs.count()*(n-r);
    }
    cout<<ans<<endl;
}