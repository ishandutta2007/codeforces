#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const LL MOD = inf + 9;
const double pi = acos(-1.0);

using namespace std;

template<typename T, typename P>
const ostream & operator << (ostream & os, const pair<T, P> & a) {
    os.precision(10);
    os << fixed;
    os << a.first;
    os << ' ';
    os << a.second;
    os << ' ';
    return os;
}

template<typename T> struct ExtrQueue{
    stack< pair<T, pair<T, T>> > a, b; // {key, {min, max}}

    ExtrQueue () {
        while(!a.empty()) a.pop();
        while(!b.empty()) b.pop();
    }

    void push(const T & key) {
        if(a.empty()) {
            a.push(mp(key, mp(key, key)));
        }else {
            T x = a.top().second.first;
            T y = a.top().second.second;
            x = min(x, key);
            y = max(y, key);
            a.push(mp(key, mp(x, y)));
        }
    }

    void reBuild() {
        if(!b.empty()) return;
        if(a.empty())  return;
        b.push(mp(a.top().first, mp(a.top().first, a.top().first))); 
        a.pop();
        while(!a.empty()) {
            T x = a.top().first;
            T mn = min(x, b.top().second.first);
            T mx = max(x, b.top().second.second);
            b.push(mp(x, mp(mn, mx)));
            a.pop();
        }
    }

    void pop() {
        reBuild();
        if(!b.empty()) b.pop();
    }

    T getMin() {
        if(a.empty() || b.empty()) {
            return (a.empty()?b.top().second.first : a.top().second.first);
        }else {
            T x, y;
            x = a.top().second.first;
            y = b.top().second.first;
            return min(x, y);
        }
    }

    T getMax() {
        if(a.empty() || b.empty()) {
            return (a.empty()?b.top().second.second : a.top().second.second);
        }else {
            T x, y;
            x = a.top().second.second;
            y = b.top().second.second;
            return max(x, y);
        }
    }

    void show() {
        stack<T> ta = a;
        stack< pair<T, pair<T, T> > > tb = b;
        while(!ta.empty()) cout << ta.top() << ' ', ta.pop();
        vec<T> ans;
        while(!tb.empty()) ans.push_back(tb.top().first), tb.pop();
        reverse(ALL(ans));
        for(int i(0);i < (int)ans.size();i++) cout << ans[i] << ' ';
        cout << '\n';
    }
};

bool solve()
{
    int n, delt;
    scanf("%d %d", &n, &delt);

    vec<int> a(n);
    for(int i(0);i < n;i++) {
        scanf("%d", &a[i]);
    }

    int index = 0, ans = 0, cnt = 0;

    ExtrQueue<int> q;
    q.push(a[0]);
    
    vec<int> maxLen(n, 0);

    for(int i(0);i < n;i++) {
        if(index < i) {
            q.push(a[i]);
            index = i;
        }
        //cout << i << " : ";
        while(index + 1 < n) {
            //cout << "{" << index << ", " << q.getMin() << ' ' << q.getMax() << "} ";
            int tmp = max(q.getMax(), a[index + 1]) - min(q.getMin(), a[index + 1]);
            if(tmp > delt) break;
            q.push(a[index + 1]);
            index++;
        }
        //cout << '\n';
        // [i .. index]
        maxLen[i] = index - i + 1;

        q.pop();
        if(maxLen[i] > ans) {
            ans = maxLen[i];
            cnt = 1;
        }else if(maxLen[i] == ans){
            cnt++;
        }
    }

    printf("%d %d\n", ans, cnt);

    for(int i(0);i < n;i++) {
        if(maxLen[i] == ans) {
            printf("%d %d\n", i + 1, i + ans);
        }
    }

    return true;
}   

int main() 
{
    //while(solve());
    solve();
    
    return 0;
}