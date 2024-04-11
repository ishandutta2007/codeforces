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
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

struct data{
    int score, diff, goal;
    data (int a = 0, int b = 0, int c = 0) {
        score = a, diff = b, goal = c;
    }
};

bool operator <(data a, data b) {
    if (a.score!=b.score) return a.score<b.score;
    if (a.diff!=b.diff) return a.diff<b.diff;
    if (a.goal!=b.goal) return a.goal<b.goal;
    return 0;
}

map<string,int> dict;
pair<data,int> pts[50];
vector<string> ans;
string ls[50], s, s1;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n;
    scanf("%d\n",&n);
    REP(i,n) {
        getline(cin,s);
        dict[s] = i; ls[i] = s;
        pts[i].sc = i; pts[i].fs = data(0,0,0);
    }
    REP(i,n*(n-1)/2) {
        int x, y, t1, t2;
        getline(cin,s,'-'); t1 = dict[s];
        getline(cin,s1,' '); t2 = dict[s1];
        scanf("%d:%d\n",&x,&y);
        if (x>y) pts[t1].fs.score+=3; else if (x==y) pts[t1].fs.score++, pts[t2].fs.score++; else pts[t2].fs.score+=3;
        pts[t1].fs.diff += x-y, pts[t2].fs.diff += y-x;
        pts[t1].fs.goal += x, pts[t2].fs.goal += y;
    }
    
    sort(pts,pts+n,greater< pair<data,int > >());
    REP(i,n/2) ans.pb(ls[pts[i].sc]);
    sort(all(ans));
    REP(i,n/2) cout << ans[i] << '\n';
    
}