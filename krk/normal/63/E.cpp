#include <cstdio>
#include <set>
using namespace std;

const int Maxd = 15;
const int Maxk = 5;
const int len[Maxd] = {3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3};
const int moves[Maxd][Maxk] = {{0, 1, 2}, {3, 4, 5, 6}, {7, 8, 9, 10, 11},
                               {12, 13, 14, 15}, {16, 17, 18}, {0, 3, 7},
                               {1, 4, 8, 12}, {2, 5, 9, 13, 16}, {6, 10, 14, 17},
                               {11, 15, 18}, {2, 6, 11}, {1, 5, 10, 15},
                               {0, 4, 9, 14, 18}, {3, 8, 13, 17}, {7, 12, 16}};
const int Maxn = 19;

set <int> M;
int pos;
bool win[1 << Maxn];

int main()
{
    for (int i = 0; i < Maxd; i++)
        for (int j = 0; j < len[i]; j++) {
            int mask = 0;
            for (int l = j; l < len[i]; l++) {
                mask |= 1 << moves[i][l];
                M.insert(mask);
            }
        }
    for (int i = 0; i < Maxn; i++) {
        char c; scanf(" %c", &c);
        if (c == 'O') pos |= 1 << i;
    }
    for (int i = 0; i <= pos; i++)
        for (set <int>::iterator it = M.begin(); it != M.end() && !win[i]; it++)
            win[i] = (i & *it) == *it && !win[i & ~*it];
    if (win[pos]) printf("Karlsson\n");
    else printf("Lillebror\n");
    return 0;
}