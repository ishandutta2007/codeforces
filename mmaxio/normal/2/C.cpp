#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(v) (int(v.size()))
#define pch putchar
#define gch getchar()
#define FORD(i,a,b) for (int i=(a); i<=(b); i++)
#define FORP(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,n) for (int i=0; i<(n); i++)
#define clean(v) memset(v,0,sizeof(v))

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

const lf eps = 1e-7;

bool eq(lf a, lf b) {
    return fabs(a-b)<eps;
}

struct pnt {
    lf x, y;
    pnt(lf _x = 0, lf _y = 0) {
        x = _x, y = _y;
    }
    pnt(pnt a, pnt b) {
        *this = pnt(b.x - a.x, b.y - a.y);
    }
    
    lf len() {
        return sqrt(sqr(x)+sqr(y));
    }
    
    void norm(lf new_len) {
        lf p = len();
        *this = pnt(x/p*new_len,y/p*new_len);
    }
    
    void rotate(lf _sin, lf _cos) {
        *this = pnt(x*_cos-y*_sin,x*_sin+y*_cos);
    }
    
    pnt operator+(pnt p) {
        return pnt(x+p.x,y+p.y);
    }
    
    pnt operator-(pnt p) {
        return pnt(p,*this);
    }
                                                   
    bool operator==(pnt p) {
        return eq(p.x,x) && eq(p.y,y);
    }
    
    void read() {
        scanf("%lf%lf",&x,&y);
    }
    
    void write() {
        printf("%.12lf %.12lf\n",x,y);
    }
    
};

struct lne {
    lf a, b, c;
    lne (lf _a = 0, lf _b = 0, lf _c = 0) {
        a = _a, b = _b, c = _c;
    }
    lne (pnt p1, pnt p2) {
        *this = lne(p2.y-p1.y,p1.x-p2.x);
        c = -a*p1.x-b*p1.y;
    }
    void read() {
        scanf("%lf%lf%lf",&a,&b,&c);
    }

};

struct crc {
    pnt c; lf r;
    crc(pnt _c = pnt(0,0), lf _r = 0) {
        c = _c, r = _r;
    }

    void read() {
        c.read();
        scanf("%lf",&r);
    }

};

lf PntLineDist(pnt p, lne l) {
    return (l.a*p.x+l.b*p.y+l.c)/sqrt(sqr(l.a)+sqr(l.b));
};

pnt LineLineInter(lne &r1, lne &r2, int &res) {//res: -1 = coincide, 0 = don't intersect, 1 = one point in intersection
    lf d = r1.a*r2.b-r2.a*r1.b, x1 = r2.c*r1.b-r1.c*r2.b, y1 = r2.a*r1.c-r2.c*r1.a;
    if (eq(d,0)) {
        res = eq(x1,0)?-1:0;
    } else return res = 1, pnt(x1/d,y1/d);
}

vector<pnt> LineCrcInter(lne l, crc s) {//return vector of points in intersection
    
    vector<pnt> res;
    pnt v(l.a,l.b);
    lf d = PntLineDist(s.c,l);
    v.norm(-d);
    pnt p1 = s.c+v;
    if (eq(fabs(d),s.r)) {
        res.pb(p1);
        return res;
    } else if (fabs(d)>s.r) return res;
    else {
        pnt v1(-l.b,l.a);
        lf d1 = sqrt(sqr(s.r)-sqr(d));
        v1.norm(d1);
        res.pb(p1+v1); res.pb(p1-v1); return res;
    }
}

vector<pnt> CrcCrcInter(crc s1, crc s2) {//return vector of points in intersection; circles coincide => size of returned vector is 3
    vector<pnt> res;
    if (s1.c==s2.c) {
        if (eq(s1.r,s2.r)) res.resize(3);
        return res;
    } else {
        return LineCrcInter(lne(2*(s1.c.x-s2.c.x),2*(s1.c.y-s2.c.y),sqr(s2.c.x)+sqr(s2.c.y)+sqr(s1.r)-sqr(s2.r)-sqr(s1.c.x)-sqr(s1.c.y)),s1);
    }
}


int main() {
    /*freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);*/
    crc s1, s2, s3;
    s1.read(); s2.read(); s3.read();
    bool crc1, crc2;
    lne l1, l2; crc c1, c2;
    if (s1.r==s2.r) {
        l1 = lne(s2.c.x-s1.c.x,s2.c.y-s1.c.y); l1.c = -l1.a*(s1.c.x+s2.c.x)/2.0-l1.b*(s1.c.y+s2.c.y)/2.0; crc1 = 0;
    } else {
        lf d = (s2.c-s1.c).len();
        pnt v(s1.c,s2.c);
        v.norm(s1.r*d/(s1.r+s2.r));
        pnt p1 = s1.c+v;
        v = pnt(s1.c,s2.c);
        v.norm(s1.r*d/(s1.r-s2.r));
        pnt p2 = s1.c+v;
        c1 = crc(pnt((p1.x+p2.x)/2.0,(p1.y+p2.y)/2.0),(p2-p1).len()/2.0);
        crc1 = 1;
    }

    if (s1.r==s3.r) {
        l2 = lne(s3.c.x-s1.c.x,s3.c.y-s1.c.y); l2.c = -l2.a*(s1.c.x+s3.c.x)/2.0-l2.b*(s1.c.y+s3.c.y)/2.0; crc2 = 0;
    } else {
        lf d = (s3.c-s1.c).len();
        pnt v(s1.c,s3.c);
        v.norm(s1.r*d/(s1.r+s3.r));
        pnt p1 = s1.c+v;
        v = pnt(s1.c,s3.c);
        v.norm(s1.r*d/(s1.r-s3.r));
        pnt p2 = s1.c+v;
        c2 = crc(pnt((p1.x+p2.x)/2.0,(p1.y+p2.y)/2.0),(p2-p1).len()/2.0);
        crc2 = 1;
    }

    vector<pnt> check;

    //cerr << l1.a << ' ' << l1.b << ' ' << l1.c;

    int res = 1;
    if (!crc1 && !crc2) check.pb(LineLineInter(l1,l2, res));
    if (!crc1 && crc2) check = LineCrcInter(l1,c2);
    if (crc1 && !crc2) check = LineCrcInter(l2,c1);
    if (crc1 && crc2) check = CrcCrcInter(c1,c2);

    if (res != 1) while(1);
    if (sz(check)==3) while (1);

    lf best_d1 = 1000000000.0; pnt ans;

    REP(i,sz(check)) {
        lf d1 = pnt(check[i],s1.c).len();
        lf d2 = pnt(check[i],s2.c).len();
        lf d3 = pnt(check[i],s3.c).len();
        if (eq(d1/d3,s1.r/s3.r) && eq(d2/d3,s2.r/s3.r) && eq(d1/d2,s1.r/s2.r)) {
            if (d1<best_d1) best_d1 = d1, ans = check[i];
        }
    }

    if (best_d1!=1000000000.0) printf("%.5lf %.5lf",ans.x,ans.y);


/* crc s1, s2;
 s1.read(); s2.read();
 vector<pnt> res = CrcCrcInter(s1,s2);
 printf("%d\n",sz(res));
 if (sz(res) != 3) REP(i,sz(res)) res[i].write();*/
}