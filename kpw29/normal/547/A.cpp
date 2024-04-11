#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define e1 first
#define e2 second
#define pb push_back
#define boost ios_base::sync_with_stdio(false)
#define milion 1000100
#define tysiac 1010
#define dwa_tysiace 2010
#define sto_tysiecy 100100
typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned int ui;
typedef pair <int, int> BONG;
typedef pair <ll, ll> LONG;
typedef pair <BONG, BONG> DONG;
const int inf = 1e9+9;
const int mod = 1e9+7;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
#define maxn 1000100
int m;
ll x1,x2,h1,h2, Y1, Y2;
LONG goal;
int time_1[maxn], time_2[maxn];
int main()
{
    scanf("%d", &m);
    cin >> h1 >> goal.e1;
    cin >> x1 >> Y1;
    cin >> h2 >> goal.e2;
    cin >> x2 >> Y2;
    int step = 0;
    fill(time_1, time_1+m+1, -1);
    fill(time_2, time_2+m+1, -1);
    time_1[h1] = time_2[h2] = 0;
    int C1_POJAW=-1, C2_POJAW=-1, C2_CZAS = 0, C1_CZAS = 0;
    for (int i=1; i<=10 * m; ++i) 
    {
        ++step;
        h1 = (x1 * h1 + Y1) % m;
        h2 = (x2 * h2 + Y2) % m;
        
        if (time_1[h1] == -1) time_1[h1] = step;
        else if (C1_POJAW == -1 && h1 == goal.e1) C1_POJAW = time_1[h1], C1_CZAS = step - time_1[h1];
        if (time_2[h2] == -1) time_2[h2] = step;
        else if (C2_POJAW == -1 && h2 == goal.e2) C2_POJAW = time_2[h2], C2_CZAS = step - time_2[h2];
        
    }   
    
    //printf("%d %d %d %d\n", C1_POJAW, C1_CZAS, C2_POJAW, C2_CZAS);
    if (C1_POJAW == -1 || C2_POJAW == -1) 
    {
        if (time_1[goal.e1] == -1 || time_2[goal.e2] == -1)
        {
            cout << "-1";
            return 0;
        }
        //tutaj jest bug bo byc moze nie ma cyklu ale jest rozwiazanie
        if (C1_POJAW == -1 && C2_POJAW == -1) 
        {
            if (time_1[goal.e1] == time_2[goal.e2]) printf("%d\n", time_2[goal.e2]);
            else cout << "-1";
            return 0;
        }
        
        else if (C1_POJAW == -1) //cyklem jest dwojka
        {
            int x = time_1[goal.e1];
            if (x < C2_POJAW) {cout << "-1"; return 0; }
            if ((x - C2_POJAW )% C2_CZAS == 0) printf("%d\n", x);
            else cout << "-1";
            return 0;
        }
        else
        {
            int x = time_2[goal.e2];
            if (x < C1_POJAW) {puts("-1"); return 0; }
            if ((x - C1_POJAW )% C1_CZAS == 0) printf("%d\n", x);
            else cout << "-1";
            return 0;
        }
        cout << "-1";
        return 0;
    }
    
    //printf("%d %d %d %d\n", C1_POJAW, C2_POJAW, C1_CZAS, C2_CZAS);
    ll wynik = C1_POJAW;
    ll WYN = INF;
    //puts("ALLEL");
    for (int help=0; help <= 5 * m; ++help)
    {
        if (wynik < C2_POJAW);
        else if ((wynik - C2_POJAW )% C2_CZAS == 0) WYN = min(WYN, wynik);
        wynik += C1_CZAS;
    }
    
    if (WYN == INF) puts("-1");
    else cout << WYN;
}