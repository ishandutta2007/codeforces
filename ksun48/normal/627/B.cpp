#include<bits/stdc++.h>
#define MAXN 400001
using namespace std;
typedef long long LL;
LL n, z, a, b, q;

LL BIT[2][MAXN]; // b, a
LL sum(LL c, LL i){
	LL k = 0;
	while(i > 0){
		k += BIT[c][i];
		i -= i & -i;
	}
	return k;
}
void add(LL c, LL i, LL k){
	while(i < MAXN){
		BIT[c][i] += k;
		i += i & -i;
	}
}
LL orders[MAXN];
int main(){
	cin >> n >> z >> a >> b >> q;
	for(LL i = 0; i < MAXN; i++){
		orders[i] = 0;
		BIT[0][i] = BIT[1][i] = 0;
	}
	for(LL i = 0; i < q; i++){
		LL ty;
		cin >> ty;
		if(ty == 1){
			LL day, ord;
			cin >> day >> ord;
			add(0, day, min(b,ord+orders[day])-min(b,orders[day]));
			add(1, day, min(a,ord+orders[day])-min(a,orders[day]));
			orders[day] += ord;
		} else if(ty == 2){
			LL p;
			cin >> p;
			cout << sum(0,p-1) - sum(1,p+z-1)+sum(1,n)<< endl;
		}
	}

}