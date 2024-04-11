#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

pair<ll, ll> p[3];

int v=6;

void go(int hp, pair<ll, ll> c, int s){
	if (s>=v) return;
	if (hp==7){
		v=min(v, s);
		return;
	}
	for (int i=0;i<3;i++){
		ll nx=p[i].F;
		if (nx!=c.F){
			int np=hp;
			for (int j=0;j<3;j++){
				if (p[j].S==c.S&&min(nx, c.F)<=p[j].F&&max(nx, c.F)>=p[j].F){
					np|=(1<<j);
				}
			}
			go(np, {nx, c.S}, s+1);
		}
	}
	for (int i=0;i<3;i++){
		ll ny=p[i].S;
		if (ny!=c.S){
			int np=hp;
			for (int j=0;j<3;j++){
				if (p[j].F==c.F&&min(ny, c.S)<=p[j].S&&max(ny, c.S)>=p[j].S){
					np|=(1<<j);
				}
			}
			go(np, {c.F, ny}, s+1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i=0;i<3;i++){
		cin>>p[i].F>>p[i].S;
	}
	go(1, p[0], 0);
	go(2, p[1], 0);
	go(4, p[2], 0);
	cout<<v<<endl;
}