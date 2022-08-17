#include <bits/stdc++.h>

#define S second
#define F first

using namespace std;
typedef long long ll;

vector<int> ans;

int main()
{
    int a, b, c;
    int m[1000], m1[1000];
    int n;
    string s;
    cin >> n;
    cin >> s;
    int k =  s[0] == 'B';
    for(int i = 1; i < n; i++)
    {
        if (s[i] == 'W')
        {
            if (k)
            {
                ans.push_back(k);
                k = 0;
            }
        }
        else
        {
            k++;
        }
    }
    if (k) ans.push_back(k);
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
}