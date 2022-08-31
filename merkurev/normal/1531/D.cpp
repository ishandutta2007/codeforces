#ifndef LOCAL
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#endif

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


const int LOG = 18;
const int LEVEL = (1 << LOG);
const int SZ = (LEVEL << 1);

const int T_NONE = 0;
const int T_LOCK = 1;
const int T_UNLOCK = 2;

map <string, int> color_id;
vector <string> colors;

int get_id(string s)
{
    if (color_id.count(s) == 0)
    {
        color_id[s] = (int) colors.size();
        colors.push_back(s);
    }
    return color_id[s];
}

struct Value
{
    int lock_change;
    int color_unlocked;
    int color_locked;

    Value() {}

    Value(string s)
    {
        if (s == "lock")
        {
            lock_change = T_LOCK;
            color_unlocked = -1;
            color_locked = -1;
        }
        else if (s == "unlock")
        {
            lock_change = T_UNLOCK;
            color_unlocked = -1;
            color_locked = -1;
        }
        else if (s == "none")
        {
            lock_change = T_NONE;
            color_unlocked = -1;
            color_locked = -1;
        }
        else 
        {
            lock_change = T_NONE;
            color_unlocked = get_id(s);
            color_locked = -1;
        }
    }

    Value operator + (const Value &A) const
    {
        Value ans = Value();
        
        if (A.lock_change != T_NONE)
            ans.lock_change = A.lock_change;
        else
            ans.lock_change = lock_change;
        
        if (lock_change == T_NONE)
        {
            if (A.color_locked == -1)
                ans.color_locked = color_locked;
            else
                ans.color_locked = A.color_locked;

            if (A.color_unlocked == -1)
                ans.color_unlocked = color_unlocked;
            else
                ans.color_unlocked = A.color_unlocked;
        }
        else if (lock_change == T_LOCK)
        {
            if (A.color_locked == -1)
            {
                ans.color_locked = color_locked;
                ans.color_unlocked = color_unlocked;
            }
            else
            {
                ans.color_locked = ans.color_unlocked = A.color_locked;
            }
        }
        else if (lock_change == T_UNLOCK)
        {
            if (A.color_unlocked == -1)
            {
                ans.color_locked = color_locked;
                ans.color_unlocked = color_unlocked;
            }
            else
            {
                ans.color_locked = ans.color_unlocked = A.color_unlocked;
            }
        }
        return ans;
    }

};

struct Tree
{
    Value a[SZ];

    Tree()
    {
        for (int i = LEVEL; i < SZ; i++)
            a[i] = Value("none");

        a[LEVEL] = Value("blue");

        for (int i = LEVEL - 1; i >= 1; i--)
            a[i] = a[2 * i] + a[2 * i + 1];
    }

    void set_value(int pos, string s)
    {
        pos += LEVEL;
        a[pos] = Value(s);

        while (pos > 1)
        {
            pos /= 2;
            a[pos] = a[2 * pos] + a[2 * pos + 1];
        }
    }

    string get_color()
    {
        return colors[a[1].color_unlocked];
    }

} tree;



char str[105];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", str);
        tree.set_value(i, string(str));  
    }

    int q;
    scanf("%d", &q);

    printf("%s\n", tree.get_color().c_str());

    for (int i = 0; i < q; i++)
    {
        int pos;
        scanf("%d%s", &pos, str);
        tree.set_value(pos, string(str));

        printf("%s\n", tree.get_color().c_str());
    }



	return 0;
}