#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <int> V;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        V.push_back(a);
    }
    sort(V.begin(), V.end());
    printf("%d\n", max(0, V.back() - 25));
    return 0;
}