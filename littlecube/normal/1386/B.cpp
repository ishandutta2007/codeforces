#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define ll long long
using namespace std;

struct fraction
{
    // denotes p / q
    ll p, q;
    fraction() : p(0), q(1){};
    fraction(ll p, ll q)
    {
        this->p = p;
        this->q = q;
        ll gcd = __gcd(p, q);
        //assert(gcd > 0);
        this->p /= gcd;
        this->q /= gcd;
        if (this->q < 0)
            this->p *= -1, this->q *= -1;
    };

    fraction operator-(fraction f)
    {
        ll newp = p * f.q - q * f.p, newq = q * f.q;
        ll gcd = __gcd(newp, newq);
        newp /= gcd, newq /= gcd;
        if (newq < 0)
            newp *= -1, newq *= -1;
        assert(newq > 0);
        return fraction(newp, newq);
    }

    bool equalZero()
    {
        if (p == 0)
            return 1;
        return 0;
    }

    fraction negative()
    {
        return fraction(p * -1, q);
    }

    long double toDouble()
    {
        return (long double)(p) / (long double)(q);
    }

    int sign()
    {
        if (p == 0)
            return 0;
        else if ((p > 0 && q > 0) || (p < 0 && q < 0))
            return 1;
        return -1;
    }
};

struct point
{
    fraction x, y;
    point() : x(fraction()), y(fraction()){};
    point(fraction x, fraction y) : x(x), y(y){};
    point(ll S, ll P, ll G) : x(fraction(S, S + P + G)), y(fraction(P, S + P + G)){};

    void simplify()
    {
        if (x.p != 0 && y.p != 0)
        {
            ll pgcd = __gcd(x.p, y.p);
            x.p /= abs(pgcd);
            y.p /= abs(pgcd);
        }
        if (x.q != 0 && y.q != 0)
        {
            ll qgcd = __gcd(x.q, y.q);
            x.q /= abs(qgcd);
            y.q /= abs(qgcd);
            assert(x.q != 0);
            assert(y.q != 0);
        }
    }

    point operator-(point p)
    {
        return point(x - p.x, y - p.y);
    }

    point negative()
    {
        return point(x.negative(), y.negative());
    }
};

int quadurant(point p)
{
    if (p.x.sign() >= 0 && p.y.sign() >= 0)
        return 1;
    if (p.x.sign() <= 0 && p.y.sign() >= 0)
        return 2;
    if (p.x.sign() <= 0 && p.y.sign() <= 0)
        return 3;
    return 4;
}

struct compare_by_tan
{
    bool operator()(point p1, point p2) const
    {
        if (quadurant(p1) != quadurant(p2))
            return quadurant(p1) < quadurant(p2);
        return p1.y.toDouble() * p2.x.toDouble() < p2.y.toDouble() * p1.x.toDouble();
    }
};

long double angle(point p)
{
    int quad = quadurant(p);
    if (quad == 1)
        return atan2l(p.y.toDouble(), p.x.toDouble());
    if (quad == 2)
        return acosl(-1) - atan2l(p.y.toDouble(), -p.x.toDouble());
    if (quad == 3)
        return acosl(-1) + atan2l(-p.y.toDouble(), -p.x.toDouble());
    return acosl(-1) * 2.0 - atan2l(-p.y.toDouble(), p.x.toDouble());
}

long double absAngleDifference(point p1, point p2)
{
    long double diff = angle(p1) - angle(p2);
    if (diff < 0.0)
        diff += acosl(-1) * 2.0;
    return diff;
}

map<point, int, compare_by_tan> mp;
ll N, S, P, G, id, cnt1, cnt2, backidx;
bool cnt3;
const long double eps = 1e-8;
char type;
point perfect, bottle[200005];

signed main()
{

    // ios::sync_with_stdio(0), cin.tie(0);

    cin >> S >> P >> G;
    perfect = point(S, P, G);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> type;
        if (type == 'A')
        {
            cin >> S >> P >> G;
            bottle[++backidx] = point(S, P, G);
            bottle[backidx] = bottle[backidx] - perfect;
            bottle[backidx].simplify();

            if (bottle[backidx].x.equalZero() && bottle[backidx].y.equalZero())
                cnt1++;
            else
            {
                mp[bottle[backidx]]++;
                if (mp.find(bottle[backidx].negative()) != mp.end())
                {
                    cnt2 += mp[bottle[backidx].negative()];
                }

                if (mp[bottle[backidx]] == 1)
                {
                    auto iter = mp.find(bottle[backidx]);
                    auto nxt = iter, pre = iter;
                    if (next(nxt) == mp.end())
                        nxt = mp.begin();
                    else
                        nxt = next(nxt);

                    if (pre == mp.begin())
                        pre = prev(mp.end());
                    else
                        pre = prev(pre);

                    if (absAngleDifference(nxt->first, pre->first) > acos(-1) - eps &&
                        absAngleDifference(nxt->first, iter->first) <= acos(-1) + eps &&
                        absAngleDifference(iter->first, pre->first) <= acos(-1) + eps)
                        cnt3 = true;
                }
            }
        }
        else
        {
            cin >> id;

            if (bottle[id].x.equalZero() && bottle[id].y.equalZero())
                cnt1--;
            else
            {
                if (mp.find(bottle[id].negative()) != mp.end())
                    cnt2 -= mp[bottle[id].negative()];

                if (mp[bottle[id]] == 1)
                {
                    auto iter = mp.find(bottle[id]);
                    auto nxt = iter, pre = iter;
                    if (next(nxt) == mp.end())
                        nxt = mp.begin();
                    else
                        nxt = next(nxt);

                    if (pre == mp.begin())
                        pre = prev(mp.end());
                    else
                        pre = prev(pre);

                    if (absAngleDifference(nxt->first, pre->first) > acos(-1) - eps &&
                        absAngleDifference(nxt->first, iter->first) <= acos(-1) + eps &&
                        absAngleDifference(iter->first, pre->first) <= acos(-1) + eps)
                        cnt3 = false;

                    mp.erase(iter);
                }
                else
                {
                    mp[bottle[id]]--;
                }
            }
        }

        if (cnt1 > 0)
        {
            cout << 1 << '\n';
        }
        else if (cnt2 > 0)
        {
            cout << 2 << '\n';
        }
        else if (cnt3)
        {
            cout << 3 << '\n';
        }
        else
            cout << 0 << '\n';
    }
}