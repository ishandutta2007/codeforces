#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;

using namespace std;

string nm[1000];
int ans[10000];

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (char a = 'A'; a <= 'Z'; a++)
    {
        for (char b = 'a'; b <= 'z'; b++)
        {
            int id = ((a - 'A') * 26 + (b - 'a'));
            nm[id] = "";
            nm[id] += a;
            nm[id] += b;
        }
    }
    for (int i = 1; i < k; i++)
    {
        ans[i] = i;
    }
    int p = k;
    for (int i = k; i <= n; i++)
    {
        string s;
        cin >> s;
        if (s == "YES")
            ans[i] = p++;
        else
            ans[i] = ans[i - k + 1];
    }
    for (int i = 1; i <= n; i++) cout << nm[ans[i]] << " ";
    cout << endl;
    return 0;
}