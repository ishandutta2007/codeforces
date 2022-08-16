#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
 
#define X first
#define Y second
 
//#include <boost/unordered_map.hpp>
//using namespace boost;
 
/*
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> rbtree;
//rbtree T;
template<class T>
using rbtree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//rbtree<int> T;
//template<class T, class cmp = less<T>, class tag = pairing_heap_tag>
//using pqueue = __gnu_pbds::priority_queue<T, cmp, tag>;
template<class T, class cmp = less<T>>
using pqueue = __gnu_pbds::priority_queue<T, cmp>;
//pqueue<int> T;
*/
 
using i32 = int;
using i64 = long long;
using u8 = unsigned char;
using u32 = unsigned;
using u64 = unsigned long long;
using f64 = double;
using f80 = long double;
//using i128 = __int128_t;
//using u128 = __uint128_t;
//using i128 = i64;
//using u128 = u64;
 
ll power(ll a, ll b, ll p)
{
	if (!b) return 1;
	ll t = power(a, b/2, p);
	t = t*t%p;
	if (b&1) t = t*a%p;
	return t;
}
 
ll exgcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll px, py;
	ll d = exgcd(b, a%b, px, py);
	x = py;
	y = px-a/b*py;
	return d;
}
 
template<class T>
inline void freshmin(T &a, const T &b)
{
	if (a > b) a = b;
}
 
template<class T>
inline void freshmax(T &a, const T &b)
{
	if (a < b) a = b;
}

const int MAXN = 100010;

int n, p;
priority_queue<pii, vector<pii>, greater<pii> > events;
queue<int> q;
priority_queue<int, vector<int>, greater<int> > waiting;
ll ans[MAXN];

int main()
{
        
        scanf("%d%d", &n, &p);
        for (int i = 1; i <= n; ++ i)
        {
                int x;
                scanf("%d", &x);
                events.push({x, i});
        }
        
        ll now = 0;
        for (int i = 1; i <= n; ++ i)
        {
                if (q.empty() && waiting.empty()) now = events.top().first;
                now += p;
                while (!events.empty() && events.top().first <= now)
                {
                        int id = events.top().second;
                        events.pop();
                        if (q.empty() || id < q.back()) q.push(id);
                        else waiting.push(id);
                }
                
                ans[q.front()] = now;
                q.pop();
                
                if (q.empty() && !waiting.empty())
                {
                        q.push(waiting.top());
                        waiting.pop();
                }
        }
        
        for (int i = 1; i <= n; ++ i)
                printf("%lld ", ans[i]);
        
        return 0;
}