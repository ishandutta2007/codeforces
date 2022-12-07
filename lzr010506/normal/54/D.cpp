#include <bits/stdc++.h>
#define Len length
#define vi vector<int>
#define FOR(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
#define N 110
#define Mk 26
using namespace std;

int n, k;
string s, inf;
int pos[N][N], p[N][N], ch[N][N];

int Fn(const string &s)
{
    vi Z(s.Len(), 0);
    int l = 0, r = 0;
    FOR(i, 1, s.Len() - 1)
    {
        if (i <= r) Z[i] = min(Z[i - l], r - i);
        while (i + Z[i] < s.Len() && s[Z[i]] == s[i + Z[i]]) Z[i]++;
        if (Z[i]) { l = i; r = i + Z[i] - 1; } 
    }
    FOR(i, 0, s.Len() - 1)
        if (i + Z[i] == s.Len()) return Z[i];
    return 0;
}

void Print(int i, int j)
{
     if (!i) return;
     Print(i - 1, p[i][j]); 
     cout << char(ch[i][j] + 'a');
}

int main()
{
    cin >> n >> k;
    cin >> s >> inf;
    pos[0][0] = true;
    FOR(i, 0, n - 1)
    {
        int l, r;
        if (s.Len() > i) { l = 0; r = s.Len(); }
        else if (inf[i - s.Len()] == '1') l = r = s.Len();
        else { l = 0; r = s.Len() - 1; }
        FOR(j, l, r)
        	if (pos[i][j])
        		FOR(l, 0, k - 1)
	            {
	                int nxt = Fn(s + "#" + s.substr(0, j) + char(l + 'a'));
	                pos[i + 1][nxt] = true; p[i + 1][nxt] = j; ch[i + 1][nxt] = l;
	            }
    }
    int l, r;
    if (inf[n - s.Len()] == '1') l = r = s.Len();
    else { l = 0; r = s.Len() - 1; }
    while (l <= r && !pos[n][l]) l++;
    if (l > r) cout << "No solution\n";
    else { Print(n, l); cout << endl; }
    return 0;
}