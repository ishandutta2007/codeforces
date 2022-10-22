#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 50;

struct Team {
       string nam;
       int pnts, sc, mis;
};

int n;
Team T[Maxn];

void Add(const string &s, int a, int b)
{
     for (int i = 0; i < n; i++)
        if (T[i].nam == s) {
                     if (a > b) T[i].pnts += 3;
                     else if (a == b) T[i].pnts += 1;
                     T[i].sc += a; 
                     T[i].mis += b;
                     break; 
        }
}

bool Less1(const Team &a, const Team &b)
{
     if (a.pnts != b.pnts) return a.pnts > b.pnts;
     else if (a.sc - a.mis != b.sc - b.mis) return a.sc - a.mis > b.sc - b.mis;
     else return a.sc > b.sc;
}

bool Less2(const Team &a, const Team &b)
{
     return a.nam < b.nam;
}

int main()
{
    string a, b;
    int c, d;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> T[i].nam;
    cin.ignore();
    for (int i = 0; i < n * (n-1) / 2; i++) {
        getline(cin, a, '-'); getline(cin, b, ' ');
        scanf("%d:%d", &c, &d); cin.ignore();
        Add(a, c, d); Add(b, d, c);
    }
    sort(T, T+n, Less1);
    sort(T, T+n/2, Less2);
    for (int i = 0; i < n/2; i++) cout << T[i].nam << endl;
    return 0;
}