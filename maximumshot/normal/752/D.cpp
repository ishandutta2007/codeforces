#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const MAX_LEN = 100005;

char buffer[MAX_LEN];

inline void readLine(string & s) {
    scanf("%s", buffer);
    s = buffer;
}

inline bool check_palindrome(const string & s) {
    for(int i = 0;i < (int)s.size() / 2;i++) {
        if(s[i] != s[(int)s.size() - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int main() {

    int k, n;

    scanf("%d %d", &k, &n);

    vec< pair< string, int > > a(k);

    map< string, vec< int > > arr;

    for(int i = 0;i < k;i++) {
        readLine(a[i].first);
        scanf("%d", &a[i].second);
        arr[ a[i].first ].push_back( a[i].second );
    }

    sort(ALL(a));

    int res = 0;

    vec< pii > mas;

    set< string > used;

    for(auto & i : arr) {
        sort(ALL(i.second));
        reverse(ALL(i.second));
    }

    for(auto i : arr) {
        if( check_palindrome(i.first) ) {
            for(int iter = 0;iter + 1 < (int)i.second.size();iter += 2) {
                if(i.second[iter] >= 0 && i.second[iter + 1] >= 0) {
                    res += i.second[iter] + i.second[iter + 1];
                    continue;
                }
                if(i.second[iter] < 0 && i.second[iter + 1] < 0) {
                    break;
                }
                mas.push_back( make_pair( i.second[iter] + i.second[iter + 1], i.second[iter] ) );
            }
            if((int)i.second.size() % 2) {
                if(i.second.back() >= 0) {
                    mas.push_back( make_pair( -inf + i.second.back(), i.second.back() ) );
                }
            }
        }else {
            if(used.count( i.first )) continue;
            string tmp = i.first;
            reverse(ALL(tmp));
            if(!arr.count( tmp )) continue;
            used.insert( i.first );
            used.insert( tmp );
            auto & arr1 = i.second;
            auto & arr2 = arr[ tmp ];
            for(int iter = 0;iter < (int)arr1.size() && iter < (int)arr2.size();iter++) {
                if(arr1[iter] + arr2[iter] >= 0) {
                    res += arr1[iter] + arr2[iter];
                }
            }
        }
    }

    int tot = 0;

    for(auto i : mas) {
//        cout << i.first << " " << i.second << "\n";
        if(i.first >= 0) {
            tot += i.first;
        }
    }

    int add = 0;

    for(auto i : mas) {
        if(i.first >= 0) {
            tot -= i.first;
        }
        add = max(add, tot + i.second);
        if(i.first >= 0) {
            tot += i.first;
        }
    }

    printf("%d\n", res + add);

    return 0;
}