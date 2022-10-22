#include <cstdio>
#include <map>
using namespace std;

const int Maxn = 5005;

int h, m, n;
map <int, int> M;
bool fil[Maxn];
int res;

int main()
{
    scanf("%d %d %d", &h, &m, &n);
    while (n--) {
        char c;
        int id, hsh;
        scanf(" %c", &c);
        if (c == '+') {
            scanf("%d %d", &id, &hsh);
            while (fil[hsh]) {
                res++; hsh = (hsh + m) % h;
            }
            fil[hsh] = true; M[id] = hsh;
        } else {
            scanf("%d", &id);
            fil[M[id]] = false; M.erase(id);
        }
    }
    printf("%d\n", res);
    return 0;
}