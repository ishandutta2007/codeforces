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

const int MX = 5e5, BITS=31;
int n, a[MX];
int b[MX];
int cnt=0, base[BITS];

void addBase(int x) {
    RE(i,BITS) {
        if((x&(1<<i))==0) continue;
        if(!base[i]) {
            base[i] = x;
            cnt++;
            return;
        }
        x ^= base[i];
    }
}

void program() {
    cin>>n;
    RE(i,n) cin>>a[i];
    RE(i,n) b[i] = a[i];
    REP(i,1,n) b[i] ^= b[i-1];
    RE(i,n)
        addBase(b[i]);
    if(b[n-1] == 0) {
        cout<<-1<<endl;
    } else {
        cout<<cnt<<endl;
    }
}