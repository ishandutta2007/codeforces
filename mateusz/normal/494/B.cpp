#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
typedef long long LL;
using namespace std;
const int N = 100005;
char s[N], t[N];
LL hasz[N], haszm;
LL pot[N];
const LL P = 29;
const LL M = 1000000007;
int ways[N];
int pref[N], prefprefow[N];
int main()
{
    scanf("%s", &s[1]);
    int n = strlen(s + 1);
    scanf("%s", &t[1]);
    int m = strlen(t + 1);
    pot[0] = 1;
    for(int i=1; i<=n; i++)
        pot[i] = pot[i - 1] * P % M;
    for(int i=1; i<=n; i++)
    {
        hasz[i] = (hasz[i - 1] * P + s[i] - 96) % M;
    }
    for(int i=1; i<=m; i++)
        haszm = (haszm * P + t[i] - 96) % M;
    if(m > n)
    {
        printf("0");
        return 0;
    }
    int last = 1;
   int suma = 0;
    int byl = 0;
    for(int i=m; i<=n; i++)
    {
        ways[i] = ways[i - 1];  
        if(((hasz[i] - ((hasz[i - m] * pot[m]) % M)) + M) % M == haszm)
        {
            ways[i] += prefprefow[i - m] - prefprefow[last - 1];
            if(ways[i] < 0)
                ways[i] += M;
            if(ways[i] >= M) ways[i] -= M;
            ways[i] += i - m + 1 - last;
            if(byl == 0) ways[i]++;
            if(ways[i] >= M) ways[i] -= M;
            last = i - m + 1;
            byl = 1;
        }
        pref[i] = pref[i - 1] + ways[i];
        if(pref[i] >= M)
            pref[i] -= M;
        prefprefow[i] = prefprefow[i - 1] + pref[i];
        if(prefprefow[i] >= M)
            prefprefow[i] -= M;
        suma += ways[i];
        if(suma >= M)
            suma -= M;
    }
    
    
    printf("%d", suma);
    
    
}