#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


struct SAT
{
    int vals;
    string s;

    SAT() : vals(-1), s() {}
    SAT(int _vals, string _s) : vals(_vals), s(_s) {}

    bool none()
    {
        return vals == -1;
    }

    bool operator < (const SAT &A) const
    {
        if (s.length() != A.s.length() ) return s.length() < A.s.length();
        return s < A.s;
    }

    SAT operator | (const SAT &A) const
    {
        return SAT(vals | A.vals, s + "|" + A.s);
    }
    SAT operator & (const SAT &A) const
    {
        return SAT(vals & A.vals, s + "&" + A.s);
    }
    SAT operator -() const
    {
        return SAT(vals ^ ((1<<8)-1), "!" + s);
    }
    SAT brac() const
    {
        return SAT(vals, "(" + s + ")");
    }
};


const int XX = 256;
const int K = 30;
vector <int> E[K], T[K], F[K];
SAT usedE[XX], usedT[XX], usedF[XX];


void addX(const SAT & x, SAT usedX[], vector <int> X[] )
{
//    if (x.vals == 51)
//    {
//        eprintf("new : %s, old : %s\n", x.s.c_str(), usedX[x.vals].s.c_str() );
//    }
    if (usedX[x.vals].none() || x < usedX[x.vals] )
    {
        if (usedX[x.vals].none() )
            X[(int)x.s.length()].push_back(x.vals);
        usedX[x.vals] = x;
    }
}


/*

E ::= E '|' T | T

T ::= T '&' F | F

F ::= '!' F | '(' E ')' | 'x' | 'y' | 'z'

*/

void init()
{
    SAT x = SAT((1 << 4) - 1, "x");
    SAT y = SAT(3 | (3 << 4), "y");
    SAT z = SAT(1 | 4 | 16 | 64, "z");

  //  eprintf("%d\n", x.vals);
 //   eprintf("%d\n", y.vals);
  //  eprintf("%d\n", z.vals);

    addX(x, usedF, F);
    addX(y, usedF, F);
    addX(z, usedF, F);

    for (int i = 1; i < K; i++)
    {
        {
            if (i >= 2)
            {
                for (int _e : E[i - 2] )
                {
                    SAT e = usedE[_e];
                    SAT nf = e.brac();
                    addX(nf, usedF, F);
                }
            }
            for (int _f : F[i - 1] )
            {
                SAT f = usedF[_f];
                SAT nf = -f;
                addX(nf, usedF, F);
            }
        }

        {
            for (int lt = 1; lt + 1 < i; lt++)
            {
                int lf = i - lt - 1;
                for (int _t : T[lt] )
                    for (int _f : F[lf] )
                    {
                        SAT t = usedT[_t], f = usedF[_f];
                        SAT nt = (t & f);
                        addX(nt, usedT, T);
                    }
            }
            for (int _f : F[i] )
            {
                SAT f = usedF[_f];
                SAT nt = f;
                addX(nt, usedT, T);
            }

        }

        {
            for (int le = 1; le + 1 < i; le++)
            {
                int lt = i - le - 1;
                for (int _e : E[le] )
                    for (int _t : T[lt] )
                    {
                        SAT e = usedE[_e], t = usedT[_t];
                        SAT ne = (e | t);
                        addX(ne, usedE, E);
                    }
            }
            for (int _t : T[i] )
            {
                SAT t = usedT[_t];
                SAT ne = t;
                addX(ne, usedE, E);
            }
        }
    }
}


const int LE = 10;
char str[LE];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    init();
    for (int i = 0; i < (1 << 8); i++)
        if (usedE[i].none() ) throw;
//        printf("%s\n", usedE[i].s.c_str() );

    int n;
    scanf("%d", &n);
    for (int it = 0; it < n; it++)
    {
       scanf("%s", str);
//       reverse(str, str + 8);
       int x = 0;
       for (int i = 0; i < 8; i++)
       {
           x *= 2;
           x += (str[i] - '0');
       }
//       eprintf("x = %d\n", x);
       printf("%s\n", usedE[x].s.c_str() );
    }


	return 0;
}