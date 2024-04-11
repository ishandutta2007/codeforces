#include<bits/stdc++.h>
#define FOR(i,s,e) for(int i=(s);i<=(e);i++)
#define FORD(i,s,e) for(int i=(s);i>=(e);i--)
#define ALL(k) (k).begin(),(k).end()
#define e1 first
#define e2 second
#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long LL;
typedef unsigned long long LLU;
typedef long double LD;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
const bool print=false;

int n, k;

int jed, dwa, czt;
vector <int> wek;

void nope()
{
    printf("NO\n");
    exit(0);
}

int main()
{
    scanf("%d%d", &n, &k);
    dwa=n*2;
    czt=n;
    for (int i=1; i<=k; i++)
    {
        int x;
        scanf("%d", &x);
        wek.push_back(x);
    }
    while(!wek.empty())
    {
        nth_element(wek.begin(), wek.end()-1, wek.end());
        int x=wek.back();
        wek.pop_back();
        if (!x)
            continue;
        if (x>=4 && czt)
        {
            czt--;
            x-=4;
            wek.push_back(x);
            continue;
        }
        if (x>=4 && dwa)
        {
            dwa--;
            x-=2;
            wek.push_back(x);
            continue;
        }
        if (x>=4 && jed)
        {
            jed--;
            x-=1;
            wek.push_back(x);
            continue;
        }
        if (x>=4)
            nope();
        if (x==3)
        {
            if (czt)
            {
                czt--;
                continue;
            }
            if (dwa)
            {
                dwa--;
                x-=2;
                wek.push_back(x);
                continue;
            }
            if (jed)
            {
                jed--;
                x-=1;
                wek.push_back(x);
                continue;
            }
            nope();
        }
        if (x==2)
        {
            if (czt)
            {
                czt--;
                jed++;
                continue;
            }
            if (dwa)
            {
                dwa--;
                x-=2;
                wek.push_back(x);
                continue;
            }
            if (jed)
            {
                jed--;
                x-=1;
                wek.push_back(x);
                continue;
            }
            nope();
        }
        if (x==1)
        {
            
            if (czt)
            {
                czt--;
                jed++;
                continue;
            }
            if (dwa)
            {
                dwa--;
                continue;
            }
            if (jed)
            {
                jed--;
                continue;
            }
            nope();
        }
    }
    printf("YES\n");
    return 0;
}