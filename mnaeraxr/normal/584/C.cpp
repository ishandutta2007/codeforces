#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

char d(char c, char d){
    if ('a' != c && 'a' != d) return 'a';
    if ('b' != c && 'b' != d) return 'b';
    return 'c';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;
    t = n - t;
    string s1, s2;
    cin >> s1 >> s2;

    string s3 = s1;
    int te = 0;

    for (int i = 0; i < n; ++i)
        if (s1[i] == s2[i]) ++te;

    if (te + (n - te) / 2 >= t){
        int v1 = 0, v2 = 0;
        if (te >= t) te = t;
        else{
            v1 = t - te;
            v2 = t - te;
        }

        for (int i = 0; i < n; ++i){
            if (s1[i] != s2[i]){
                if (v1){
                    cout << s1[i];
                    v1--;
                }
                else if (v2){
                    cout << s2[i];
                    v2--;
                }
                else{
                    cout << d(s1[i], s2[i]);
                }
            }
            else{
                if (te){
                    cout << s1[i];
                    te--;
                }
                else{
                    cout << d(s1[i], s2[i]);
                }
            }
        }
        cout << endl;
    }
    else{
        cout << -1 << endl;
    }

    return 0;
}