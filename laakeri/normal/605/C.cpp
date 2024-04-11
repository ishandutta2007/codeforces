#include <bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define P pair<ll,ll>
#define Pd pair<ld,ld>

#define ld long double

using namespace std;

int n;
P p[101010];
P s,t;

ll lef(P a, P b, P c) {
	return (b.F-a.F)*(c.S-a.S)-(c.F-a.F)*(b.S-a.S);
}

ld dist(Pd a, Pd b) {
	return sqrt((a.F-b.F)*(a.F-b.F)+(a.S-b.S)*(a.S-b.S));
}

ld sect(P a, P b) {
	ld ala=0;
	ld yla=1e18;
	for (int i=0;i<500;i++) {
		ld mid1=(2*ala+yla)/3;
		ld mid2=(ala+2*yla)/3;
		if (dist(a,{mid1*t.F,mid1*t.S})+dist(b,{mid1*t.F,mid1*t.S})
			<dist(a,{mid2*t.F,mid2*t.S})+dist(b,{mid2*t.F,mid2*t.S})) {
			yla=mid2;
		} else ala=mid1;
	}
	return ala;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	ll pe,q;
	cin>>pe>>q;
	t={pe,q};
	s={0,0};
	vector<pair<ll, ll> > pp;
	for (int i=0;i<n;i++) {
		ll a,b;
		cin>>a>>b;
		pp.push_back({a, b});
		//p[i]={a,b};
	}
	sort(pp.rbegin(), pp.rend());
    ll my=-1;
    int i2=0;
    for (int i=0;i<(int)pp.size();i++){
        if (pp[i].S>my){
            p[i2++]=pp[i];
            my=pp[i].S;
        }
    }
    n=i2;
	sort(p,p+n);
	vector<P> conv;
	for (int i=0;i<n;i++) {
		int c=conv.size();
		while (c>=2 && lef(conv[c-2],conv[c-1],p[i])>0) {
			conv.pop_back();
			c--;
		}
		conv.push_back(p[i]);
	}
	ld parsa=1e18;
	parsa=min(parsa,max((((ld)pe)/conv[0].F),(((ld)q)/conv[0].S)));
	parsa=min(parsa,max((((ld)q)/conv[conv.size()-1].S),
			(((ld)pe)/conv[conv.size()-1].F)));
	for (unsigned int i=0;i<conv.size()-1;i++) {
		parsa=min(parsa,max((((ld)pe)/conv[i].F),(((ld)q)/conv[i].S)));
		if (lef(s,t,conv[i])>=0 && lef(s,t,conv[i+1])<=0) {
			parsa=min(parsa,1/sect(conv[i],conv[i+1]));
//			cout<<"AAAAAA"<<endl;
		}
	}
	cout<<setprecision(15)<<parsa<<"\n";
}