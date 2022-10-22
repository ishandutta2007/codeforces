#include <iostream>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n, m;
int a[Maxn], b[Maxn];
char sim[Maxn];
bool stop;

void Gen(int lvl)
{
     if (lvl == m) stop = true;
     else {
          sim[lvl] = '?';
          int j;
          for (j = 0; j < lvl; j++)
             if (a[lvl] < a[j] && a[j] < b[lvl] && (b[lvl] < b[j] || b[j] < a[lvl]) ||
                 a[lvl] < b[j] && b[j] < b[lvl] && (b[lvl] < a[j] || a[j] < a[lvl])) 
                if (sim[lvl] != '?' && sim[lvl] == sim[j]) break;
                else if (sim[j] == 'o') sim[lvl] = 'i';
                     else sim[lvl] = 'o';
          if (j < lvl) return;
          if (sim[lvl] != '?') Gen(lvl+1);
          else {
               sim[lvl] = 'i';
               Gen(lvl+1);
               if (stop) return;
               sim[lvl] = 'o';
               Gen(lvl+1);
          }
     }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        if (a[i] > b[i]) swap(a[i], b[i]);
    }
    Gen(0);
    if (!stop) cout << "Impossible\n";
    else {
         for (int i = 0; i < m; i++)
            cout << sim[i];
         cout << endl;
    }
    return 0;
}