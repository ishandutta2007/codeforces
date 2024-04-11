#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 17;
const string ranks = "23456789TJQKA";
const string suits = "CDHS";

int n, m, r1, c1, r2, c2;
int B[Maxn][Maxn];
vector <int> fr;
vector <pair <pair <int, int>, int> > jokers;
bool ans;

int toInt(const string &s)
{
    if (s[1] == '1') return 53;
    else if (s[1] == '2') return 54;
    return suits.find(s[1]) * 13 + ranks.find(s[0]);
}

string toChars(int x)
{
     string s = "";
     s += ranks[x % 13]; s += suits[x / 13];
     return s;
}

bool canFind(int x)
{
     for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
           if (B[i][j] == x) return true;
     return false;
}

bool goodCheck(int r, int c)
{
     char ch = toChars(B[r][c])[1];
     int i, j;
     for (i = r; i <= r + 2; i++) {
         for (j = c; j <= c + 2; j++)
            if (toChars(B[i][j])[1] != ch) break;
         if (j <= c + 2) break;
     }
     if (i > r + 2) return true;
     for (int i = r; i <= r + 2; i++)
        for (int j = c; j <= c + 2; j++)
           for (int i2 = r; i2 <= r + 2; i2++)
              for (int j2 = c; j2 <= c + 2; j2++) if (i2 != i || j2 != j)
                 if (toChars(B[i][j])[0] == toChars(B[i2][j2])[0]) return false;
     return true;
}

void check()
{
     for (int i = 0; i + 2 < n && !ans; i++)
        for (int j = 0; j + 2 < m && !ans; j++) if (goodCheck(i, j))
           for (int i2 = 0; i2 + 2 < n && !ans; i2++)
              for (int j2 = 0; j2 + 2 < m && !ans; j2++)
                 if ((abs(i-i2) >= 3 || abs(j-j2) >= 3) && goodCheck(i2, j2)) {
                               ans = true;
                               r1 = i+1; c1 = j+1;
                               r2 = i2+1; c2 = j2+1;
                 }
}

int main()
{
    string s;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
       for (int j = 0; j < m; j++) {
           cin >> s;
           B[i][j] = toInt(s);
           if (B[i][j] == 53) jokers.push_back(make_pair(make_pair(i, j), 1));
           else if (B[i][j] == 54) jokers.push_back(make_pair(make_pair(i, j), 2));
       }
    for (int i = 0; i < 52; i++) if (!canFind(i)) fr.push_back(i);
    if (jokers.size() == 0) {
                      check();
                      if (ans) {
                               cout << "Solution exists.\n";
                               cout << "There are no jokers.\n";
                               cout << "Put the first square to (" << r1 << ", " << c1 << ").\n";
                               cout << "Put the second square to (" << r2 << ", " << c2 << ").\n";
                      } else cout << "No solution.\n";
    } else if (jokers.size() == 1) {
              int i;
              for (i = 0; i < fr.size() && !ans; i++) {
                  B[jokers[0].first.first][jokers[0].first.second] = fr[i];
                  check();
              }
              if (ans) {
                       cout << "Solution exists.\n";
                       cout << "Replace J" << jokers[0].second << " with " 
                            << toChars(B[jokers[0].first.first][jokers[0].first.second]) << ".\n";
                       cout << "Put the first square to (" << r1 << ", " << c1 << ").\n";
                       cout << "Put the second square to (" << r2 << ", " << c2 << ").\n";
              } else cout << "No solution.\n";
    } else {
           if (jokers[0].second > jokers[1].second) swap(jokers[0], jokers[1]);
           int i, j;
           for (i = 0; i < fr.size() && !ans; i++)
              for (j = 0; j < fr.size() && !ans; j++) if (i != j) {
                  B[jokers[0].first.first][jokers[0].first.second] = fr[i];
                  B[jokers[1].first.first][jokers[1].first.second] = fr[j];
                  check();
              }
           if (ans) {
                    cout << "Solution exists.\n";
                    cout << "Replace J1 with " 
                         << toChars(B[jokers[0].first.first][jokers[0].first.second])
                         << " and J2 with " 
                         << toChars(B[jokers[1].first.first][jokers[1].first.second]) << ".\n";
                    cout << "Put the first square to (" << r1 << ", " << c1 << ").\n";
                    cout << "Put the second square to (" << r2 << ", " << c2 << ").\n";
           } else cout << "No solution.\n";
    }
    return 0;
}