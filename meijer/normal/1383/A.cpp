#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> lll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<lll> vlll;
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

const int MX = 100;
int testCases;
int n;
string a, b;
vi adj[MX];
bitset<MX> used;

int p[MX], r[MX], sets;
void buildDSU(int dsuSize) {
    RE(i,dsuSize) p[i]=i, r[i]=0;
    sets = dsuSize;
}
int getSet(int i) {return i==p[i]?i:p[i]=getSet(p[i]);}
bool isSameSet(int i, int j) {return getSet(i)==getSet(j);}
void unionSet(int i, int j) {
    if(!isSameSet(i,j)) {
        i=p[i], j=p[j];
        sets--;
        if(r[i] > r[j]) {
            p[j] = i;
        } else {
            p[i] = j;
            if(r[i] == r[j]) r[j]++;
        }
    }
}

void program() {
    cin>>testCases;
    while(testCases--) {
        cin>>n>>a>>b;
        RE(i,n) a[i]-='a';
        RE(i,n) b[i]-='a';

        bool pos=1;
        RE(i,n) if(a[i] > b[i]) pos = 0;
        if(!pos) {
            cout<<-1<<endl;
            continue;
        }

        used.reset();
        buildDSU(20); sets = 0; int alf=0;
        RE(i,n) if(a[i] != b[i]) {
            if(!used[a[i]]) used[a[i]]=1, sets++, alf++;
            if(!used[b[i]]) used[b[i]]=1, sets++, alf++;
            unionSet(a[i], b[i]);
        }

        cout<<alf-sets<<endl;
    }
}