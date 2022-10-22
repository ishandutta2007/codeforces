#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

int n;
vector <int> groups[Maxn];
int oth[Maxn];
int mygroup[Maxn];
bool tk[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &n);
    if (n % 2 == 0) {
        printf("First\n");
        fflush(stdout);
        for (int i = 1; i <= n; i++)
            printf("%d ", i);
        for (int i = 1; i <= n; i++)
            printf("%d%c", i, i + 1 <= n? ' ': '\n');
        fflush(stdout);
    } else {
        printf("Second\n");
        fflush(stdout);
        for (int i = 1; i <= 2 * n; i++) {
            int a; scanf("%d", &a);
            groups[a].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            oth[groups[i][0]] = groups[i][1];
            oth[groups[i][1]] = groups[i][0];
            mygroup[groups[i][0]] = mygroup[groups[i][1]] = i;
        }
        vector <vector <int> > cycles;
        for (int i = 1; i <= 2 * n; i++) if (!tk[i]) {
            vector <int> cur;
            int my = i;
            while (!tk[my]) {
                cur.push_back(my);
                tk[my] = true;
                my = oth[my];
                cur.push_back(my);
                tk[my] = true;
                if (my <= n) my += n;
                else my -= n;
            }
            cycles.push_back(cur);
        }
        int r = 0;
        while (cycles[r].size() / 2 % 2 == 0) r++;
        int cnt = n % 4 == 3? 1: 0;
        for (int i = 0; i < cycles.size(); i++)
            for (int j = 0; j < cycles[i].size(); j += 2) {
                int num = cycles[i][j];
                if (num % (2 * n) >= n) cnt++;
                res[mygroup[num]] = num;
            }
        if (cnt % 2)
            for (int j = 1; j < cycles[r].size(); j += 2) {
                int num = cycles[r][j];
                res[mygroup[num]] = num;
            }
        for (int i = 1; i <= n; i++)
            printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
        fflush(stdout);
    }
    return 0;
}