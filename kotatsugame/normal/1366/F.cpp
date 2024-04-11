#include<cstdio>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
template< typename T, T x_low, T x_high, T id >
struct DynamicLiChaoTree {

  struct Line {
    T a, b;

    Line(T a, T b) : a(a), b(b) {}

    inline T get(T x) const { return a * x + b; }
  };

  struct Node {
    Line x;
    Node *l, *r;

    Node(const Line &x) : x{x}, l{nullptr}, r{nullptr} {}
  };

  Node *root;

  DynamicLiChaoTree() : root{nullptr} {}

  Node *add_line(Node *t, Line &x, const T &l, const T &r, const T &x_l, const T &x_r) {
    if(!t) return new Node(x);

    T t_l = t->x.get(l), t_r = t->x.get(r);

    if(t_l <= x_l && t_r <= x_r) {
      return t;
    } else if(t_l >= x_l && t_r >= x_r) {
      t->x = x;
      return t;
    } else {
      T m = (l + r) / 2;
      if(m == r) --m;
      T t_m = t->x.get(m), x_m = x.get(m);
      if(t_m > x_m) {
        swap(t->x, x);
        if(x_l >= t_l) t->l = add_line(t->l, x, l, m, t_l, t_m);
        else t->r = add_line(t->r, x, m + 1, r, t_m + x.a, t_r);
      } else {
        if(t_l >= x_l) t->l = add_line(t->l, x, l, m, x_l, x_m);
        else t->r = add_line(t->r, x, m + 1, r, x_m + x.a, x_r);
      }
      return t;
    }
  }

  void add_line(const T &a, const T &b) {
    Line x(a, b);
    root = add_line(root, x, x_low, x_high, x.get(x_low), x.get(x_high));
  }

  Node *add_segment(Node *t, Line &x, const T &a, const T &b, const T &l, const T &r, const T &x_l, const T &x_r) {
    if(r < a || b < l) return t;
    if(a <= l && r <= b) {
      Line y{x};
      return add_line(t, y, l, r, x_l, x_r);
    }
    if(t) {
      T t_l = t->x.get(l), t_r = t->x.get(r);
      if(t_l <= x_l && t_r <= x_r) return t;
    } else {
      t = new Node(Line(0, id));
    }
    T m = (l + r) / 2;
    if(m == r) --m;
    T x_m = x.get(m);
    t->l = add_segment(t->l, x, a, b, l, m, x_l, x_m);
    t->r = add_segment(t->r, x, a, b, m + 1, r, x_m + x.a, x_r);
    return t;
  }

  void add_segment(const T &l, const T &r, const T &a, const T &b) {
    Line x(a, b);
    root = add_segment(root, x, l, r - 1, x_low, x_high, x.get(x_low), x.get(x_high));
  }

  T query(const Node *t, const T &l, const T &r, const T &x) const {
    if(!t) return id;
    if(l == r) return t->x.get(x);
    T m = (l + r) / 2;
    if(m == r) --m;
    if(x <= m) return min(t->x.get(x), query(t->l, l, m, x));
    else return min(t->x.get(x), query(t->r, m + 1, r, x));
  }

  T query(const T &x) const {
    return query(root, x_low, x_high, x);
  }
};
int N,M,Q;
const long long mod=1e9+7;
vector<pair<int,int> >G[2020];
long long d[2020],dt[2020];
int used[2020];
vector<pair<long long,long long> >f[2020];
main()
{
	scanf("%d%d%d",&N,&M,&Q);
	for(int i=0;i<M;i++)
	{
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		u--,v--;
		G[u].push_back(make_pair(v,w));
		G[v].push_back(make_pair(u,w));
	}
	for(int i=0;i<N;i++)d[i]=-1e18;
	d[0]=0;
	long long ans=0;
	const long long MAX=1e18;
	const long long LIM=10000;
	DynamicLiChaoTree<long long,-LIM-1,LIM+1,MAX>cht;
	vector<pair<long long,long long > >ls;
	for(int k=0;k<=LIM&&k<=Q;k++)
	{
		if(k<=M)
		{
			for(int i=0;i<N;i++)dt[i]=-1e18;
			for(int i=0;i<N;i++)if(d[i]>=0)
			{
				for(pair<int,int>e:G[i])
				{
					int v=e.first;
					if(dt[v]<d[i]+e.second)
					{
						dt[v]=d[i]+e.second;
					}
					long long E=e.second;
					pair<long long,long long>now=make_pair(E,d[i]-(long long)k*E);
					cht.add_line(-now.first,-now.second);
					ls.push_back(now);
				}
			}
			for(int i=0;i<N;i++)d[i]=dt[i];
		}
		ans-=cht.query(k);
		ans%=mod;
	}
	if(LIM<Q)
	{
		deque<pair<long long,long long> >P;
		sort(ls.begin(),ls.end());
		for(pair<long long,long long>e:ls)
		{
			while(P.size()>=2)
			{
				long long a1=P[P.size()-2].first,b1=P[P.size()-2].second;
				long long a2=P[P.size()-1].first,b2=P[P.size()-1].second;
				long long a3=e.first,b3=e.second;
				if((a2-a1)*(b3-b2)>=(a3-a2)*(b2-b1))P.pop_back();
				else break;
			}
			P.push_back(e);
		}
		long long t=LIM+1;
		while(P.size()>=2)
		{
			if(P[0].first*t+P[0].second<=P[1].first*t+P[1].second)P.pop_front();
			else break;
		}
		Q++;
		while(t<Q)
		{
			long long l=t-1,r=Q;
			while(P.size()>=2&&r-l>1)
			{
				long long mid=l+r>>1;
				if(P[0].first*mid+P[0].second<=P[1].first*mid+P[1].second)r=mid;
				else l=mid;
			}
			long long A=P[0].first,B=P[0].second;
			long long n=r-t;
			A%=mod;
			B+=A*t;
			B%=mod;
			ans+=B*n%mod;
			ans+=n*(n-1)/2%mod*A%mod;
			ans%=mod;
			t=r;
			P.pop_front();
		}
	}
	printf("%lld\n",(ans+mod)%mod);
}