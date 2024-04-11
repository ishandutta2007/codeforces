#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
#define sz size()

//===================//
//  Added libraries  //
//===================//

//===================//
//end added libraries//
//===================//

void program();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	program();
}


//===================//
//   begin program   //
//===================//

const int MX = 16, BITS=(1<<MX);
int T, n, a[MX];
int dp[MX][MX][BITS];
int value[BITS];
int ft[MX];
iii PREV[MX][MX][BITS];

void addFT(int i, int x) {
    for(i++; i<=n; i+=i&-i) ft[i] += x;
}
int getFT(int i) {
    int ans=0;
    for(i++; i; i-=i&-i) ans += ft[i];
    return ans; 
}
void merge(int i, int j) {
    cout<<i-getFT(i)+1<<" "<<j-getFT(j)+1<<endl;
    addFT(i, 1);
}
void findAns(iii p) {
    int cnt, pos, bm;
    tie(cnt, pos, bm) = p;
    if(cnt == 0) return;
    iii prev = PREV[cnt][pos][bm];
    int _cnt, _pos, _bm;
    tie(_cnt, _pos, _bm) = prev;
    int nbm = _bm^bm;
    RE(i,n) if(nbm&(1<<i)) {
        if(i == pos-1) continue;
        merge(i, pos-1);
    }
    findAns(prev);
}

void program() {
    cin>>T;
    RE(bm,BITS) RE(i,MX) dp[0][i][bm] = INF;
    dp[0][0][0] = 0;
    while(T--) {
        cin>>n;
        RE(i,n) cin>>a[i];
        int ans = 0;
        iii ansBeg;
        int bits = (1<<n);
        REP(cnt,1,n+1) RE(bm,bits) REI(pos,0,n) dp[cnt][pos][bm] = INF;
        RE(bm,bits) {
            value[bm] = 0;
            REV(i,0,n) if(bm&(1<<i)) value[bm] += a[i];
        }
        REI(cnt,0,n) REI(pos,0,n) RE(bm,bits) if(dp[cnt][pos][bm] != INF) {
            int rbm = bm^(bits-1);
            if(bm == bits-1 && ans < cnt) {
                ans     = cnt;
                ansBeg  = iii{cnt, pos, bm};
            }
            for(int nbm=rbm; nbm; nbm=((nbm-1)&rbm)) {
                if(value[nbm] <= dp[cnt][pos][bm]) continue;
                if((nbm>>pos) == 0) continue;
                int nPos = pos + __builtin_ctz(nbm>>pos) + 1;
                if(value[nbm] < dp[cnt+1][nPos][bm|nbm]) {
                    dp  [cnt+1][nPos][bm|nbm] = value[nbm];
                    PREV[cnt+1][nPos][bm|nbm] = iii{cnt, pos, bm};
                }
            }
        }
        cout<<n - ans<<endl;
        RE(i,n+1) ft[i] = 0;
        findAns(ansBeg);
    }
}