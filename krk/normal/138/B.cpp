#include <iostream>
#include <cstdio>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

string s;
int a[10], b[10];
int best, from;
deque <pair <int, char> > resA, resB;

int getBest()
{
    int c[10], d[10];
    for (int i = 0; i < 10; i++) {
        c[i] = a[i]; d[i] = b[i];
    }
    int res = 0;
    for (int i = 0; i < 10; i++) {
        int k = min(c[i], d[9 - i]);
        c[i] -= k; d[9 - i] -= k; res += k;
    }
    res += min(c[0], d[0]);
    return res;
}

void Print(deque <pair <int, char> > &D)
{
     for (int i = 0; i < D.size(); i++)
         while (D[i].first--) cout << D[i].second;
     cout << endl;
}

int main()
{
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        a[s[i] - '0']++; b[s[i] - '0']++;
    }
    for (int i = 1; i < 10; i++)
        if (a[i] && b[10 - i]) {
                 a[i]--; b[10 - i]--;
                 int val = 1 + getBest();
                 if (val > best) {
                         best = val; from = i;
                 }
                 a[i]++; b[10 - i]++;
        }
    if (best) {
              a[from]--; b[10 - from]--;
              resA.push_back(make_pair(1, char(from + '0')));
              resB.push_back(make_pair(1, char(10 - from + '0')));
              for (int i = 0; i < 10; i++) {
                  int k = min(a[i], b[9 - i]); a[i] -= k; b[9 - i] -= k;
                  resA.push_front(make_pair(k, char(i + '0')));
                  resB.push_front(make_pair(k, char(9 - i + '0')));
              }
              int k = min(a[0], b[0]); a[0] -= k; b[0] -= k;
              resA.push_back(make_pair(k, '0'));
              resB.push_back(make_pair(k, '0'));
              for (int i = 0; i < 10; i++) {
                  resA.push_front(make_pair(a[i], char(i + '0')));
                  resB.push_front(make_pair(b[i], char(i + '0')));
              }
    } else {
           for (int i = 1; i < 10; i++)
               resA.push_back(make_pair(a[i], char(i + '0')));
           resA.push_back(make_pair(a[0], '0'));
           resB = resA;
    }
    Print(resA);
    Print(resB);
    return 0;
}