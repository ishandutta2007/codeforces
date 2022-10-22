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
string s;
int mem[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>s;
    tuple<int, int, int> ans(0,0,0);
    int cnt=0;
    RE(i,n)
        if(s[i] == '(')
            cnt++;
    if(cnt == n/2 && n%2 == 0)
    RE(l,n) {
        REP(r,l,n) {
            swap(s[l], s[r]);

            int mn=INF; cnt=0;
            RE(i,n)
                mem[i] = (i==0?0:mem[i-1]) + (s[i]=='('?1:-1);
            RE(i,n)
                mn=min(mn,mem[i]);
            RE(i,n)
                if(mem[i] == mn)
                    cnt++;
            tuple<int,int,int> canst(cnt,l,r);
            ans = max(ans, canst);

            swap(s[l], s[r]);
        }
    }
    int ansA, l, r;
    tie(ansA, l, r) = ans;
    cout<<ansA<<endl<<l+1<<" "<<r+1<<endl;
}