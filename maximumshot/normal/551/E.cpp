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
#include <list>

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
const double pi = acos(-1.0);

using namespace std;

template<typename T, typename P>
const ostream & operator << (ostream & os, const pair<T, P> & a) {
    os.precision(10);
    os << fixed;
    os << a.first;
    os << ' ';
    os << a.second;
    os << '\n';
    return os;
}

int bpLeft(const vec< pair<LL, int> > & a, LL value) {
    if(a.empty()) return -1;
    int l, r, m;
    l = 0, r = (int)a.size() - 1;
    while(r - l > 1) {
        m = (l + r) >> 1;
        if(a[m].first >= value) r = m;
        else l = m + 1;
    }
    if(a[l].first == value) return a[l].second;
    else if(a[r].first == value) return a[r].second;
    else return -1;
}

int bpRight(const vec< pair<LL, int> > & a, LL value) {
    if(a.empty()) return -1;
    int l, r, m;
    l = 0, r = (int)a.size() - 1;
    while(r - l > 1) {
        m = (l + r) >> 1;
        if(a[m].first <= value) l = m;
        else r = m - 1;
    }
    if(a[r].first == value) return a[r].second;
    else if(a[l].first == value) return a[l].second;
    else return -1;
}

int n, q, BlockSize, BlockCnt;
vec< LL > a;
vec< vec< pair<LL, int> > > mas;
vec< LL > delt; 

void build() {
    BlockSize = ceil(sqrt((LD)n));
    BlockCnt = (n / BlockSize) + (n % BlockSize > 0);
    mas.resize(BlockCnt);
    delt.resize(BlockCnt);
    for(int i(0);i < n;i++) {
        mas[i / BlockSize].push_back(mp(a[i], i));
    }
    for(int i(0);i < BlockCnt;i++) {
        sort(ALL(mas[i]));
    }
}

void update(int l, int r, LL value) {
    int LeftBlock = l / BlockSize;
    int RightBlock = r / BlockSize;
    bool ok = 0;
    if(LeftBlock * BlockSize != l) {
        ok = 1;
        for(int i(0);i < (int)mas[LeftBlock].size();i++) {
            int id = mas[LeftBlock][i].second;
            if(l <= id && id <= r) {
                mas[LeftBlock][i].first += value;
            }
        }
        sort(ALL(mas[LeftBlock]));
        LeftBlock++;
    }

    if((RightBlock + 1) * BlockSize - 1 != r) {
        if(ok) {
            if(LeftBlock - 1 == RightBlock) {
            }else {
                for(int i(0);i < (int)mas[RightBlock].size();i++) {
                    int id = mas[RightBlock][i].second;
                    if(l <= id && id <= r) {
                        mas[RightBlock][i].first += value;
                    }
                }
            }
        }else {
            for(int i(0);i < (int)mas[RightBlock].size();i++) {
                int id = mas[RightBlock][i].second;
                if(l <= id && id <= r) {
                    mas[RightBlock][i].first += value;
                }
            }
        }
        sort(ALL(mas[RightBlock]));
        RightBlock--;
    }

    for(int i(LeftBlock);i <= RightBlock;i++) delt[i] += value;
}

int get_Ans(LL value) {
    int L = inf, R = -inf;
    for(int i(0);i < BlockCnt;i++) {
        int idL, idR;
        idL = bpLeft(mas[i], value - delt[i]);
        idR = bpRight(mas[i], value - delt[i]);
        if(idL != -1) L = min(L, idL);
        if(idR != -1) R = max(R, idR);
    }   
    //cout << L << ' ' << R << '\n';
    if(L == inf || R == -inf) return -1;
    else return (R - L);
}

void show() {
    cout << "\n-------------\n";
    for(int i(0);i < BlockCnt;i++) {
        cout << delt[i] << " : ";
        for(int j(0);j < (int)mas[i].size();j++) cout << mas[i][j].first << ' ';
        cout << '\n';
    }
    cout << "\n-------------\n";
}

bool solve()
{
    scanf("%d %d", &n, &q);

    a.resize(n);

    for(int i(0);i < n;i++) {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }

    build();

    for(int i(0);i < q;i++) {
        //show();
        int type;
        scanf("%d", &type);
        if(type == 1) {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            l--, r--;
            update(l, r, x);
        }else {
            int y;
            scanf("%d", &y);
            printf("%d\n", get_Ans(y));
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