#include <iostream>
using namespace std;

typedef long long ll;

const int Maxa = 32000, Maxb = 31;

int a, b, n;
int wins[Maxa][Maxb];

int getWins(int a, int b)
{
    if (wins[a][b] != 0) return wins[a][b];
    ll res = 1;
    if (a == 1) {
          for (int i = 0; i < b; i++) res *= 2;
          if (res >= n) wins[a][b] = -2;
          else if (getWins(2, b) == -1 || getWins(1, b+1) == -1) wins[a][b] = 1;
          else if (getWins(1, b+1) == -2) wins[a][b] = -2;
          else wins[a][b] = -1;
    } else {
           for (int i = 0; i < b; i++) res *= a;
           if (res >= ll(n)) wins[a][b] = 1;
           else if (ll(a) * ll(a) >= ll(n)) if ((n - res) % 2) wins[a][b] = -1;
                                            else wins[a][b] = 1;
           else if (getWins(a+1, b) < 0 || getWins(a, b+1) < 0) wins[a][b] = 1;
                else wins[a][b] = -1; 
    }
    return wins[a][b]; 
}

int main()
{
    cin >> a >> b >> n;
    if (getWins(a, b) == 1) cout << "Masha\n";
    else if (getWins(a, b) == -1) cout << "Stas\n";
    else cout << "Missing\n";
    return 0;
}