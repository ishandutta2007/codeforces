#include <cstdio>
#include <vector>
using namespace std;

int n;
vector<int> num[105];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            num[(j+i)%n].push_back(i*n + j);
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<num[i].size(); j++) printf("%d ", num[i][j] + 1);
        printf("\n");
    }
}