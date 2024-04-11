#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define e1 first
#define e2 second
#define OUT(x) { cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define boost ios_base::sync_with_stdio(0)
typedef long long ll;
typedef unsigned int ui;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <PII, PII> PP;
typedef pair <ll, ll> PLL;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18 + 3;
int n, n1, n2, m, a, b, c;
#define maxn 1000100

int main()
{
    string s;
    cin >> s;
    int lewo = 0, prawo = 0, jest = 0;
    for (int i=0; i<s.size(); ++i)
    {
        if (s[i] == '|') jest = 1;
        else if (jest) prawo++;
        else lewo++;
    }
    string tmp;
    cin >> tmp;
    int sz = tmp.size();
    int sum = sz + prawo + lewo;
    if (sum % 2) OUT("Impossible");
    int pol = sum / 2;
    if (prawo > pol || lewo > pol) OUT("Impossible");
    
    for (int i=0; i<s.size(); ++i) 
    {
        if (s[i] == '|')
        {
            for (int j=0; j<pol - lewo; ++j) cout << tmp[j];
        }
        cout << s[i];
    }
    for (int i=pol - lewo; i<tmp.size(); ++i) cout << tmp[i];
}