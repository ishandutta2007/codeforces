#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <deque>
#include <cassert>
#include <ctime>
#include <ctype.h>

using namespace std;



struct fastInOut
{
    bool isEoln(char c)
    {
        return c == 10 || c == 13 || c == '\n' || c == EOF;
    }

    int nextInt()
    {
        char c = 'x';
        bool minus = false;
        int res = 0;
        while (!isdigit(c) && c != '+' && c != '-')
            c = getc(stdin);
        if (c == '-')
            minus = true;
        if (c == '-' || c == '+')
            c = getc(stdin);
        while(isdigit(c))
        {
            res = res * 10 + (int)c  -(int)'0';
            c = getc(stdin);
        }
        if (minus)
            res = -res;
        return res;
    }

    long long nextLongLong()
    {
        char c = 'x';
        bool minus = false;
        long long res = 0;
        while (!isdigit(c) && c != '+' && c != '-')
            c = getc(stdin);
        if (c == '-')
            minus = true;
        if (c == '-' || c == '+')
            c = getc(stdin);
        while(isdigit(c))
        {
            res = res * 10 + (int)c  -(int)'0';
            c = getc(stdin);
        }
        if (minus)
            res = -res;
        return res;
    }

    string nextString(char stop = ' ')
    {
        string result;
        char c = getc(stdin);
        while (!isEoln(c) && c != stop)
        {
            result += c;
            c = getc(stdin);
        }
        return result;

    }

    string nextLine()
    {
        string result;
        char c = getc(stdin);
        while (!isEoln(c))
        {

            result += c;
            c = getc(stdin);
        }
        return result;
    }

    void printInt(int n)
    {
        if (n == 0)
        {
            putc('0', stdout);
            return;
        }
        if (n < 0)
        {
            putc('-', stdout);
            n = -n;
        }
        char buf[21];
        int size = 0;
        while (n > 0)
        {
            buf[size++] = n % 10 + '0';
            n /= 10;
        }
        for (int i = size - 1; i >= 0; --i)
            putc(buf[i], stdout);
    }

    void printLongLong(long long n)
    {
        if (n == 0)
        {
            putc('0', stdout);
            return;
        }
        if (n < 0)
        {
            putc('-', stdout);
            n = -n;
        }
        char buf[25];
        int size = 0;
        while (n > 0)
        {
            buf[size++] = n % 10 + '0';
            n /= 10;
        }
        for (int i = size - 1; i >= 0; --i)
            putc(buf[i], stdout);

    }

    void printLn()
    {
        puts("");
    }

    void printChar(char c)
    {
        putc(c, stdout);
    }

    void printString(const string & s)
    {
        for (int i = 0; i < s.length(); ++i)
            putc(s[i], stdout);
    }
};




fastInOut io;


struct fenw_tree
{
    vector<int> f;

    void init(int n)
    {
        f.assign(n, 0);
    }

    void update(int pos, int val)
    {
        for (; pos < f.size(); pos = (pos | (pos + 1)))
            f[pos] += val;
    }

    int _get_sum(int pos)
    {
        int res = 0;
        for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
            res += f[pos];
        return res;
    }

    int get_sum(int l, int r)
    {
        return _get_sum(r) - _get_sum(l - 1);
    }
};

struct man
{
    long long start, fin, start_t, id;

    man() {}

    man(int _start, int _fin, int _start_t, int _id)
    {
        start = _start;
        fin = _fin;
        start_t = _start_t;
        id = _id;
    }

    void read(int _id)
    {
        id = _id;
        start_t = io.nextInt();
        start = io.nextInt();
        fin = io.nextInt();
        --start;
        --fin;
    }
};


const int N = 100 * 1000 + 100;
vector<man> at_floor[N];
vector<man> want_this[N];
fenw_tree in, out;
man all[N];
long long ans[N];
multiset<long long> events;

bool cmp_time(man a, man b)
{
    return a.start_t < b.start_t;
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    n = io.nextInt();
    m = io.nextInt();

    in.init(m + 2);
    out.init(m + 2);

    for (int i = 0; i < n; ++i)
        all[i].read(i);
    sort(all, all + n, cmp_time);

    int cur_floor = 0;
    long long time = 0;
    int ptr = 0;

    for (;;)
    {
        //cerr << cur_floor + 1 << " " << time << endl;

        for (; want_this[cur_floor].size() > 0;)//going outside the elevator
        {
            man v = want_this[cur_floor].back();
            want_this[cur_floor].pop_back();
            ans[v.id] = time;
            in.update(v.fin, -1);
            events.erase(events.find(v.fin));
        }


        for (; at_floor[cur_floor].size() > 0;) //going inside the elevator
        {
            man v = at_floor[cur_floor].back();
            at_floor[cur_floor].pop_back();
            want_this[v.fin].push_back(v);
            in.update(v.fin, 1);
            out.update(v.start, -1);
            events.erase(events.find(v.start));
            events.insert(v.fin);
        }

        int high = in.get_sum(cur_floor + 1, m + 1) + out.get_sum(cur_floor + 1, m + 1);
        int low = in.get_sum(0, max(0, cur_floor - 1)) + out.get_sum(0, max(0, cur_floor - 1));

        if (cur_floor == m - 1)
            high = -1;
        if (cur_floor == 0)
            low = -1;

        multiset<long long>::iterator it;
        long long fin_time;

        if (high >= low)
        {
            it = events.lower_bound(cur_floor);

            if (events.size() == 0)
                fin_time = (long long)1e18;
            else
                fin_time = *it - cur_floor + time;

            bool any = false;
            bool es = events.size() ? true : false;
            while (ptr != n && all[ptr].start_t <= fin_time)
            {
                fin_time = all[ptr].start_t;
                if (events.size() == 0)
                    time = fin_time;
                man v = all[ptr];
                events.insert(v.start);
                out.update(v.start, 1);
                at_floor[v.start].push_back(v);
                ++ptr;
                any = true;
            }
            if (any && !es)
                continue;
            cur_floor = min(*it, cur_floor + fin_time - time);
            time = fin_time;
        }
        else
        {
            it = events.lower_bound(cur_floor);

            if (events.size() == 0)
                fin_time = (long long)1e18;
            else
                fin_time = cur_floor - *(--it) + time;

            bool any = false;
            bool es = events.size() ? true : false;
            while (ptr != n && all[ptr].start_t <= fin_time)
            {
                any = true;
                fin_time = all[ptr].start_t;
                if (events.size() == 0)
                    time = fin_time;
                man v = all[ptr];
                events.insert(v.start);
                out.update(v.start, 1);
                at_floor[v.start].push_back(v);
                ++ptr;
            }
            if (any && !es)
                continue;

            cur_floor = max(*it, cur_floor + time - fin_time);
            time = fin_time;
        }

        if (ptr == n && in.get_sum(0, m) == 0 && out.get_sum(0, m) == 0)
            break;
    }

    for (int i = 0; i < n; ++i)
    {
        io.printLongLong(ans[i]);
        io.printLn();
    }


    return 0;
}