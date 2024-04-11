
#include <bits/stdc++.h>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORK(i, k, n) for(int i = k; i < n; i++)
#define FORr(i, n) for(int i = n - 1; i >= 0; i--)
#define FORKr(i, k, n) for(int i = n - 1; i >= k; i--)
#define PRINT(a, b) copy((a), (b), ostream_iterator<int>(cout, " "))
#define all(a) a.begin(), a.end()
#define in(a, b) ((b).find(a) != (b).end())
#define sz(a) ((int) (a).size())
#define Mp make_pair
#define PII pair<int, int>
#define LL long long
#define VI vector<int>

using namespace std;

const int MAX_N = 1e5 + 5;
int n;
int a[MAX_N];

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n;
    int mymax = -1;
    int mycount = 0;
    int maxcount = 0;
    FOR(i, n) {
        cin >> a[i];
        if(a[i] > mymax) {
            mymax = a[i];
            mycount = 1;
            maxcount = 1;
        }else if(a[i] == mymax) {
            mycount++;
            maxcount = max(maxcount, mycount);
        }else {
            mycount = 0;
        }
    }
    cout << maxcount << endl;
}