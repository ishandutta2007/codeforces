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

void get(int &x, int &y) {
    x = gch - 'a';
    y = gch - '1';
    gch;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    
    int r1x, r1y;
    int r2x, r2y;
    int wkx, wky;
    int bkx, bky;
    
    get(r1x, r1y);
    get(r2x, r2y);
    get(wkx, wky);
    get(bkx, bky);
    
    int Bx = bkx;
    int By = bky;
    bool f1 = (Bx == r1x);
    bool f2 = (By == r1y);
    bool f3 = (Bx == r2x);
    bool f4 = (By == r2y);      
    
    bool beat1;
    bool beat2;

    if (f1 == f2) beat1 = false;
    else {
        beat1 = true;
        if (f1 && wkx == Bx && (wky - By)*(wky - r1y) <= 0)
            beat1 = false;
        if (f2 && wky == By && (wkx - Bx)*(wkx - r1x) <= 0)
            beat1 = false;
    }

    if (f3 == f4) beat2 = false;
    else {
        beat2 = true;
        if (f3 && wkx == Bx && (wky - By)*(wky - r2y) <= 0)
            beat2 = false;
        if (f4 && wky == By && (wkx - Bx)*(wkx - r2x) <= 0)
            beat2 = false;
    }

    if (!beat1 && !beat2) {
        puts("OTHER");
        return 0;
   }
    
    FORD(dx, -1, 1)
        FORD(dy, -1, 1) {
            int Bx = bkx + dx;
            int By = bky + dy;
            if (!(Bx >= 0 && Bx < 8 && By >= 0 && By < 8)) continue;
            if (abs(Bx - wkx) <= 1 && abs(By - wky) <= 1) continue;
            bool f1 = (Bx == r1x);
            bool f2 = (By == r1y);
            bool f3 = (Bx == r2x);
            bool f4 = (By == r2y);      
            
            bool beat1;
            bool beat2;

            if (f1 == f2) beat1 = false;
            else {
                beat1 = true;
                if (f1 && wkx == Bx && (wky - By)*(wky - r1y) <= 0)
                    beat1 = false;
                if (f2 && wky == By && (wkx - Bx)*(wkx - r1x) <= 0)
                    beat1 = false;
            }

            if (f3 == f4) beat2 = false;
            else {
                beat2 = true;
                if (f3 && wkx == Bx && (wky - By)*(wky - r2y) <= 0)
                    beat2 = false;
                if (f4 && wky == By && (wkx - Bx)*(wkx - r2x) <= 0)
                    beat2 = false;
    }

            if (!beat1 && !beat2) {
                puts("OTHER");
                return 0;
            }
        }
        
    puts("CHECKMATE");
}