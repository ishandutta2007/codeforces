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


struct State
{
    long long up, down, xup, xdown, id;

    State() : up(), down(), xup(), xdown(), id() {}
    State(long long _up, long long _down, long long _xup, long long _xdown, int _id) : 
        up(_up), down(_down), xup(_xup), xdown(_xdown), id(_id) 
    {
        if (down < 0)
        {
            up = -up;
            down = -down;
        }
        if (xdown < 0)
        {
            xup = -xup;
            xdown = -xdown;
        }
    }

    bool operator < (const State &A) const
    {
        long long x = up * A.down - down * A.up;
        long long xx = xup * A.xdown - xdown * A.xup;
        if (x != 0) return x < 0;
        if (xx != 0) return xx > 0;

        return id < A.id;
    }
};

const int N = (int) 1e5 + 100;
int posSt[N];
vector <State> st, en;

int p[N], v[N], s[N];

int fn[N];
void add(int pos, int val)
{
    pos++;
    for (; pos < N; pos = (pos | (pos - 1) ) + 1)
        fn[pos] += val;
}
int sum(int pos)
{
    pos++;
    int ans = 0;
    for (; pos > 0; pos = pos & (pos - 1))
        ans += fn[pos];
    return ans;
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, w;
    scanf("%d%d", &n, &w);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &s[i], &v[i]);
        st.emplace_back(v[i] - w, -s[i], v[i] + w, -s[i], i);
        en.emplace_back(v[i] + w, -s[i], v[i] - w, -s[i], -i);
    }
    sort(st.begin(), st.end() );
    sort(en.begin(), en.end() );
    for (int i = 0; i < n; i++)
        posSt[st[i].id] = i;
    
    for (int i = 0; i < n; i++)
    {
        int x = -en[i].id;
        p[i] = posSt[x];
    }
    
    
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x = p[i];
        ans += i - sum(x);
        add(x, 1);
    }
    printf("%lld\n", ans);

	return 0;
}