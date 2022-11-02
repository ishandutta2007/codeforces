#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        if (s.front() == s.back()) cout << "-1\n";
        else cout << s << endl;
    }
    return 0;
}