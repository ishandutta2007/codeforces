#include <iostream>
using namespace std;

const int Maxn = 105;

int n;
int speed[Maxn], ram[Maxn], hdd[Maxn], cost[Maxn];
bool del[Maxn];
int best, besti;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
       cin >> speed[i] >> ram[i] >> hdd[i] >> cost[i];
    for (int i = 0; i < n; i++)
       for (int j = 0; j < n && !del[i]; j++)
          del[i] = speed[i] < speed[j] && ram[i] < ram[j] && hdd[i] < hdd[j];
    best = 1000000000;
    for (int i = 0; i < n; i++)
       if (!del[i] && cost[i] < best) {
                   best = cost[i];
                   besti = i + 1;
       }
    cout << besti << endl;
    return 0;
}