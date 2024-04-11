#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
char str[Maxn];
int slen;
int zers[Maxn];
vector <int> ones;

bool Check(int x)
{
    int rem = int(ones.size()) - x;
    for (int i = 0; i + rem <= ones.size(); i++)
        if (zers[ones[i + rem - 1]] - zers[ones[i] - 1] <= x)
            return true;
    return false;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str + 1);
        slen = strlen(str + 1);
        ones.clear();
        for (int i = 1; i <= slen; i++) {
            zers[i] = zers[i - 1] + int(str[i] == '0');
            if (str[i] == '1') ones.push_back(i);
        }
        int lef = 0, rig = int(ones.size()) - 1;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (Check(mid)) rig = mid - 1;
            else lef = mid + 1;
        }
        printf("%d\n", lef);
    }
    return 0;
}