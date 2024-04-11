#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )
#define LSB(S) (S & (-S))

string ol, ig;
deque<char> a, z;

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> ol >> ig;
    int n = ol.size();

    sort(ol.begin(), ol.end());
    sort(ig.begin(), ig.end(), greater<char>());

    for (int i = 0; i < (n / 2 + n % 2); i++)
        a.push_back(ol[i]);

    for (int i = 0; i < n / 2; i++)
        z.push_back(ig[i]);

    string res(n, 0);
    int i = 0, j = n - 1;
    bool f = true;

    while ( a.size() || z.size() ) {
        if (f) {
            if ( z.size() && a.front() >= z.front() ) {
                res[j--] = a.back();
                a.pop_back();
            } else {
                res[i++] = a.front();
                a.pop_front();
            }
        } else {
            if ( a.size() && z.front() <= a.front() ) {
                res[j--] = z.back();
                z.pop_back();
            } else {
                res[i++] = z.front();
                z.pop_front();
            }
        }
        f = !f;
    }

    cout << res << endl;

    return 0;
}