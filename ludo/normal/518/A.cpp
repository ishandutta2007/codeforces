#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define INF 2147483647
#define MOD 1000000007
#define MAX 100000

typedef long long ll;
typedef pair<int, int> pii;



int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    string s, t;
    cin >> s >> t;
    if (s == t) {
        cout << "No such string" << endl;
    } else {
        int i = s.size() - 1;
        while (s[i] == 'z') {
            s[i] = 'a';
            i--;
        }
        s[i]++;
        if (s == t) {
            cout << "No such string" << endl;
        } else {
            cout << s << endl;
        }
    }
    return 0;
}