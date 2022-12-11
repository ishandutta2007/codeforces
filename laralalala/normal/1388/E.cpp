#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(998244353)
#define eps (1e-9)
//#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(4e5+5)

ld cross(point a, point b) { return imag(conj(a) * b); } ///a_x*b_y-b_x*a_y

ld dot(point a, point b) { return real(conj(a) * b); } /// a_x*b_x+a_y*b_y

ld area2(point a, point b, point c) { return cross(b - a, c - a); }

namespace std
{
	bool operator<(const point &a, const point &b)
	{
		return real(a) < real(b) || (real(a) == real(b) && imag(a) < imag(b));
	}
}

const ld oo = 0x3f3f3f3f3f3f3f3f;

struct dynamic_hull
{
	dynamic_hull() : hulls() {}

	void add_point(point p)
	{
		hull h;
		h.add_point(p);

		for (hull &_h : hulls)
			if (_h.empty())
			{
				h.swap(_h);
				break;
			}
			else h = merge(h, _h), _h.clear();

		if (!h.empty()) hulls.emplace_back(h);
	}

	ld max_dot(point p)
	{
		ld best = -oo;

		for (hull &h : hulls)
			if (!h.empty()) best = max(best, h.max_dot(p));

		return best;
	}

    void mergeall()
    {
        vector<hull> hs;
        hs.push_back(hulls[0]);
        for(int i=1;i<hulls.size();i++)
            hs[0]=merge(hulls[i],hs[0]);
        hulls=hs;
    }

private:
	struct hull : vector<point>
	{
		void add_point(point p)
		{
			for (int s = size(); s > 1; --s)
				if (area2(at(s - 2), at(s - 1), p) < 0) break;
				else pop_back();
			push_back(p);
		}

		ld max_dot(point p)
		{
			int lo = 0, hi = (int) size() - 1, mid;

			while (lo < hi)
			{
				mid = (lo + hi) / 2;

				if (dot(at(mid), p) <= dot(at(mid + 1), p))
					lo = mid + 1;
				else hi = mid;
			}

			return dot(at(lo), p);
		}
	};

	static hull merge(const hull &a, const hull &b)
	{
		hull h;
		size_t i = 0, j = 0;

		while (i < a.size() && j < b.size())
			if (a[i] < b[j]) h.add_point(a[i++]);
			else h.add_point(b[j++]);

		while (i < a.size()) h.add_point(a[i++]);

		while (j < b.size()) h.add_point(b[j++]);

		return h;
	}

	vector<hull> hulls;
};

ld xs[MAXN][2];
ld ys[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    dynamic_hull dpr;
    dynamic_hull dpl;
    ld mi=oo;
    ld ma=-oo;
    for(int i=0;i<n;i++)
    {
        cin >> xs[i][0] >> xs[i][1] >> ys[i];
        mi=min(mi,xs[i][0]);
        ma=max(ma,xs[i][1]);
        dpr.add_point(point(ys[i],xs[i][1]));
        dpl.add_point(point(-ys[i],-xs[i][0]));
    }
    dpr.mergeall();
    dpl.mergeall();
    vector<pdi> as;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(ys[i]<=ys[j])
                continue;
            ll d=ys[i]-ys[j];
            ll x1=xs[i][1]-xs[j][0];
            ll x2=xs[i][0]-xs[j][1];
            ll g1=__gcd(d,abs(x1));
            ll g2=__gcd(d,abs(x2));
            ld a1=(ld)(x1/g1)/(ld)(d/g1);
            ld a2=(ld)(x2/g2)/(ld)(d/g2);
//            cout << i << ' ' << j << '\n';
//            cout << a1 << ' ' << a2 << '\n';
//            cout << '\n';
            as.push_back(pdi(-a1,1));
            as.push_back(pdi(-a2,-1));
        }
    }

    sort(all(as));
    ld res=oo;
    if(as.empty())
        res=ma-mi;
    int sum=0;
    for(int i=0;i<as.size();i++)
    {
        ld v=as[i].f;
        int ty=as[i].s;
        if(ty==1)
        {
            if(!sum)
            {
//                db("")
//                db(v)
//                db(dpr.max_dot(point(v,1))+dpl.max_dot(point(v,1)))
                res=min(res,dpr.max_dot(point(v,1))+dpl.max_dot(point(v,1)));
            }
            sum++;
        }
        else
        {
            sum--;
            if(!sum)
            {
//                db("")
//                db(v)
//                db(dpr.max_dot(point(v,1))+dpl.max_dot(point(v,1)))
                res=min(res,dpr.max_dot(point(v,1))+dpl.max_dot(point(v,1)));
            }
        }
    }

    cout.precision(10);
    cout<<fixed;
    db(res)

    return 0;
}
/**
3
1 6 2
4 6 4
4 6 6
2
1 3 1
4 7 1
**/