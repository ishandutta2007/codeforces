#include <iostream>
#include <stack>
#include <string>
using namespace std;

const int Maxn = 1000005;

stack <int> S;
int best[Maxn];
string s;

int main()
{
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
       if (s[i] == '(') {
                best[i] = -1;
                S.push(i);
       } else {
              if (!S.empty()) {
                              best[i] = S.top(); S.pop();
                              if (best[i] && best[best[i]-1] != -1)
                                 best[i] = best[best[i]-1];
              } else best[i] = -1;
       }
    int ans = 0, cnt = 1;
    for (int i = 0; i < s.length(); i++)
       if (best[i] != -1)
          if (i - best[i] + 1 > ans) {
                ans = i - best[i] + 1; cnt = 1;
          } else if (i - best[i] + 1 == ans) cnt++;
    cout << ans << " " << cnt << endl;
    return 0;
}