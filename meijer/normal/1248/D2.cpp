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

const int MX=4e5;
int n, opening=0, mn=INF, mnBegin;
int sum[MX], SUM[MX], X[MX], Y[MX], x, y;
int cnt1[MX], cnt2[MX];
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>s;
    RE(i,n) if(s[i] == '(') opening++;
    if(opening != n/2 || n%2 == 1) {
        cout<<0<<endl;
        cout<<"1 1"<<endl;
        return 0;
    }
    RE(i,n)
        sum[i] = (i==0?0:sum[i-1]) + (s[i]=='('?1:-1);
    RE(i,n)
        mn = min(mn, sum[i]);
    RE(i,n)
        if(sum[i] == mn)
            mnBegin = i;
    RE(i,n)
        SUM[i] = sum[(i+mnBegin)%n] - mn;
    RE(i,n)
        if(SUM[i] == 0)
            X[x++] = i;
    X[x++] = n;
    RE(i,n)
        if(SUM[i] == 1)
            Y[y++] = i;
    cnt1[0] = 0;
    RE(i,n) cnt1[i+1] = cnt1[i]+int(SUM[i]==1);
    cnt2[0] = 0;
    RE(i,n) cnt2[i+1] = cnt2[i]+int(SUM[i]==2);

    tuple<int, int, int> ans(x-1,0,0);
    RE(i,x-1)
        ans = max(ans, make_tuple(cnt1[X[i+1]]-cnt1[X[i]],X[i]+1,X[i+1]));
    RE(i,y-1)
        if(SUM[(Y[i]+1)%n] != 0)
            ans = max(ans, make_tuple(x-1+cnt2[Y[i+1]]-cnt2[Y[i]],Y[i]+1,Y[i+1]));

    int ansA, l, r;
    tie(ansA, l, r) = ans;
    l = (l+n+mnBegin)%n;
    r = (r+n+mnBegin)%n;
    cout<<ansA<<endl<<l+1<<" "<<r+1<<endl;
}