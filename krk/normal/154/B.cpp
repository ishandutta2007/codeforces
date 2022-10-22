#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 100005;

int n, m;
vector <int> tmp;
char ch;
int col;
int pr[Maxn];
bool on[Maxn];

vector <int> getVector(int x)
{
    vector <int> V;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) {
            V.push_back(i);
            do x /= i;
            while (x % i == 0);
        }
    if (x > 1) V.push_back(x);
    return V;
}

int Check(const vector <int> &V)
{
    for (int i = 0; i < V.size(); i++) if (pr[V[i]]) return pr[V[i]];
    return 0;
}

void Add(int x, const vector <int> &V)
{
    for (int i = 0; i < V.size(); i++) pr[V[i]] = x;
    on[x] = true;
}

void Rem(int x, const vector <int> &V)
{
    for (int i = 0; i < V.size(); i++) pr[V[i]] = 0;
    on[x] = false;
}

int main()
{
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf(" %c %d", &ch, &col);
        tmp = getVector(col);
        if (ch == '+')
            if (on[col]) printf("Already on\n");
            else {
                int st = Check(tmp);
                if (st) printf("Conflict with %d\n", st);
                else { Add(col, tmp); printf("Success\n"); }
            }
        else if (!on[col]) printf("Already off\n");
             else {
                 Rem(col, tmp); printf("Success\n");
             }
    }
    return 0;
}