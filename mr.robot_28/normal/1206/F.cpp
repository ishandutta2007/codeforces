#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef long long ll;
 
template <class T> ostream& operator << (ostream &os, const vector<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T> ostream& operator << (ostream &os, const set<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const pair<T, S> &v) { os << v.first << ' ' << v.second; return os; }
template <class T, class S> ostream& operator << (ostream &os, const map<T, S> &v) { for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const unordered_map<T, S> &v) { for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' '; return os; }
 
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <class Arg1> void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << endl; }
    template <class Arg1, class... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args) {
        const char* sep = strchr(names + 1, ',');
        cerr.write(names, sep - names) << " : " << arg1 << "  ";
        __f(sep + 1, args...);
    }
#else
#define trace(...) 0
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#endif // ifndef ONLINE_JUDGE
 
#define endl "\n"
#define vll vector<int>
#define max_heap priority_queue<int>
#define min_heap priority_queue<int , vector<int>, greater<int> >
#define pb push_back
#define all(container) container.begin(), container.end()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define printArr(name,from,to) for(int x = from; x < to; x++) cout << name[x] << " ";
#define fi first
#define se second
#define mp make_pair
#define prime1 304933
#define prime2 15486277 
#define mod2 179424691
// #define int ll
 
typedef tree<ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set; 
 
const ll MOD = 1000000007;
const ll MAX = 1e3 + 10;
const double PI = 3.1415926;
const ll INF = 1e18;
const double EPS = 1e-5;
vll adj[MAX];
int centroid;
int sub_sz[MAX];
int cnt, step;
 
bool cmp(const int& lhs, const int& rhs){
	return (sub_sz[lhs] < sub_sz[rhs]);
}
 
void dfs(int s, int p){
	sub_sz[s]=1;
	for(int x : adj[s]){
		if (x == p) continue;
		dfs(x,s);
		sub_sz[s]+=sub_sz[x];
	}
	return ;
}
 
void find_cent(int s, int p, int n){
	dfs(s,p);
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int source = q.front();
		q.pop();
		bool found = true;
		for(int x : adj[source]){
			if (x == p) continue;
			if (sub_sz[x] > n/2){
				q.push(x);
				p = source;
				found = false;
				break;
			}
		}
		if (found){
			centroid = source;
			dfs(source,-1);
			return ;
		}
	}
}
 
void dfs1(int s, int p, int carry){
	int place = cnt-carry;
	cout << s << " " << p << " " << cnt - carry << endl;
	cnt+=step;
	bool first = true;
	for(int x : adj[s]){
		if (x == p) continue;
		dfs1(x,s,place+carry);
	}
}
 
signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	clock_t t1, t2;
	t1 = clock();
	int n;
	cin >> n;
	for(int i = 0; i < n-1; ++i){
		int x,y;cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	find_cent(1,-1,n);
	vector<int> adj_cent(adj[centroid]);
	sort(all(adj_cent), cmp);
	// trace(centroid, adj_cent);
	int i = 0;
	cnt = 1;
	step = 1;
	while(i < adj_cent.size() && (cnt-1)*3 < n){
		dfs1(adj_cent[i], centroid, 0);
		++i;
	}
	step = cnt;
	
	while(i < adj_cent.size()){
		dfs1(adj_cent[i], centroid, 0);
		++i;
	}
 
	t2 = clock(); cerr << "time taken: " << (t2-t1)/(long double)CLOCKS_PER_SEC << endl;
	return 0;
}