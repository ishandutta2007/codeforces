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

const int MX=2e5;
int n, k;
string s;
bitset<MX> col;
bitset<MX> chancing;

int r(int i) {return (i==n-1?0:i+1);}
int l(int i) {return (i==0?n-1:i-1);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    cin>>s;
    RE(i,n) col[i] = s[i]=='W';
    RE(i,n) chancing[i] = col[r(i)] != col[i] && col[l(i)] != col[i];
    int firstNoChance = -1;
    RE(i,n) if(!chancing[i]) firstNoChance=i;
    if(firstNoChance != -1) {
        int j=firstNoChance;
        int b=firstNoChance, len=0;
        do {
            j=r(j);
            if(!chancing[j]) {
                if(len != 0) {
                    int bCopy=r(b);
                    RE(i,min((len+1)/2, k)) {
                        chancing[bCopy] = 0;
                        col[bCopy] = col[b];
                        bCopy = r(bCopy);
                    }
                    int eCopy = l(j);
                    RE(i,min((len+1)/2, k)) {
                        chancing[eCopy] = 0;
                        col[eCopy] = col[j];
                        eCopy = l(eCopy);
                    }
                }
                len=0;
                b = j;
            } else {
                len++;
            }
        } while(j != firstNoChance);
    }
    if(k % 2) {
        RE(i,n)
            if(chancing[i])
                col[i] = !col[i];
    }
    RE(i,n) s[i] = (col[i]?'W':'B');
    cout<<s<<endl;
}