#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1001111, inf = 1000111222;

int m[max_n];
vector<int> odd;
int main()
{
    //freopen("input.txt", "r", stdin);
    int s = 0;
    int n;
    cin >> n;
    for (int i =0; i < n; ++i) {
        cin >> m[i];
        if (abs(m[i]) % 2 == 1) {
            odd.PB(i);
        }
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (m[i] % 2 == 0) {
            m[i] /= 2;
        } else if (m[i] > 0) {
            m[i] /= 2;
        } else {
            m[i] = -(abs(m[i]) / 2 + 1);
        }
        sum += m[i];
    }
    if (sum > 0) {
        exit(228);
    }
    sum = abs(sum);
    if (sum > odd.size()) {
        exit(228);
    }
    for (int i = 0; i < sum; ++i) {
        m[odd[i]]++;
    }
    for (int i = 0; i < n; ++i) {
        cout << m[i] << ' ';
    }


    return 0;
}