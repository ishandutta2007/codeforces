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

const int MX=1e5;
int n;
int t[MX];
int mem1[MX], mem2[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    RE(i,n) cin>>t[i];
    mem1[n] = mem2[n] = 0;
    REV(i,0,n) mem1[i] = (t[i]==1?mem1[i+1]+1:0);
    REV(i,0,n) mem2[i] = (t[i]==2?mem2[i+1]+1:0);
    int ans=0;
    RE(i,n) {
        if(t[i] == 1) {
            if(mem1[i] <= mem2[i+mem1[i]]) ans=max(ans, mem1[i]);
        } else {
            if(mem2[i] <= mem1[i+mem2[i]]) ans=max(ans, mem2[i]);
        }
    }
    cout<<ans*2<<endl;
}