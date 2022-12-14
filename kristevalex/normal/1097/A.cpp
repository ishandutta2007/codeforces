#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;





int main()
    {
    FAST;


    string s, s1, s2, s3, s4, s5;
    cin >> s >> s1 >> s2 >> s3 >> s4 >> s5;

    if (s[1] == s1[1] || s[1] == s2[1] || s[1] == s3[1] || s[1] == s4[1] || s[1] == s5[1])
    {
    cout << "YES";
    return 0;
    }

if (s[0] == s1[0] || s[0] == s2[0] || s[0] == s3[0] || s[0] == s4[0] || s[0] == s5[0])
    {
    cout << "YES";
    return 0;
    }



    cout << "NO";

    return 0;
    }