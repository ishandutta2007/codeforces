#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 101, inf = 1000111222;

bool cmp(const string& a, const string& b) {
    return a.size() < b.size();
}

int main()
{
    //freopen("input.txt", "r", stdin);
    vector<string> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.PB(s);
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (v[j].find(v[i]) == string::npos) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i){
        cout << v[i] << endl;
    }

    return 0;
}