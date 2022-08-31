// CF_NERC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstring>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cmath>
#define maxn 200020
using namespace std;
int pre[maxn], fir[maxn], en[maxn], nex[maxn], start[maxn];
int n, m, s;
int sta[2][maxn];
int dl[maxn];
bool flag;
int top0, top1;
void print_ans() {
    printf("Possible\n");
    printf("%d\n", top0);
    for (int i = top0 - 1; i >= 0; --i) {
        printf("%d", sta[0][i]);
        if (i > 0)printf(" "); else printf("\n");
    }
    printf("%d\n", top1);
    for (int i = top1 - 1; i >= 0; --i) {
        printf("%d", sta[1][i]);
        if (i > 0)printf(" "); else printf("\n");
    }
}
void bfs(int st) {
    if (start[st] > 0) {
        top1 = 2;
        sta[1][0] = st;
        sta[1][1] = s;
        int j = st;
        top0 = 0;
        sta[0][top0++] = st;
        while (j != s) {
            j = pre[j];
            sta[0][top0++] = j;
        }
        flag = true;
        print_ans();
        return;
    }
    start[st] = st;
    pre[st] = s;
    dl[1] = st;
    int hd = 0;
    int td = 1;
    while (hd < td) {
        int x = dl[++hd];
        for (int k = fir[x]; k; k = nex[k]) {
            int j = en[k];
            if (j == s)continue;
            if (start[j] == 0) {
                start[j] = st;
                pre[j] = x;
                dl[++td] = j;
            }
            else if (start[j] != st) {
                int v = j;
                top0 = 0;
                sta[0][top0++] = j;
                while (j != s) {
                    j = pre[j];
                    sta[0][top0++] = j;
                }
                top1 = 0;
                sta[1][top1++] = v;
                sta[1][top1++] = x;
                j = x;
                while (j != s) {
                    j = pre[j];
                    sta[1][top1++] = j;
                }
                flag = true;
                print_ans();
                return;
            }
        }
    }
    
}
int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        en[i] = y;
        nex[i] = fir[x];
        fir[x] = i;
    }
    flag = false;
    for (int k = fir[s]; k; k = nex[k]) {
        int j = en[k];
        bfs(j);
        if (flag)break;
    }
    if (!flag)printf("Impossible\n");
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file