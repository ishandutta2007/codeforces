#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 100005;

int n;
iii inf[Maxn];
int res[Maxn];
stack <int> S;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &inf[i].first.first, &inf[i].first.second);
        inf[i].second = i;
    }
    sort(inf, inf + n);
    for (int i = n - 1; i >= 0; i--) {
        int ans = 1;
        while (!S.empty() && 
               inf[i].first.first + inf[i].first.second - 1 >= inf[S.top()].first.first) {
                                  ans += res[inf[S.top()].second];
                                  S.pop();
        }
        res[inf[i].second] = ans;
        S.push(i);
    }
    for (int i = 0; i < n; i++)
        printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    return 0;
}