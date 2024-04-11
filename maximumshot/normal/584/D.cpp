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
typedef double LD;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
 
bool solve()
{
    int ok = 1;

    int n;

    cin >> n;

    for(int i = 2;i * i <= n;i++) {
        if(n % i == 0) {
            ok = 0;
            break;
        }
    }

    if(ok) {
        cout << 1 << '\n' << n << '\n';
        return true;
    }

    vec< int > prime(1e4, 1);
    prime[0] = prime[1] = 0;
    for(int i = 2;i * i < 1e4;i++) {
        if(!prime[i]) continue;
        for(int j = i * i;j < 1e4;j += i) prime[j] = 0;
    }

    for(int i = 2;i < 250;i++) {

        if(!prime[i]) continue;

        if(i > n) break;

        int value = n - i;

        ok = 1;
        for(int j = 2;j * j <= value;j++) {
            if(value % j) continue;
            ok = 0;
            break;
        }

        if(ok) {
            cout << 2 << "\n" << i << " " << n - i << '\n';
            return true;
        }

        for(int j = 2;j < 250;j++) {
            if(!prime[i] || !prime[j]) continue;
            if(i + j == n) {
                cout << 2 << "\n" << i << " " << j << '\n';
                return true;
            }

            if(i + j > n) break;
            
            ok = 1;
            for(int d = 2;d * d <= n - i - j;d++) {
                if((n - i - j) % d) continue;
                ok = 0;
                break;
            }

            if(ok) {
                cout << 3 << "\n" << i << " " << j << " " << n - i - j << '\n';
                return true;
            }
        }
    }

    cout << -1 << '\n';

    return true;
} 

int main() {

    //while(solve());
    solve();

    return 0;
}