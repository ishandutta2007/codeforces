#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define MAXF 4096
LL BIT2[MAXF][MAXF];
void upd2(LL x, LL y, LL v){
	LL c = x;
	while(c < MAXF){
		LL d = y;
		while(d	< MAXF){
			BIT2[c][d] += v;
			d += d & -d;
		}
		c += c & -c;
	}	
}

LL q2(LL x, LL y){
	LL c = x;
	LL a = 0;
	while(c > 0){
		LL d = y;
		while(d	> 0){
			a += BIT2[c][d];
			d -= d & -d;
		}
		c -= c & -c;
	}
	return a;
}

void updrect(LL r1, LL c1, LL r2, LL c2, LL v){
	upd2(r1, c1, v);
	upd2(r1, c2+1, -v);
	upd2(r2+1, c1, -v);
	upd2(r2+1, c2+1, v);
}
int main(){
	srand(time(0));
	LL n, m, q;
	cin >> n >> m >> q;
	map<pair<pair<LL,LL>, pair<LL,LL> >, LL> nums;
	for(LL i = 0; i < q; i++){
		LL t, r1, c1, r2, c2;
		cin >> t >> r1 >> c1 >> r2 >> c2;
		pair<pair<LL,LL>, pair<LL,LL> > gg =
			make_pair(make_pair(r1, c1), make_pair(r2, c2));
		if(t == 2){
			updrect(r1, c1, r2, c2, -nums[gg]);
			nums.erase(gg);
		} else if(t == 1){
			LL f = (rand() << 15) + rand();
			nums[gg] = f;
			updrect(r1, c1, r2, c2, nums[gg]);			
		} else if(t == 3){
			LL ans1 = q2(r1, c1);
			LL ans2 = q2(r2, c2);
			cout << ((ans1 == ans2) ? "Yes" : "No") << endl;
		}
	}
}