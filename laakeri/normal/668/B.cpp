#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int v[10101010];

int main(){
	int n,q;
	scanf("%d %d", &n, &q);
	ll pm=0;
	int dir=0;
	int rot=0;
	vector<pair<int, int> > inp;
	for (int qq=0;qq<q;qq++){
		int t;
		scanf("%d", &t);
		if (t==1){
			int rr;
			scanf("%d", &rr);
			pm+=rr;
			pm+=n;
			pm%=n;
			if ((rr+n)%2==0){
			}
			else{
				if ((int)inp.size()>0&&inp.back().F==1) inp.pop_back();
				else inp.push_back({1, rr});
			}
		}
		else{
			if ((int)inp.size()>0&&inp.back().F==2) inp.pop_back();
			else inp.push_back({2, 0});
		}
	}
	if ((int)inp.size()>0&&inp[0].F==1) dir=1;
	rot=0;
	for (int i=0;i<(int)inp.size();i++){
		if (inp[i].F==2) rot++;
	}
	rot%=n;
	for (int i=0;i<n;i++){
		int t=i+n+n+pm;
		if ((i+dir)%2==0){
			t+=rot;
		}
		else{
			t-=rot;
			t+=n;
		}
		t%=n;
		v[t]=i+1;
	}
	for (int i=0;i<n;i++){
		printf("%d ", v[i]);
	}
}