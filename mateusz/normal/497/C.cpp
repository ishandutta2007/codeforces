#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <set>
typedef long long LL;
#define ff first
#define ss second
#define MP make_pair
#define PB push_back
using namespace std;
const int N = 200005;
int n, m;
int a[N], b[N];
pair<int, pair<int, int> >S[N];
int poc[N], kon[N], ilerazy[N];
set<pair<int, int> > spiewaki;
int size;
int wynik[N];
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d %d", &a[i], &b[i]);
        S[++size] = MP(a[i], MP(1, i));
    }
    scanf("%d", &m);
    for(int i=1; i<=m; i++)
    {
        scanf("%d %d %d", &poc[i], &kon[i], &ilerazy[i]);
        S[++size] = MP(poc[i], MP(0, i));
    }
    sort(S + 1, S + 1 + size);
    for(int i=1; i<=size; i++)
    {
        int co = S[i].ss.ff;
        int indeks = S[i].ss.ss;
        if(co == 0)
        {
            spiewaki.insert(MP(kon[indeks], indeks));
        }       
        else
        {
            set<pair<int, int> >::iterator it = spiewaki.lower_bound(MP(b[indeks], 0));
            if(it == spiewaki.end())
            {
                printf("NO");
                return 0;
            }
            else
            {
                wynik[indeks] = it->ss;
                ilerazy[it->ss]--;
                if(ilerazy[it->ss] == 0) spiewaki.erase(it);
            }
        }
    }
    printf("YES\n");
    for(int i=1; i<=n; i++)
    {
        printf("%d ", wynik[i]);
    }
}