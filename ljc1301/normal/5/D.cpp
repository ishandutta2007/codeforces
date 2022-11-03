#include <cstdio>
#include <cmath>
double a,v,l,d,w,ans;
inline double l_v(double l) { return sqrt(2*a*l); }
inline double l_t(double l) { return sqrt(2*l/a); }
inline double t_l(double t) { return .5*a*t*t; }
inline double v_l(double v) { return .5*v*v/a; }
int main()
{
    scanf("%lf%lf%lf%lf%lf",&a,&v,&l,&d,&w);
    if(w>=v) w=v;
    if(l_v(d)<=w)
        if(l_v(l)<=v)
            ans=l_t(l);
        else
            ans=v/a+(l-t_l(v/a))/v;
    else
    {
        if(2*v_l(v)-v_l(w)<=d)
            ans=(2*v-w)/a+(d-(2*v_l(v)-v_l(w)))/v;
        else
            ans=sqrt((d+v_l(w))/a)*2-w/a;
        if(v_l(v)-v_l(w)>=l-d)
            ans+=(-w+sqrt(w*w-2*a*(d-l)))/a;
        else
            ans+=(v-w)/a+(l-d-(v_l(v)-v_l(w)))/v;
    }
    printf("%.12lf\n",ans);
    return 0;
}