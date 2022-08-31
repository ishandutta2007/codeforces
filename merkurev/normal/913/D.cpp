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


struct Task
{
    int a, t, id;

    Task() : a(), t(), id() {}
    Task(int _a, int _t, int _id) : a(_a), t(_t), id(_id) {}

    void read(int _id)
    {
        id = _id;
        scanf("%d%d", &a, &t);
    }

    bool operator < (const Task &A) const
    {
        if (a != A.a) return a < A.a;
        if (t != A.t) return t < A.t;
        return id < A.id;
    }
};


const int N = (int) 2e5 + 100;
Task task[N];


set <Task> solve;
int solvet;
int n, T;


int f(int prat = -1)
{
    solve.clear();
    solvet = 0;


    int ans = 0;
    int ansat = 0;
    int ptr = 0;

    if (prat == 0)
    {
        printf("0\n0\n\n");
        return -1;
    }

    for (int cnt = n; cnt >= 1; cnt--)
    {
        if ((int) solve.size() > cnt)
        {
            solvet -= solve.rbegin()->t;
            solve.erase(*solve.rbegin() );
        }


        while (ptr < n && task[ptr].a == cnt)
        {
            Task cur = task[ptr++];
            cur.a = 0;

            while (solvet + cur.t > T || (int) solve.size() == cnt)
            {
                if (solve.empty() ) break;
                if (solve.rbegin()->t <= cur.t) break;
                solvet -= solve.rbegin()->t;
                solve.erase(*solve.rbegin() );
            }

            if (solvet + cur.t <= T && (int) solve.size() < cnt)
            {
                solvet += cur.t;
                solve.insert(cur);
            }

        }

        if (prat == cnt)
        {
            int k = (int) solve.size();
#ifdef LOCAL
            eprintf("k = %d, cnt = %d\n", k, cnt);
            if (k != cnt) throw;
#endif
            printf("%d\n%d\n", k, k);
            for (Task i : solve)
                printf("%d ", i.id + 1);
            printf("\n");
            return -1;
        }

        eprintf("cnt = %d, sz = %d\n", cnt, (int) solve.size() );
        if ((int) solve.size() > 0 && (int) solve.size() >= ans)
        {
            ans = (int) solve.size();
            ansat = cnt;
        }
    }
    eprintf("ans = %d, anssat = %d\n", ans, ansat);
    return ansat;
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    scanf("%d%d", &n, &T);

    for (int i = 0; i < n; i++)
        task[i].read(i);
    sort(task, task + n);
    reverse(task, task + n);

    int id = f();
    eprintf("id = %d\n", id);
    f(id);


	return 0;
}