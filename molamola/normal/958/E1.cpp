#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <set>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define rep(i, n) for(int i=0;i<n;i++)
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define szz(x) (int)(x).size()
#define Fi first
#define Se second

const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f;
const ll MOD = 1000000007;
const int IT_MAX = 1 << 17;

char in1[15][15];
char in2[15][15];
char u[15][15];

void myrotate(int N) {
    int i, j;
    for(i = 0; i < N; i++) for(j = 0; j < N; j++) u[j][N-1-i] = in1[i][j];
    for(i = 0; i < N; i++) for(j = 0; j < N; j++) in1[i][j] = u[i][j];
}
void myflip(int N) {
    int i, j;
    for(i = 0; i < N; i++) for(j = 0; j < N-1-j; j++) swap(in1[i][j], in1[i][N-1-j]);
}
bool isValid(int N) {
    int i, j;
    for(i = 0; i < N; i++) for(j = 0; j < N; j++) if(in1[i][j] != in2[i][j]) return false;
    return true;
}
int main() {
    int a, b; scanf("%d%d", &a, &b);
    printf("%s\n", a == b ? "Yes" : "No");
    return 0;

}