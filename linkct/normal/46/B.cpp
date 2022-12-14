#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

const int a[5][5] = {{0,1,2,3,4},
                     {1,2,0,3,4},
                     {2,3,1,4,0},
                     {3,4,2,1,0},
                     {4,3,2,1,0}};

map<string,int> mp;
int cnt[5];

int main() {
    mp["S"] = 0;
    mp["M"] = 1;
    mp["L"] = 2;
    mp["XL"] = 3;
    mp["XXL"] = 4;
    for (int i = 0; i < 5; i++)
        scanf("%d",&cnt[i]);
    int T;
    scanf("%d",&T);
    for (; T--;) {
        string s;
        cin >> s;
        int x = mp[s];
        for (int i = 0; i < 5; i++)
            if (cnt[a[x][i]]) {
                cnt[a[x][i]]--;
                if (a[x][i] == 0)
                    printf("S\n");
                else
                    if (a[x][i] == 1)
                        printf("M\n");
                    else
                        if (a[x][i] == 2)
                            printf("L\n");
                        else
                            if (a[x][i] == 3)
                                printf("XL\n");
                            else
                                printf("XXL\n");
                break;
            }
    }
    return 0;
}