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

const int MX=1e5;
int n;
int a[MX];
int b[MX];
bool changeAble[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    RE(i,n) cin>>a[i];
    RE(i,n) {
        b[i] = a[i]/2;
        if(a[i] < 0) {
            changeAble[i] = ((a[i]-1)/2 != b[i]);
            if(changeAble[i])
                b[i]--;
        } else {
            changeAble[i] = ((a[i]+1)/2 != b[i]);
        }
    }
    int needToAdd=0;
    RE(i,n) needToAdd -= b[i];
    RE(i,n) {
        if(needToAdd == 0) break;
        if(changeAble[i])
            b[i]++, needToAdd--;
    }
    RE(i,n) cout<<b[i]<<endl;
}