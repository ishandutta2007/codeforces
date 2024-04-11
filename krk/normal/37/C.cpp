#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int Maxn = 1001;

int n, a[Maxn], is[Maxn];
queue <string> take[Maxn];
string canbe;

bool makeBigger(int pos)
{
     if (pos < 0) return false;
     if (canbe[pos] == '0') {
                    canbe[pos] = '1';
                    return true;
     } else {
            canbe[pos] = '0';
            return makeBigger(pos-1);
     }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        is[a[i]]++;
    }
    int i;
    for (i = 1; i < Maxn; i++) {
        canbe += "0";
        bool alltaken = false;
        while (is[i]) {
              take[i].push(canbe);
              is[i]--;
              alltaken = !makeBigger(canbe.length()-1);
              if (alltaken) break;
        }
        if (alltaken) break; 
    }
    int j;
    for (j = i; j < Maxn; j++) if (is[j]) break;
    if (j < Maxn) cout << "NO\n";
    else {
         cout << "YES\n";
         for (int i = 0; i < n; i++) {
             cout << take[a[i]].front() << endl;
             take[a[i]].pop();
         }
    }
    return 0;
}