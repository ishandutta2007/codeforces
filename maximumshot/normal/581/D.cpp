#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = 3.1415926535897932384626433832795;

bool solve() {
        
    int x[3], y[3];

    for(int i = 0;i < 3;i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    for(int mask = 0;mask < (1 << 3);mask++) {
        for(int i = 0;i < 3;i++) {
            if((1 << i) & mask) {
                swap(x[i], y[i]);
            }
        }

        vec< pair< pair< int, int >, int> > a;

        for(int i = 0;i < 3;i++) {
            a.push_back(mp(mp(x[i], y[i]), i));
        }

        sort(ALL(a));

        //for(int i = 0;i < 3;i++) cout << a[i].first.first << " " << a[i].first.second << " " << a[i].second << '\n';

        if(a[0].first.first + a[1].first.first == a[2].first.first) {
            int d = a[2].first.first;
            if(a[0].first.second == a[1].first.second && a[0].first.second + a[2].first.second == d) {
                vec< vec< int > > ans(d + 1, vec< int >(d + 1));
                // 1
                for(int k1 = 1;k1 <= a[0].first.first;k1++) 
                    for(int k2 = 1;k2 <= a[0].first.second;k2++) 
                        ans[k1][k2] = a[0].second;
                // 2
                for(int k1 = a[0].first.first + 1;k1 <= d;k1++) {
                    for(int k2 = 1;k2 <= a[1].first.second;k2++) {
                        ans[k1][k2] = a[1].second;
                    }
                }
                // 3
                for(int k1 = 1;k1 <= d;k1++) {
                    for(int k2 = a[0].first.second + 1;k2 <= d;k2++) {
                        ans[k1][k2] = a[2].second;
                    }
                }
                cout << d << '\n';
                for(int k1 = 1;k1 <= d;k1++) {
                    for(int k2 = 1;k2 <= d;k2++) {
                        cout << char('A' + ans[k1][k2]);
                    }
                    cout << '\n';
                }
                return true;
            }
        }

        if(a[0].first.first == a[1].first.first && a[0].first.first == a[2].first.first) {
            int d = a[0].first.first;
            if(a[0].first.second + a[1].first.second + a[2].first.second == d) {
                vec< vec< int > > ans(d + 1, vec< int >(d + 1));
                // 1
                for(int k1 = 1;k1 <= d;k1++) 
                    for(int k2 = 1;k2 <= a[0].first.second;k2++) 
                        ans[k1][k2] = a[0].second;
                // 2
                for(int k1 = 1;k1 <= d;k1++) {
                    for(int k2 = a[0].first.second + 1;k2 <= a[0].first.second + a[1].first.second;k2++) {
                        ans[k1][k2] = a[1].second;
                    }
                }
                // 3
                for(int k1 = 1;k1 <= d;k1++) {
                    for(int k2 = a[0].first.second + a[1].first.second + 1;k2 <= d;k2++) {
                        ans[k1][k2] = a[2].second;
                    }
                }
                cout << d << '\n';
                for(int k1 = 1;k1 <= d;k1++) {
                    for(int k2 = 1;k2 <= d;k2++) {
                        cout << char('A' + ans[k1][k2]);
                    }
                    cout << '\n';
                }
                return true;
            }
        }

        for(int i = 0;i < 3;i++) {
            if((1 << i) & mask) {
                swap(x[i], y[i]);
            }
        }
    }

    puts("-1");

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}