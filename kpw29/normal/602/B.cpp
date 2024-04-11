#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010

multiset <int> s;
int t[maxn], n, inf = 1e9+8;
inline int nt(int poz)
{
    ++poz;
    s.insert(t[poz]);
    return poz;
}
inline int cof(int poz)
{
    s.erase(s.find(t[poz]));
    poz--;
    return poz;
}

int main()
{
    scanf("%d", &n);
    int wyn = 0;
    for (int i=1; i<=n; ++i) scanf("%d" , &t[i]);
    t[n+1] = inf;
    int j = 0; j = nt(j);
    for (int i=1; i<=n; ++i)
    {
        if (j < i) j = nt(j);
        while ((*(--s.end()) - *(s.begin())) <= 1) j = nt(j);
        if (j > n || *(--s.end()) - *(s.begin()) > 1) j = cof(j);
        s.erase(s.find(t[i]));
        wyn = max(wyn, j - i + 1);
    }
    printf("%d", wyn);
}