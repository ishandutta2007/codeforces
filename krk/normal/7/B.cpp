#include <iostream>
#include <string>
using namespace std;

const int Maxm = 105;

int t, m, n;
int mem[Maxm];
int cur = 1;

void Alloc(int n)
{
    for (int i = 0; i + n <= m; i++) {
        int j;
        for (j = 0; j < n; j++)
           if (mem[i + j]) break;
        if (j < n) continue;
        for (j = 0; j < n; j++) mem[i + j] = cur;
        cout << cur++ << endl;
        return;
    }
    cout << "NULL\n";
}

void Erase(int n)
{
     if (n <= 0 || n >= cur) cout << "ILLEGAL_ERASE_ARGUMENT\n";
     else {
          bool was = false;
          for (int i = 0; i < m; i++)
             if (mem[i] == n) {
                        was = true;
                        mem[i] = 0;
             }
          if (!was) cout << "ILLEGAL_ERASE_ARGUMENT\n";
     }
}

void Defragment()
{
     for (int i = 0; i < m; i++) if (mem[i]) {
         int j = 0;
         while (mem[j] && j < i) j++;
         if (j < i) {
               mem[j] = mem[i];
               mem[i] = 0;
         }
     }
}

int main()
{
    cin >> t >> m;
    while (t--) {
          string s; cin >> s;
          if (s == "alloc") {
                cin >> n;
                Alloc(n);
          } else if (s == "erase") {
                 cin >> n;
                 Erase(n);
          } else Defragment();
    }
    return 0;
}