#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

int main() {
    ios_base::sync_with_stdio(false);
    map<pair<string, string>, int> lastMessage;
    int n, d;
    cin >> n >> d;
    vector<pair<string, string> > waiting;
    int waitingTime = -1;
    set<pair<string, string> > friends;
    for (int i = 0; i < n; ++i) {
        string a, b;
        int time;
        cin >> a >> b >> time;
        if (waitingTime < time) {
            FORE (it, waiting) {
                lastMessage[*it] = waitingTime;
            }
            waiting.clear();
            waitingTime = time;
        }
        if (lastMessage.find(MP(b, a)) != lastMessage.end() && lastMessage[MP(b, a)] >= time - d) {
            friends.insert(MP(min(a, b), max(a, b)));
        }
        waiting.PB(MP(a, b));
    }
    cout << friends.size() << "\n";
    FORE (it, friends) {
        cout << it->ST << " " << it->ND << "\n";
    }
}