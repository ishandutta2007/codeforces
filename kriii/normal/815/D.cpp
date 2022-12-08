#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;

struct pt{
	int x,y,z;
	bool operator <(const pt t)const{return z > t.z;}
}P[500050];

int N,X,Y,Z;

map<long long, long long> con;
long long cnt;

void upd(long long x, long long y)
{
	auto I = con.lower_bound(x);
	if (y <= I->second) return;

	long long last = I->second;
	con[x] = y;
	I = con.find(x);
	while (I != con.begin()){
		I--;
		if (I->second <= y){
			cnt -= (x - I->first) * (I->second - last);
			last = I->second;
			I = con.erase(I);
		}
		else{
			cnt -= (x - I->first) * (y - last);
			break;
		}
	}
}

int main()
{
	scanf ("%d %d %d %d",&N,&X,&Y,&Z);
	for (int i=0;i<N;i++){
		scanf ("%d %d %d",&P[i].x,&P[i].y,&P[i].z);
	}
	sort(P,P+N);

	long long up = Z, ans = 0;
	cnt = (long long) X * Y;
	con[0] = Y+1; con[X+1] = 0;
	for (int i=0;i<N;i++) upd(P[i].x,P[i].y);
	for (int i=0;i<N;i++){
		ans += (up - P[i].z) * cnt;
		upd(P[i].x,Y);
		upd(X,P[i].y);
		up = P[i].z;
	}
	ans += up * cnt;
	printf ("%lld\n",ans);

	return 0;
}