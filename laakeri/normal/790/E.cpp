#include <bits/stdc++.h>
#define X real()
#define Y imag()
using namespace std;
typedef double ld;
typedef complex<ld> co;
const ld eps=1e-9;
const ld maxD=1e6;
ld ccw(co a, co b) {
	return (b*conj(a)).Y;
}
int ar(co x) {
	if (x.Y>=0&&x.X<0) return 1;
	if (x.X>=0&&x.Y>0) return 2;
	if (x.Y<=0&&x.X>0) return 3;
	return 4;
}
bool cp(co p1, co p2) {
	if (ar(p1)!=ar(p2)) return ar(p1)>ar(p2);
	return ccw(p2, p1)<0;
}
struct hp_t {
	co a, b;
	hp_t(co p1, co p2) {
		a=p1;
		b=(p2-p1)/abs(p2-p1);
	}
	ld d(co p) const {
		return ccw(b, p-a);
	}
	bool operator==(const hp_t& o) const {
		return abs(b.X-o.b.X)<eps&&abs(b.Y-o.b.Y)<eps;
	}
	bool operator<(const hp_t& o) const {
		if ((*this)==o){
			return d(o.a)<-eps;
		}
		return cp(b, o.b);
	}
};
co getI(hp_t a, hp_t b) {
	ld c=ccw(a.b, b.b);
	assert(!(abs(c)<eps));
	return ccw(b.a, b.b)*a.b/c+ccw(a.b, a.a)*b.b/c;
}
vector<co> getHPI(vector<hp_t> hp) {
	hp.push_back({{-maxD, -maxD}, {maxD, -maxD}});
	hp.push_back({{maxD, -maxD}, {maxD, maxD}});
	hp.push_back({{maxD, maxD}, {-maxD, maxD}});
	hp.push_back({{-maxD, maxD}, {-maxD, -maxD}});
	sort(hp.begin(), hp.end());
	hp.erase(unique(hp.begin(), hp.end()), hp.end());
	int del=0;
	vector<co> p;
	for (int i=1;i<(int)hp.size();i++){
		while ((int)p.size()>del&&hp[i].d(p.back())<eps) p.pop_back();
		while ((int)p.size()>del&&hp[i].d(p[del])<eps) del++;
		if (del==(int)p.size()&&ccw(hp[p.size()].b, hp[i].b)<eps) return {};
		co np=getI(hp[i], hp[p.size()]);
		if (hp[del].d(np)>-eps){
			p.push_back(np);
			hp[p.size()]=hp[i];
		}
	}
	rotate(p.begin(), p.begin()+del, p.end());
	rotate(hp.begin(), hp.begin()+del, hp.begin()+p.size()+1);
	p.resize((int)p.size()-del);
	if (p.empty()) return p;
	p.push_back(getI(hp[0], hp[p.size()]));
	return p;
}
bool cp2(co p1, co p2) {
	if (ar(p1)!=ar(p2)) return ar(p1)<ar(p2);
	return ccw(p2, p1)>0;
}

void solve(){
	int n;
	scanf("%d", &n);
	vector<co> ps;
	int xx,yy;
	scanf("%d %d", &xx, &yy);
	co x={(ld)xx, (ld)yy};
	for (int i=1;i<n;i++){
		scanf("%d %d", &xx, &yy);
		ps.push_back({(ld)xx, (ld)yy});
		ps.back()-=x;
	}
	sort(ps.begin(), ps.end(), cp2);
	vector<hp_t> hps;
	for (int i=0;i<(int)ps.size();i++){
		co t=ps[i];
		co nt=ps[(i+1)%(int)ps.size()];
		if (abs(ccw(t, nt))<eps){
			printf("0\n");
			return;
		}
		if (ccw(t, nt)>0){
			hps.push_back({t+x, nt+x});
		}
		else{
			hps.push_back({nt+x, t+x});
		}
	}
	int i2=0;
	for (int i=0;i<(int)ps.size();i++){
		int ct=0;
		while (i2==i||(ccw(ps[i], ps[i2])<eps)){
			if (i2!=i){
				if (abs(ccw(ps[i], ps[i2]))<eps){
					printf("0\n");
					return;
				}
			}
			i2++;
			i2=i2%(int)ps.size();
			ct++;
			if (ct>2*n){
				break;
			}
		}
		if (ct>2*n){
			i2=(i+2)%(int)ps.size();
			continue;
		}
		hps.push_back({ps[i]+x, ps[i2]+x});
		int e=(i2+(int)ps.size()-1)%(int)ps.size();
		if (e!=i){
			hps.push_back({ps[e]+x, ps[i]+x});
		}
	}
	auto it=getHPI(hps);
	ld A=0;
	for (int i=0;i<(int)it.size();i++){
		co t=it[i];
		co ne=it[(i+1)%(int)it.size()];
		A+=(t*conj(ne)).Y;
	}
	printf("%.18f\n", (double)(abs(A)/(ld)2));
}

int main(){
	int tcs;
	scanf("%d", &tcs);
	for (int tc=0;tc<tcs;tc++){
		solve();
	}
}