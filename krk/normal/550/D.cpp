#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

int k;
vector <ii> E;

int A(int x) { return 2 + x; }

int B(int x) { return k + 3 + x; }

int main()
{
    scanf("%d", &k);
    if (k % 2 == 0) printf("NO\n");
    else if (k == 1) {
        printf("YES\n");
        printf("2 1\n");
        printf("1 2\n");
    } else {
        int n = 2 + k + 1 + k + 1;
        E.push_back(ii(1, 2));
        for (int i = 1; i <= k - 1; i++) {
            E.push_back(ii(1, A(i)));
            E.push_back(ii(2, B(i)));
        }
        for (int i = 1; i <= k + 1; i++) {
            if (i != k) {
                E.push_back(ii(A(k), A(i)));
                E.push_back(ii(B(k), B(i)));
            }
            if (i != k && i != k + 1) {
                E.push_back(ii(A(k + 1), A(i)));
                E.push_back(ii(B(k + 1), B(i)));
            }
        }
        for (int i = 1; i < k; i++)
            for (int j = i + 1; j < k; j++)
                if (i + j != k) {
                    E.push_back(ii(A(i), A(j)));
                    E.push_back(ii(B(i), B(j)));
                }
        printf("YES\n");
        printf("%d %d\n", n, E.size());
        for (int i = 0; i < E.size(); i++)
            printf("%d %d\n", E[i].first, E[i].second);
    }
    return 0;
}