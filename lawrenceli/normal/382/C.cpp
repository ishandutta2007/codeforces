#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <set>
#include <map>

using namespace std;

const int MAXN = 100100;

int n, arr[MAXN];
set<int> dif;
map<int, int> freq;

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr + n);

    if (n == 1) {
        cout << "-1\n";
        return 0;
    }

    for (int i=0; i<n-1; i++) {
        dif.insert(arr[i+1] - arr[i]);
        freq[arr[i+1] - arr[i]] ++;
    }

    if (dif.size() > 2) {
        cout << "0\n";
        return 0;
    }

    if (dif.size() == 1) {
        set<int> st;
        st.insert(arr[0] - (*dif.begin()));
        st.insert(arr[n-1] + (*dif.begin()));
        if (n == 2 && (arr[0] + arr[1]) % 2 == 0) st.insert((arr[0] + arr[1]) / 2);
        cout << st.size() << '\n';
        for (typeof(st.begin()) it = st.begin(); it != st.end(); it++)
            cout << *it << ' ';
        return 0;
    }

    typeof(freq.begin()) it = freq.begin();
    if (it->second > 1 && (++it)->second > 1) {
        cout << "0\n";
        return 0;
    }

    typeof(dif.begin()) it2 = dif.begin();
    int a = *it2; it2++; int b = *it2;

    set<int> st;

    for (int i=0; i<n-1; i++) {
        if (freq[arr[i+1] - arr[i]] == 1) {
            int c = arr[i+1] - arr[i];
            if (c == a) c = b;
            else c = a;
            if (!((arr[i] + arr[i+1]) % 2) && (arr[i+1] - arr[i]) / 2 == c) {
                st.insert((arr[i] + arr[i+1]) / 2);
            }
        }
    }

    cout << st.size() << '\n';
    for (typeof(st.begin()) it3 = st.begin(); it3 != st.end(); it3++) {
        cout << *it3 << ' ';
    }

    return 0;
}