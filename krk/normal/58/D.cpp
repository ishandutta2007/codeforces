#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 10000, Maxl = 11;

int n;
char c;
string arr[Maxn];
bool del[Maxn];
vector <string> slen[Maxl];

bool Less(const string &a, const string &b)
{
     if (a.length() == b.length()) return a < b;
     if (a.find(b) == 0) return a[b.length()] < c;
     else if (b.find(a) == 0) return b[a.length()] > c;
     else return a < b;
}

int main()
{
    int sumlen = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sumlen += arr[i].length();
        slen[arr[i].length()].push_back(arr[i]);
    }
    sumlen /= n/2;
    cin >> c;
    sort(arr, arr+n, Less);
    for (int i = 1; i < Maxl; i++) sort(slen[i].begin(), slen[i].end());
    for (int i = 0; i < n; i++) if (!del[i]) {
        cout << arr[i] << c;
        slen[arr[i].length()].erase(slen[arr[i].length()].begin());
        int from = sumlen - arr[i].length();
        cout << slen[from][0] << endl;
        del[lower_bound(arr, arr+n, slen[from][0], Less)-arr] = true;
        slen[from].erase(slen[from].begin());
    }
    return 0;
}