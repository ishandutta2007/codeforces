//Well known task in Poland
//oi.edu.pl --> X OI -> TASOWANIE -> solutions
/*************************************************************************
 *                                                                       *
 *                       X Olimpiada Informatyczna                       *
 *                                                                       *
 *   Rozwizanie zadania: Tasowanie                                      *
 *   Plik:                tas.cpp                                        *
 *   Autor:               Krzysztof Onak                                 *
 *************************************************************************/

#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

const int MAXN = 1000000;

// liczby z pliku wejciowego
int n, l;
int b[MAXN];

bool odwiedzone[MAXN];       // tablica odwiedze 
vector<int> cykle[MAXN + 1]; // tablica wektorw pocztkw cykli

// wyszukiwanie i zliczanie cykli
void zliczaj_cykle() {
  for(int i = 0; i < n; ++i) odwiedzone[i] = false;
  for(int i = 0; i < n; ++i)
    if (!odwiedzone[i]) {
      int k = i;
      int dl = 0;
      while (!odwiedzone[k]) {
        ++dl;
    odwiedzone[k] = true;
    k = b[k];
      }
      cykle[dl].push_back(i);
    }
}

// najmniejszy wsplny dzielnik
int nwd(int a, int b) {
  return (b == 0) ? a : nwd(b, a % b);
}

// oblicza najmniejszy upierwszacz a wzgldem b (definicja w opracowaniu)
int upierwszacz(int a, int b) {
  int dz = 1, k = 1;
  do {
    a /= k;
    k = nwd(a, b);
    dz *= k;
  } while (k != 1);
  return dz;
}

// podnosi cykl do zadanej potgi
void cykl_potega(int start, int pot) {
  vector<int> cykl;
  int teraz = start;
  do {
    cykl.push_back(teraz);
    teraz = b[teraz];
  } while(teraz != start);
  int dl = cykl.size();
  for(int i = 0; i < dl; ++i)
    b[cykl[i]] = cykl[(i + pot) % dl];
}

// przeplata u cykli dlugosci dl o pocztkach cykle_dl[start..start+u-1]
void nawlecz(vector<int> &cykle_dl, int start, int u, int dl) {
  vector<int> w;
  for(int i = 0; i < dl; ++i)
    for(int j = start; j < start + u; ++j) {
      w.push_back(cykle_dl[j]);
      cykle_dl[j] = b[cykle_dl[j]];
    }
  int ile = w.size();;
  for(int i = 0; i < ile; ++i)
    b[w[i]] = w[(i + 1) % ile];
}

// oblicza odwrotnoci
void odwroc() {
  for(int i = 1; i <= n; ++i) if (!cykle[i].empty()) {
    int u = upierwszacz(l, i);
    int lu = l / u;
    int odwr_lu = 0;
    while ((long long)odwr_lu * lu % i != 1 % i) ++odwr_lu;
    int ile = cykle[i].size();
    if (ile % u != 0) {
      // to nie powinno si zdarzy dla poprawnych danych
      cout << "-1";
      exit(0);
    }
    for(int j = 0; j < ile; ++j) cykl_potega(cykle[i][j], odwr_lu);
    for(int j = 0; j < ile; j += u) nawlecz(cykle[i], j, u, i);
  }
}

int main() {
  scanf("%d", &n);
  l = 2;
  for(int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
    --b[i];
  }
  zliczaj_cykle();
  odwroc();
  for(int i = 0; i < n; ++i)
    printf("%d ", b[i] + 1);
}