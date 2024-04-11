#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> co;
const ld PI=atan2(0, -1);

int ar(co x){
	if (x.Y>=0&&x.X<0){
		return 1;
	}
	if (x.X>=0&&x.Y>0){
		return 2;
	}
	if (x.Y<=0&&x.X>0){
		return 3;
	}
	if (x.X<=0&&x.Y<0){
		return 4;
	}
	assert(1==0);
}

ll ccw2(co c1, co c2){
	return (c1*conj(c2)).Y;
}

int cp(pair<co, int> c1, pair<co, int> c2){
	if (ar(c1.F)!=ar(c2.F)){
		return ar(c1.F)<ar(c2.F);
	}
	return ccw2(c1.F, c2.F)>0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<co, int> > ps;
    for (int i=0;i<n;i++){
        ld x,y;
        cin>>x>>y;
        ps.push_back({co(x, y), i+1});
    }
    sort(ps.begin(), ps.end(), cp);
    pair<ld, pair<int, int> > v={1e9, {1, 2}};
    for (int i=0;i<n;i++){
        ld k1=atan2(ps[i].F.Y, ps[i].F.X);
        ld k2=atan2(ps[(i+1)%n].F.Y, ps[(i+1)%n].F.X);
        ld e=min(abs(k1-k2), abs(k1+PI*2-k2));
        e=min(e, abs(k2+PI*2-k1));
        v=min(v, {e, {ps[i].S, ps[(i+1)%n].S}});
    }
    cout<<v.S.F<<" "<<v.S.S<<endl;
}