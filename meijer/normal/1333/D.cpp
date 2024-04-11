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

const int MX = 3100;
int n, k;
int minimum = 0;
int maximum = 0;
string s;
int ans[MX][MX];
int sz[MX];
set<int> nextPos;

void program() {
    cin>>n>>k>>s;
    REP(i,1,n) nextPos.insert(i);
    while(1) {
        sz[minimum] = 0;
        for(int i:nextPos) {
            if(s[i-1] == 'R' && s[i] == 'L') {
                ans[minimum][sz[minimum]++] = i;
                maximum++;
            }
        }
        if(sz[minimum] == 0) {
            break;
        } else {
            nextPos.clear();
            RE(i,sz[minimum]) {
                s[ans[minimum][i]-1] = 'L';
                s[ans[minimum][i]] = 'R';
                if(ans[minimum][i] >= 2) nextPos.insert(ans[minimum][i]-1);
                nextPos.insert(ans[minimum][i]+1);
            }
            minimum++;
            if(k < minimum || maximum > n*n) {
                cout<<-1<<endl;
                return;
            }
            assert(minimum < 3005);
        }
    }
    if(k < minimum || k > maximum) {
        cout<<-1<<endl;
        return;
    }
    int i = 0, j = 0, m = minimum;
    while(minimum < k) {
        printf("1 %d\n", ans[i][j]);
        j++;
        if(j == sz[i]) {
            i++, j=0;
            if(j == sz[i]) break;
        }
        else minimum++;
    }
    while(i < m) {
        printf("%d", sz[i]-j);
        for(; j<sz[i]; j++) printf(" %d", ans[i][j]);
        printf("\n");
        i++; j = 0;
    }
}