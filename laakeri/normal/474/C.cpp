#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define PI 3.14159265358979323
#define err 0.00001
#define F first
#define S second

using namespace std;

struct p{
    double x, y;
};

double d (p a, p b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int issq(vector<p>&ps){
    vector<double> ds;
    for (int i=0;i<ps.size();i++){
        for (int ii=0;ii<ps.size();ii++){
            if (i!=ii){
                ds.push_back(d(ps[i], ps[ii]));
            }
        }
    }
    sort(ds.begin(), ds.end());
    if (ds[0]<err) return 0;
    for (int i=1;i<8;i++){
        if (abs(ds[i]-ds[0])>err){
            return 0;
        }
    }
    if (abs(ds[8]-sqrt(ds[0]*ds[0]+ds[0]*ds[0]))>err){
        return 0;
    }
    for (int i=9;i<12;i++){
        if (abs(ds[i]-ds[8])>err){
            return 0;
        }
    }
    return 1;
}

p rot(p a, p b, int ang){
    double an=atan2(a.y-b.y, a.x-b.x)+(double)ang*PI/2.0;
    double di=d(a, b);
    an+=PI*2.0;
    a.x=b.x+cos(an)*di;
    a.y=b.y+sin(an)*di;
    return a;
}

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        vector<pair<p, p> > ps;
        for (int ii=0;ii<4;ii++){
            p po, h;
            cin>>po.x>>po.y>>h.x>>h.y;
            ps.push_back(make_pair(po, h));
        }
        int m=99999;
        for (int a=0;a<4;a++){
            for (int aa=0;aa<4;aa++){
                for (int aaa=0;aaa<4;aaa++){
                    for (int aaaa=0;aaaa<4;aaaa++){
                        vector<p> lol(4);
                        lol[0]=rot(ps[0].F, ps[0].S, a);
                        lol[1]=rot(ps[1].F, ps[1].S, aa);
                        lol[2]=rot(ps[2].F, ps[2].S, aaa);
                        lol[3]=rot(ps[3].F, ps[3].S, aaaa);
                        if (issq(lol)){
                            m=min(m, a+aa+aaa+aaaa);
                        }
                    }
                }
            }
        }
        if (m==99999) cout<<-1<<endl;
        else cout<<m<<endl;
    }
}