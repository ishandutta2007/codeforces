#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(v) (int(v.size()))
#define pch putchar
#define gch getchar()
#define FORD(i,a,b) for (int i=(a); i<=(b); i++)
#define FORP(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,n) for (int i=0; i<(n); i++)
#define clean(v) memset(v,0,sizeof(v))

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n, m, x, y;
    scanf("%d%d%d%d",&x,&n,&y,&m);

    if (n > m)
        swap(n, m), swap(x, y);

    if (x + y <= m - n) {
        printf("%d",1 + x + y);
        return 0;
    }

    ll ans = 2, edge = 0, ver = 0;

/*  for (int i = 1; i <= x; i++) {
        int r = abs(n + i - m);
        if (r > y) ans++; else {
            //if (r != 0) edge++, ver++;
            int l = m - n - i;
            int r = m - n + i;
            l = max(l, 1);
            r = min(r, y);
            if (l <= y) edge++, ver++. l++;
            if (r >= 1) edge++, ver++, r--;
            if (l <= r)
                edge += 2 * (r - l + 1),
                ver += 2 * (r - l + 1);
        }
    }*/

    for (int i = 1; i <= x; i++) {
        int r = abs(n + i - m);
        if (r > y) ans++; else {
            int l, r;
            if (n + i <= m)
                l = m - n - i,
                r = m - n + i;
            else
                l = i - (m - n),
                r = m - n + i;
            //cerr << l << ' ' << r << '\n';


            //l = max(l, 1);
            //r = min(r, y);

            //cerr << l << ' ' << r << '\n';
            
            if (l >= 1 && l <= y) edge++, ver++, l++;
            if (r >= 1 && r <= y) edge++, ver++, r--;

            //cerr << l << ' ' << r << '\n';

            l = max(l, 1);
            r = min(r, y);

            if (l <= r)
                edge += 2 * (r - l + 1),
                ver += 2 * (r - l + 1);
        }
    }

    //cerr << edge << ' ' << ver << '\n';

    for (int i = 1; i <= y; i++) {
        int r = abs(m - i - n);
        if (r > x) ans++; else {
            int l, r;
            if (m - i >= n)
                l = m - n - i,
                r = m - n + i;
            else
                l = i - (m - n),
                r = m - n + i;
            if (l >= 1 && l <= x) edge++, ver++, l++;
            if (r >= 1 && r <= x) edge++, ver++, r--;

            l = max(l, 1);
            r = min(r, x);

            if (l <= r)
                edge += 2 * (r - l + 1),
                ver += 2 * (r - l + 1);
    
        }
    }

    //cerr << edge << ' ' << ver/2;

                
    cout << ans + edge - ver/2;

}