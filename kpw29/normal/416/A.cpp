#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define e2 second
#define e1 first
const int inf = 2e9;
typedef unsigned int ui;
typedef pair <int, int> BONG;
typedef pair <BONG, BONG> LONG;
int n,a,b,c,m;
char s[1000100];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    int dol = -inf, gora = inf;
    for (int i=0; i<n; ++i)
    {
        string zn;
        char help;
        cin >> zn >> a >> help;
        bool dlugosc = 0;
        int ktore = 1;
        if (zn.size() > 1) dlugosc = true;
        if (zn[0] == '>') ktore = 1;
        else ktore = 0;
        
        if (help == 'N')
        {
            ktore = 1- ktore;
            if (dlugosc == true) dlugosc = false;
            else dlugosc = true;
        }
        if (ktore == 1 && dlugosc == false) ++a;
        if (ktore == 0 && dlugosc == false) --a;
        if (ktore == 1) dol = max(a, dol);
        else gora = min(gora, a);
        //cout << gora << ' ' << dol << endl;
    }
    if (dol <= gora) cout << dol;
    else cout << "Impossible";
}