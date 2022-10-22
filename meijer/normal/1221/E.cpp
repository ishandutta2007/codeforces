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
int q, a, b, N;
vi l;
int t1, t2, t3, t3size;
string s;

void updateLengths() {
    l.clear();
    int beg=0;
    RE(i,s.size()) {
        if(s[i] == 'X') {
            if(i-beg >= b) l.pb(i-beg);
            beg=i+1;
        }
    }
    if(s.size()-beg >= b) l.pb(s.size()-beg);

    t1=t2=t3=0; N=l.size();
    RE(i,N) {
        if(l[i] < a) t1++;
        if(l[i] >= a && l[i] < 2*b) t2++;
        if(l[i] >= 2*b) t3++, t3size=l[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>q;
    while(q--) {
        cin>>a>>b>>s;
        updateLengths();
        if(t1 != 0 || t3 > 1) {
            cout<<"NO"<<endl;
        } else
        if(t3 == 1) {
            bool pos=0;
            RE(i,t3size-a+1) {
                int sz1 = t3size-a-i;
                int sz2 = i;
                if(sz1 >= 2*b || sz2 >= 2*b) continue;
                if((sz1 < a && sz1 >= b) || (sz2 < a && sz2 >= b)) continue;
                int new2sz = 0;
                if(sz1 >= a) new2sz++;
                if(sz2 >= a) new2sz++;
                if((t2+new2sz)%2 == 0) pos = 1;
            }
            cout<<(pos ? "YES" : "NO")<<endl;
        } else {
            cout<<(t2%2 ? "YES" : "NO")<<endl;
        }
    }
}