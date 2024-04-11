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
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

const lf pi = 2.0*acos(0.0);

bool ok(lf a, lf b) {
    //cerr << fixed << setprecision(12) << a/b << ' ';
    return fabs(a/b-floor(a/b))<1e-5 || fabs(a/b-floor(a/b)-1)<1e-5;
}

int main() {
    //freopen("in.txt","r",stdin);  
    //freopen("out.txt","w",stdout);    

    lf x1, y1, x2, y2, x3, y3;
    scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
    
    lf a1 = x2-x1, b1 = y2-y1, c1 = -a1*(x1+x2)/2.0-b1*(y1+y2)/2.0;
    lf a2 = x3-x1, b2 = y3-y1, c2 = -a2*(x1+x3)/2.0-b2*(y1+y3)/2.0;
    
    lf x0 = -(c1*b2-c2*b1)/(a1*b2-a2*b1), y0 = -(a1*c2-a2*c1)/(a1*b2-a2*b1);
    
    //cerr << fixed << setprecision(5) << x0 << ' ' << y0 << '\n';

    lf r2 = sqr(x1-x0)+sqr(y1-y0);

    lf ang1 = acos( ((x1-x0)*(x2-x0)+(y1-y0)*(y2-y0))/r2 );
    lf ang2 = acos( ((x2-x0)*(x3-x0)+(y2-y0)*(y3-y0))/r2 );
    lf ang3 = acos( ((x3-x0)*(x1-x0)+(y3-y0)*(y1-y0))/r2 );

    //cerr << fixed << setprecision(5) << ang1*180/pi << ' ' << ang2*180/pi << ' ' << ang3*180/pi << '\n';
    
    lf ans = 1000000000000.0;
    
    FORD(i,3,100) {
        lf ang = 2*pi/lf(i);
        if (ok(ang1,ang) && ok(ang2,ang) && ok(ang3,ang) ) ans = min(ans,0.5*i*r2*sin(ang));    
    }

    printf("%.12lf",ans);
    
}