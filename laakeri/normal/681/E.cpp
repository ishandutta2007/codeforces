#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> co;
const ld eps=1e-8;
const ld PI=atan2(0, -1);

ld sq(ld x){
	return x*x;
}

pair<ld, ld> ks(ld d, ld r){
	ld k=sqrt(max((ld)0, -(sq(r)/(sq(r)-sq(d)))));
	//cout<<k<<endl;
	ld x=(d-sqrt(max((ld)0, -sq(d)*sq(k)+sq(k)*r+r)))/(sq(k)+1);
	return {atan(k), sqrt(sq(x)+sq(k*x))};
}

pair<int, pair<co, co> > circleIntersection(co p1, ld r1, co p2, ld r2){
	if (norm(p1-p2)>(r1+r2)*(r1+r2)||norm(p1-p2)<(r1-r2)*(r1-r2)) return {0, {{0, 0}, {0, 0}}};
	if (abs(p1-p2)<eps&&abs(r1-r2)<eps) return {3, {{p1.X, p1.Y+r1}, {p1.X+r1, p1.Y}}};
	ld a=abs(p1-p2);
	ld x=(r1*r1-r2*r2+a*a)/(2*a);
	co v1={x, sqrt(r1*r1-x*x)};
	co v2={x, -sqrt(r1*r1-x*x)};
	v1=v1*(p2-p1)/a+p1;
	v2=v2*(p2-p1)/a+p1;
	if (abs(v1-v2)<eps) return {1, {v1, v1}};
	return {2, {v1, v2}};
}

void nm(ld& x){
	while (x<-PI) x+=2*PI;
	while (x>PI) x-=2*PI;
}

ld x[101010];
ld y[101010];
ld r[101010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll x0,y0,v,t;
	cin>>x0>>y0>>v>>t;
	t*=v;
	int n;
	cin>>n;
	vector<pair<ld, int> > vv;
	for (int i=0;i<n;i++){
		ll xx,yy,rr;
		cin>>xx>>yy>>rr;
		xx-=x0;
		yy-=y0;
		x[i]=xx;
		y[i]=yy;
		r[i]=rr;
		if (sq(xx)+sq(yy)<=sq(rr)){
			cout<<1<<endl;
			return 0;
		}
		auto lol=ks(sqrt(sq(x[i])+sq(y[i])), r[i]);
		int f=0;
		ld from=0;
		ld to=0;
		//cout<<lol.F*180/PI<<" "<<lol.S<<endl;
		if (lol.S>t){
			//cout<<"joo"<<endl;
			auto asd=circleIntersection({0, 0}, t, {x[i], y[i]}, r[i]);
			if (asd.F==2){
				f=1;
				from=atan2(asd.S.F.Y, asd.S.F.X);
				to=atan2(asd.S.S.Y, asd.S.S.X);
			}
		}
		else {
			f=1;
			from=atan2(y[i], x[i])-lol.F;
			to=atan2(y[i], x[i])+lol.F;
			//cout<<from<<" "<<to<<endl;
		}
		if (f){
			nm(from);
			nm(to);
			if (from>to) swap(from, to);
			if (atan2(y[i], x[i])>from-eps&&atan2(y[i], x[i])<to+eps){
				
			}
			else{
				from+=2*PI;
				swap(from, to);
			}
			//assert(from<to);
			//assert(to-from<PI+eps);
			//cout<<from<<" "<<to<<endl;
			vv.push_back({from, 1});
			vv.push_back({to, -1});
			vv.push_back({from+2*PI, 1});
			vv.push_back({to+2*PI, -1});
			vv.push_back({from-2*PI, 1});
			vv.push_back({to-2*PI, -1});
			vv.push_back({from+3*PI, 1});
			vv.push_back({to+3*PI, -1});
			vv.push_back({from-3*PI, 1});
			vv.push_back({to-3*PI, -1});
		}
	}
	vv.push_back({0, 2});
	vv.push_back({2*PI, 3});
	sort(vv.begin(), vv.end());
	int ac=0;
	int s=0;
	ld ans=0;
	ld ed=-1e9;
	for (auto tt:vv){
		//cout<<tt.F<<" "<<tt.S<<endl;
		if (ac==1&&s>0){
			ans+=tt.F-ed;
		}
		ed=tt.F;
		if (tt.S==2){
			ac=1;
		}
		else if(tt.S==3){
			ac=0;
		}
		else {
			s+=tt.S;
		}
	}
	cout<<setprecision(15)<<ans/(2*PI)<<endl;
}