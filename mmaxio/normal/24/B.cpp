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
#include <string>
#include <map>
#include <algorithm>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

const int wtf[] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

struct stats{
    int place[50];
    int score;
    stats() {clean(place), score = 0;}
};

bool comp1(stats a, stats b) {//is a better than b?
    if (a.score!=b.score) return a.score>b.score;
    int i = 0;
    while (i<50 && a.place[i]==b.place[i]) i++;
    if (i==50) return 0;
    return a.place[i]>b.place[i];
}

bool comp2(stats a, stats b) {
    if (a.place[0]!=b.place[0]) return a.place[0]>b.place[0];
    return comp1(a,b);
}

map<string,stats> dict;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n, t; string s;
    scanf("%d\n",&t);
    REP(i,t) {
        scanf("%d\n",&n);
        REP(i,n) {
            getline(cin,s);
            if (i<10) dict[s].score += wtf[i];
            dict[s].place[i]++;
        }
    }
    
    stats best = dict.begin()->sc; string ans = dict.begin()->fs;
    
    for (map<string,stats>::iterator it = dict.begin(); it!=dict.end(); it++) {
        if (comp1(it->sc,best)) best = it->sc, ans = it->fs;
    }
    
    cout << ans << '\n';
    
    best = dict.begin()->sc; ans = dict.begin()->fs;
    
    for (map<string,stats>::iterator it = dict.begin(); it!=dict.end(); it++) {
        if (comp2(it->sc,best)) best = it->sc, ans = it->fs;
    }
    
    cout << ans << '\n';
    
    
}