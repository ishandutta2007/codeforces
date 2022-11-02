#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inft = 1000000009;
const int MAXN = 1000006;
const int MOD = 1000000009;

map<pii, int> M;
vector<pii> A;
vi mark;

vi getdown(int i) {
    int x = A[i].x, y = A[i].y;
    vi ans;
    for(int h=-1; h<=1; h++) {
        if(M.find(pii(x+h,y-1)) != M.end()) ans.pb(M[pii(x+h,y-1)]);
    }
    return ans;
}
vi getup(int i) {
    int x = A[i].x, y = A[i].y;
    vi ans;
    for(int h=-1; h<=1; h++) {
        if(M.find(pii(x+h,y+1)) != M.end()) ans.pb(M[pii(x+h,y+1)]);
    }
    return ans;
}
void remark(int i) {
    if(mark[i] == -1) return;
    vi CU = getup(i);
    mark[i]=0;
//    printf("up: "); tr(it, CU) printf("%d ",*it); puts("");
    tr(it, CU) if(getdown(*it).size()==1) mark[i]++;
}

void solve() {
    int n;
    scanf("%d",&n);
    A.resize(n);
    fru(i,n) {
        int x,y;
        scanf("%d%d",&x,&y);
        M[pii(x,y)] = i;
        A[i] = pii(x,y);
    }
    mark.resize(n,0);
    fru(i,n) remark(i);
    set<int> S;
    fru(i,n) if(mark[i]==0) S.insert(i);
//    fru(i,n) printf("%d ",mark[i]);
    ll ans = 0;
    fru(_,n) {
        assert(!S.empty());
        int take;
        if(_%2==0) { // max
            take = *(S.rbegin());
        } else { // min
            take = *(S.begin());
        }
//        printf("take %d\n", take);
        S.erase(take);
        vi CU = getup(take), CD = getdown(take);
        bool ok = true;
        tr(it, CU) if(getdown(*it).size() == 1) ok = false;
        if(!ok) { _--; continue; }
        mark[take] = -1;
        M.erase(pii(A[take].x,A[take].y));
        tr(it, CD) remark(*it);
        tr(it, CD) if(mark[*it]==0) S.insert(*it);
        ans = (ans * n + take) % MOD;
    }
    cout << ans << endl;
}

int main() {
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int t=1;
//	scanf("%d",&t);
	fru(i,t) solve();
	return 0;
}