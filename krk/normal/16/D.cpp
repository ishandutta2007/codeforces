#include <iostream>
#include <string>
using namespace std;

int n;
string s;
int tim, cnt;
int days = 1;

int getTime()
{
    int hours = (10 * (s[1] - '0') + (s[2] - '0')) % 12;
    int mins = 10 * (s[4] - '0') + (s[5] - '0');
    return 60 * hours + mins + (s[7] == 'p'? 12 * 60: 0);
}

int main()
{
    cin >> n; cin.ignore();
    while (n--) {
          getline(cin, s);
          int ntim = getTime();
          if (ntim != tim) cnt = 1;
          if (ntim < tim) days++;
          if (ntim == tim)
             if (++cnt > 10) {
                       days++; cnt = 1;
             }
          tim = ntim;
    }
    cout << days << endl;
    return 0;
}