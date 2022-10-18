#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(v) (int(v.size()))
#define pch putchar
#define gch getchar()
#define FORD(i,a,b) for (int i=(a); i<=(b); i++)
#define FORP(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,n) for (int i=0; i<(n); i++)
#define clean(v) memset(v,0,sizeof(v))

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

string s, tmp;
stack<int> st;

vector<int> get(string &s, string sub) {
    vector<int> res;
    int cur = 0;
    do {
        cur = s.find(sub, cur);
        //cerr << cur << ' ';
        if (cur >= 0) res.pb(cur);
        cur++;
    } while (cur > 0);
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    while (cin >> tmp) s += tmp;
    //cerr << s;
    vector<int> p1 = get(s, "<table>");
    vector<int> p2 = get(s, "</table>");
    vector<int> p3 = get(s, "<td>");

    int uk1 = 0, uk2 = 0, uk3 = 0;
    int ans[10000];
    clean(ans);
                                        
    while (uk3 < sz(p3)) {
        int best = p3[uk3];
        int who = 3;
        if (uk1 < sz(p1) && p1[uk1] < best) {
            best = p1[uk1];
            who = 1;
        }
        if (uk2 < sz(p2) && p2[uk2] < best) {
            best = p2[uk2];
            who = 2;
        }
        if (who == 1) {
            st.push(uk1);
            uk1++;
        } else if (who == 2) {
            st.pop();
            uk2++;
        } else if (who == 3) {
            ans[st.top()]++;
            uk3++;
        }
    }

    sort(ans, ans + sz(p1));

    REP(i, sz(p1)) printf("%d ",ans[i]);

}