/*
kotlinheroes
kotlin
ync
copy from https://codeforces.com/contest/1211/submission/60227082
*/
/*
kotlinheroes
kotlin
t
copy from https://codeforces.com/contest/1211/submission/60227082
*/

// Fresh Peach Heart Shower
/*
#include <bits/stdc++.h>
#define reg
#define ALL(x) (x).begin(),(x).end()
#define mem(x,y) memset(x,y,sizeof x)
#define sz(x) (int)(x).size()
#define ln putchar('\n')
#define lsp putchar(32)
#define pb push_back
#define MP std::make_pair
#define MT std::make_tuple
#ifdef _LOCAL_
#define dbg(x) std::cerr<<__func__<<"\tLine:"<<__LINE__<<' '<<#x<<": "<<x<<"\n"
#define dprintf(x...) std::fprintf(stderr,x)
#else
#define dbg(x) 42
#define dprintf(x...) 42
#endif
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
typedef std::pair<int,int> pii;
typedef std::vector<int> poly;
template <class t> inline void read(t &s){s=0;
signed f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
while(isdigit(c))s=(s<<3)+(s<<1)+(c^48),c=getchar();;s*=f;}
template<class t,class ...A> inline void read(t &x,A &...a){read(x);read(a...);}
template <class t> inline void write(t x){if(x<0)putchar('-'),x=-x;
static int buf[50],top=0;while(x)buf[++top]=x%10,x/=10;if(!top)buf[++top]=0;
while(top)putchar(buf[top--]^'0');}
inline void setIn(std::string s){freopen(s.c_str(),"r",stdin);return;}
inline void setOut(std::string s){freopen(s.c_str(),"w",stdout);return;}
inline void setIO(std::string s=""){setIn(s+".in");setOut(s+".out");return;}
template <class t>inline bool ckmin(t&x,t y){if(x>y){x=y;return 1;}return 0;}
template <class t>inline bool ckmax(t&x,t y){if(x<y){x=y;return 1;}return 0;}
inline int lowbit(int x){return x&(-x);}
const int MaxN=2e5+50;
std::set<int> E[MaxN];
int c[MaxN],d[MaxN],n;
inline void work()
{
	read(n);
	rep(i,1,n)E[i].clear();
	rep(i,1,n)read(c[i]);
	rep(i,1,n)read(d[i]);
	int u,v;
	poly deg(n+1),D(n+1);
	rep(i,1,n-1)read(u,v),E[u].insert(v),E[v].insert(u),++deg[u],++deg[v];
	std::queue<int> Q;
	rep(i,1,n)if(E[i].size()==1u)Q.push(i),D[i]=1;
	int N=n;
	while(!Q.empty())
	{
		int u=Q.front();Q.pop();
		if(c[u]!=d[u])continue;
		--N,--deg[u];
		poly del;
		for(auto v:E[u])if(!D[v])
		{
			del.pb(v);
			if((--deg[v])==1)Q.push(v),D[v]=1;
		}
		for(auto v:del)E[u].erase(v),E[v].erase(u);
	}
	if(!N)return std::puts("Yes\n0"),void();
	if(N==1)return std::puts("No"),void();
	poly dr;
	rep(i,1,n)if(E[i].size())dr.pb(i);
	int ct1=0,ct2=0;
	for(auto i:dr)ct1+=E[i].size()==1u,ct2+=E[i].size()==2u;
	if(ct1+ct2!=N)return std::puts("No"),void();
	if(ct2!=N-2||ct1!=2)return std::puts("No"),void();
	dr.clear();
	{
		int x=1;
		while(E[x].size()!=1)++x;
		dr.pb(x);
		int lst=x;
		x=*E[x].begin();
		while(E[x].size()>1u)dr.pb(x),E[x].erase(lst),lst=x,x=*E[x].begin();
		dr.pb(x);
	}
	int ok=c[dr[0]]==d[dr[N-1]];
	rep(i,0,(int)dr.size()-2)ok&=c[dr[i+1]]==d[dr[i]];
	if(ok)
	{
		std::puts("Yes");
		write(N),ln;
		for(auto i:dr)write(i),lsp;ln;
		return ;
	}
	std::reverse(ALL(dr));
	ok=c[dr[0]]==d[dr[N-1]];
	rep(i,0,(int)dr.size()-2)ok&=c[dr[i+1]]==d[dr[i]];
	if(ok)
	{
		std::puts("Yes");
		write(N),ln;
		for(auto i:dr)write(i),lsp;ln;
		return ;
	}
	std::puts("No");
}
signed main(void)
{
	int t;read(t);
	while(t--)work();
	return 0;
}

*/

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var tt = readInt()
    while (tt-- > 0) {
        var n = readInt()
        var initC = readInts()
        var c = initC.toMutableList()
        var d = readInts()
        var g = Array<MutableList<Int>>(n, { i -> mutableListOf() })
        for (i in 0..n-2) {
            var (x, y) = readInts()
            x--
            y--
            g[x].add(y)
            g[y].add(x)
        }
        var pv = IntArray(n, {-1})
        var dist = IntArray(n, {-1})
        var start = -1
        fun Dfs(v: Int) {
            if (c[v] != d[v]) {
                if (start == -1 || dist[v] > dist[start]) {
                    start = v
                }
            }
            for (u in g[v]) {
                if (u == pv[v]) {
                    continue
                }
                pv[u] = v
                dist[u] = dist[v] + 1
                Dfs(u)
            }
        }
        dist[0] = 0
        Dfs(0)
        if (start == -1) {
            println("Yes")
            println("0")
            continue
        }
        var found = false
        for (iter in 0..1) {
            var noteq = 0
            for (i in 0..n - 1) {
                noteq += if (c[i] != d[i]) 1 else 0
            }
            pv = IntArray(n, { -1 })
            dist = IntArray(n, { -1 })
            var ans = -1
            var newstart = -1
            fun Solve(v: Int) {
                if (initC[v] != d[v]) {
                    if (newstart == -1 || dist[v] > dist[newstart]) {
                        newstart = v
                    }
                }
                if (noteq == 0) {
                    if (ans == -1 || dist[v] < dist[ans]) {
                        ans = v
                    }
                    return
                }
                for (u in g[v]) {
                    if (u == pv[v]) {
                        continue
                    }
                    var oldnoteq = noteq
                    if (c[v] != d[v]) noteq--
                    if (c[u] != d[u]) noteq--
                    var tmp = c[v]
                    c[v] = c[u]
                    c[u] = tmp
                    if (c[v] != d[v]) noteq++
                    if (c[u] != d[u]) noteq++
                    pv[u] = v
                    dist[u] = dist[v] + 1
                    Solve(u)
                    noteq = oldnoteq
                    tmp = c[v]
                    c[v] = c[u]
                    c[u] = tmp
                }
            }
            Solve(start)
            if (ans != -1) {
                println("Yes")
                var res = ArrayList<Int>()
                while (ans != start) {
                    res.add(ans + 1)
                    ans = pv[ans]
                }
                res.add(start + 1)
                res.reverse()
                println(res.size)
                println(res.joinToString(" "))
                found = true
                break
            }
            start = newstart
        }
        if (!found) println("No")
    }
}