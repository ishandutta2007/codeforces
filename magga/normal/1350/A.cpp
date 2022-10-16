#include <bits/stdc++.h>
using namespace std;

template<class T> ostream& operator<<(ostream &os, vector<T> V){
	os << "[ ";
	for(auto v  : V) os << v << " ";
	return os << " ]";
}
template<class T> ostream& operator<<(ostream &os, set<T> V){
	os << "[ ";
	for(auto v  : V) os << v << " ";
	return os << " ]";
}
template<class T , class R > ostream& operator<<(ostream &os, map<T , R> V){
	os << "[ ";
	for(auto v  : V) os << "(" << v.first << ":" << v.second << ")";
	return os << " ]";
}
template<class T , class R > ostream& operator<<(ostream &os, pair<T , R> V){
	return os << "(" << V.first << "," << V.second << ")";
}

// #define TRACE
#ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << std::endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1<<" | ";
        __f(comma+1, args...);
    }
#else
    #define trace(...)
#endif

typedef long long int lli;
typedef vector<lli> vll;
typedef vector<vector<lli>> vvl;
typedef vector<pair<lli, lli>> vpll;
typedef pair<lli, lli> pll;
typedef pair<long double, long double> pdd;
typedef pair<lli, vll> plv;
typedef pair<long double, vll> pdv;
typedef map<lli, lli> mll;
typedef map<lli, vll> mlv;
#define pb push_back
#define google cout << "Case #" << TT << ": ";
#define fin for (lli i = 0; i < n; i++)
#define fi(n) for (lli i = 0; i < n; i++)
#define fj(n) for (lli j = 0; j < n; j++)
#define fiv for (lli i = 0; i < v.size(); i++)
#define fis for (lli i = 0; i < s.size(); i++)
#define rep(i,s,e) for (lli i = s; i != e; i += (e>s)?1:-1)
#define vs v.size()
#define ss s.size()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli TC = 1;
    cin >> TC;

    vector<lli> primes;
    primes.push_back(2);
    for(lli i=3; i <= 1e6; i++)
    {
        bool prime=true;
        for(lli j=0;j<primes.size() && primes[j]*primes[j] <= i;j++)
        {
            if(i % primes[j] == 0)
            {
                prime=false;
                break;
            }
        }
        if(prime) 
        {
            primes.push_back(i);
            // cout << i << " ";
        }
    }

    for (lli TT = 1; TT<=TC; TT++) {
        lli n, k;
        cin >> n >> k;
        for(lli j=0; j<primes.size(); j++){
            trace(TT, n, j, primes[j], n%primes[j]==0);
            if (n%primes[j]==0){
                n+=primes[j];
                break;
            }
        }
        fi(k-1){
            n+=2;
        }
        cout << n << "\n";
    }
    return 0;
}