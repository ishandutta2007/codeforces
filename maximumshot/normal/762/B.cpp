#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    int n;

    scanf("%d", &n);

    vec< pair< int, string > > arr(n);

    for(int i = 0;i < n;i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(ALL(arr));

    int cnt = 0;
    ll sum = 0;

    for(int i = 0;i < n;i++) {
        if(arr[i].second[0] == 'U') {
            if(a > 0) {
                a--;
                cnt++;
                sum += arr[i].first;
            }else if(c > 0) {
                c--;
                cnt++;
                sum += arr[i].first;
            }
        }else {
            if(b > 0) {
                b--;
                cnt++;
                sum += arr[i].first;
            }else if(c > 0) {
                c--;
                cnt++;
                sum += arr[i].first;
            }
        }
    }

    cout << cnt << " " << sum << "\n";

    return 0;
}