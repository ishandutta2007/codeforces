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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

const int MX = 5e5;
int testCases;
int n, k, a[MX];
int cnt[MX];
int cnt1[MX];

int MAX[MX*4], MIN[MX*4];
void buildSeg(int p=0, int l=0, int r=n-1) {
    if(l == r) {
        MAX[p] = cnt[l];
        MIN[p] = cnt[l];
        return;
    }
    int m=(l+r)/2;
    buildSeg(p*2+1,l,m);
    buildSeg(p*2+2,m+1,r);
    MAX[p] = max(MAX[p*2+1], MAX[p*2+2]);
    MIN[p] = max(MIN[p*2+1], MIN[p*2+2]);
}
int getMax(int i, int j, int p=0, int l=0, int r=n-1) {
    if(j < r || i > r) return -INF;
    if(i <= l && j >= r) return MAX[p];
    int m=(l+r)/2;
    int a = getMax(i,j,p*2+1,l,m);
    int b = getMax(i,j,p*2+2,m+1,r);
    return max(a,b);
}
int getMin(int i, int j, int p=0, int l=0, int r=n-1) {
    if(j < r || i > r) return INF;
    if(i <= l && j >= r) return MIN[p];
    int m=(l+r)/2;
    int a = getMin(i,j,p*2+1,l,m);
    int b = getMin(i,j,p*2+2,m+1,r);
    return min(a,b);
}

void program() {
    cin>>testCases;
    while(testCases--) {
        cin>>n>>k;
        RE(i,n) cin>>a[i];
        RE(i,n) {
            if(a[i] == k) a[i] = 1;
            else if(a[i] < k) a[i] = 0;
            else a[i] = 2;
        }
        RE(i,n) cnt[i] = (i==0?0:cnt[i-1])+(a[i]>=1?1:-1);
        RE(i,n) cnt1[i] = (i==0?0:cnt1[i-1])+(a[i]==1?1:0);
        buildSeg();
        bool pos = 0;
        RE(i,n) {
            if(a[i] == 0) continue;
            if(i != n-1) if(getMax(i+1,n-1)-cnt[i] >= 0) pos = 1;
            if(i != 0) if(cnt[i-1]-min(0,getMin(0,i-2)) >= 0) pos = 1;
        }
        if(cnt1[n-1] == 0) pos = 0;
        if(n == 1 && a[0] == 1) pos = 1;
        cout<<(pos?"yes":"no")<<endl;
    }
}