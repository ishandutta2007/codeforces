/*
    27.08.2018 18:55:48
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

ostream & operator << (ostream & o, string & s) {
    o << '"';
    for (int i = 0; i < s.length(); ++i)
    {
        o << s[i];
    }
    o << '"';
    return o;
}

template< typename T >
ostream & operator << (ostream & o, vector< T > & v) {
    bool first = true;
    o << "[";
    for (typename vector< T >::iterator i = v.begin(); i != v.end(); i++)
    {
        if (!first) {
            o << ", ";
        }
        first = false;
        o << *i;
    }
    o << "]";
    return o;
}

template< typename T >
ostream & operator << (ostream & o, set< T > & s) {
    bool first = true;
    o << "(";
    for (typename set< T >::iterator i = s.begin(); i != s.end(); i++)
    {
        if (!first) {
            o << ", ";
        }
        first = false;
        o << *i;
    }
    o << ")";
    return o;
}

template< typename T >
ostream & operator << (ostream & o, multiset< T > & s) {
    bool first = true;
    o << "(";
    for (typename multiset< T >::iterator i = s.begin(); i != s.end(); i++)
    {
        if (!first) {
            o << ", ";
        }
        first = false;
        o << *i;
    }
    o << ")";
    return o;
}

template< typename T1, typename T2 >
ostream & operator << (ostream & o, map< T1, T2 > & m) {
    bool first = true;
    o << "{";
    for (typename map < T1, T2 >::iterator i = m.begin(); i != m.end(); i++)
    {
        if (!first) {
            o << ", ";
        }
        first = false;
        o << i->first << ": " << i->second;
    }
    o << "}";
    return o;
}

template< typename T1, typename T2 >
ostream & operator << (ostream & o, pair< T1, T2 > & p) {
    o << "(" << p.first << ", " << p.second << ")";
    return o;
}

int main(int argc, char const *argv[])
{
    if (debug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int test_count = 2;
    if (!debug) {
        test_count = 1;
    }
    for (int test = 0; test < test_count; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        long long n;
        cin >> n;
        vector< long long > a(n), b(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> b[i];
        }
        vector< long long > sum(n);
        sum[n - 1] = a[n - 1] + b[n - 1];
        for (int i = n - 2; i > -1; i--) {
            sum[i] = sum[i + 1] + a[i] + b[i];
        }
        vector< long long > a_sm(n, 0), b_sm(n, 0);
        a_sm[n - 1] = b[n - 1];
        b_sm[n - 1] = a[n - 1];
        for (long long i = n - 2; i > -1; i--) {
            a_sm[i] = a_sm[i + 1] + sum[i + 1] + (2ll * (n - i) - 1ll) * b[i];
            b_sm[i] = b_sm[i + 1] + sum[i + 1] + (2ll * (n - i) - 1ll) * a[i];
        }
        if (debug) {
            cout << "a_sm = " << a_sm << endl;
        }
        if (debug) {
            cout << "b_sm = " << b_sm << endl;
        }
        vector< long long > a_mx(n, 0), b_mx(n, 0);
        a_mx[n - 1] = a_sm[n - 1];
        b_mx[n - 1] = b_sm[n - 1];
        for (int i = n - 2; i > -1; i--) {
            a_mx[i] = max(a_sm[i], b[i] + b_mx[i + 1] + sum[i + 1] * 2ll);
            b_mx[i] = max(b_sm[i], a[i] + a_mx[i + 1] + sum[i + 1] * 2ll);
        }
        cout << a_mx[0] << endl;
    }
    fclose(stdout);
    return 0;
}