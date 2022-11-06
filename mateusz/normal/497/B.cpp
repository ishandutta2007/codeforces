#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <list>
typedef long long LL;
#define ff first
#define ss second
#define MP make_pair
#define PB push_back
using namespace std;
using namespace std;
const int N = 100005;
int tab[N];
int pref1[N], pref2[N];
pair<int, int> S[N];
int size, n;
int operacje;
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &tab[i]);
        pref1[i] = pref1[i - 1] + (tab[i] == 1);
        pref2[i] = pref2[i - 1] + (tab[i] == 2);
    }
    list<int>ruchy;
    for(int i=1; i<=n; i++)
    {
        ruchy.PB(i);
    }
    for(int i=1;i<=n; i++)
    {
        int poz = 1;
        int wygr = 0;
        int przegr = 0;
        bool dasie = true;
        int last = 0;
        for(list<int>::iterator it = ruchy.begin(); it != ruchy.end(); it++)
        {
            while(*it <= last)
            {
//              operacje++;
                list<int>::iterator it2 = it;
                it++;
                ruchy.erase(it2);
                if(it == ruchy.end()) break;
            }
            if(it == ruchy.end()) break;
            while(*it <= n && pref1[*it] - pref1[last] < i && pref2[*it] - pref2[last] < i) {/*operacje++; */(*it)++;}
//          operacje++;
            if(*it > n)
                dasie = false;
            else
                if(pref1[*it] - pref1[last] >= i)
                    wygr++;
                else przegr++;
            last = *it;
            if(*it == n) break;
            
        }
//      operacje++;
        if(dasie == false || (tab[n] == 1 && wygr <= przegr) || (tab[n] == 2 && przegr <= wygr))
            continue;
        S[++size] = MP(max(wygr, przegr), i);

    }
    sort(S + 1, S + 1 + size);
    printf("%d\n", size);
    for(int i=1; i<=size; i++)
        printf("%d %d\n", S[i].ff, S[i].ss);
//  printf("%d\n", operacje);
    return 0;
}