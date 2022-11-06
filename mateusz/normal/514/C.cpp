#include <bits/stdc++.h>
using namespace std;
const int N = 6000005, M = 1e9 + 7, P = 29, P2 = 5, M2 = 1e9 + 9;
map<pair<int, int>, bool> Mapa;
int pot[N];
int pot2[N];
char word[N];
int n, m;
int main()
{
    scanf("%d %d", &n, &m);
    pot[0] = 1;
    pot2[0] = 1;
    for(int i = 1; i <= N - 5; i++)
    {
        pot[i] = (long long)pot[i - 1] * P % M;
        pot2[i] = (long long)pot2[i - 1] * P2 % M2;
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%s", &word[1]);
        int hash = 0, hash2 = 0;
        int l = strlen(word + 1);
        for(int j = 1; j <= l; j++)
        {
            word[j] -= 96;
            hash = ((long long)hash * P + word[j]) % M;
            hash2 = ((long long)hash2 * P2 + word[j]) % M2;
        }
        for(int j = 1; j <= l; j++)
        {
            for(int k = word[j] - 1; k >= 1; k--)
            {
                long long temp = hash, temp2 = hash2;
                hash = (hash - ((long long)word[j] * pot[l - j] % M) + M) % M;
                hash = (hash + (long long)k * pot[l - j]) % M;
                hash2 = (hash2 - ((long long)word[j] * pot2[l - j] % M2) + M2) % M2;
                hash2 = (hash2 + (long long)k * pot2[l - j]) % M2;
                Mapa[{hash, hash2}] = true;             
                hash = temp;
                hash2 = temp2;
            }
            for(int k = word[j] + 1; k <= 3; k++)
            {
                long long temp = hash, temp2 = hash2;
                hash = (hash - ((long long)word[j] * pot[l - j] % M) + M) % M;
                hash = (hash + (long long)k * pot[l - j]) % M;
                hash2 = (hash2 - ((long long)word[j] * pot2[l - j] % M2) + M2) % M2;
                hash2 = (hash2 + (long long)k * pot2[l - j]) % M2;
                Mapa[{hash, hash2}] = true;             
                hash = temp;
                hash2 = temp2;
            }
        }
    }
    for(int i = 1; i <= m; i++)
    {
        scanf("%s", &word[1]);
        int l = strlen(word + 1);
        int hash = 0, hash2 = 0;
        for(int j = 1; j <= l; j++)
        {
            hash = ((long long)hash * P + word[j] - 96) % M;
            hash2 = ((long long)hash2 * P2 + word[j] - 96) % M2;            
        }   
        printf(Mapa.count({hash, hash2})? "YES\n": "NO\n");
    }
    return 0;
}