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

const int MX=1e6, BS=1<<20;

string s;
bitset<BS> found;
int mem[BS];
int n;

int getMem(int bs) {
    if(mem[bs] == -1) {
        mem[bs] = 0;
        RE(i,20) {
            if((bs & (1<<i)) == 0) continue;
            mem[bs] = max(mem[bs], getMem(bs ^ (1<<i)));
        }
    }
    return mem[bs];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s; n=s.size();
    found.reset();
    RE(i,BS) mem[i] = -1;
    RE(i,n) {
        int used=0;
        REP(j,i,n) {
            int numb = s[j]-'a';
            if((used & (1<<numb)) != 0) break;
            used |= (1<<numb);
            found[used] = 1;
            mem[used] = j-i+1;
        }
    }
    int ans=0;
    RE(i,BS) {
        if(found[i]) {
            int neg = (~(i)) & ((1<<20)-1);
            ans = max(ans, getMem(i) + getMem(neg));
        }
    }
    cout<<ans<<endl;
}