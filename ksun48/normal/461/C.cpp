#include<iostream>
using namespace std;
typedef long long LL;
int sums[500000];
int l[500000];
int r[500000];
int maps[500000];
int num[500000];

void maketree(int i){
	//cout << l[i] << " " << r[i] << " " << sums[i] << endl;
	if(l[i] == r[i]){
		maps[l[i]] = i;
		return;
	}
	l[2*i+1] = l[i];
	r[2*i+1] = (l[i]+r[i])/2;
	sums[2*i+1] = r[2*i+1]+1-l[2*i+1];

	l[2*i+2] = r[2*i+1]+1;
	r[2*i+2] = r[i];
	sums[2*i+2] = r[2*i+2]+1-l[2*i+2];
	maketree(2*i+1);
	maketree(2*i+2);
	return;
}

void upd(int i, int val){
	num[i] = val;
	int y = maps[i];
	sums[y] = val;
	while(1){
		y = (y-1)/2;
		sums[y] = sums[2*y+1] + sums[2*y+2];
		if(y == 0) break;
	}
}
int query(int left, int right, int z){
	if(l[z] == left && r[z] == right){
		return sums[z];
	} else if(left >= l[2*z+2]){
		return query(left, right, 2*z+2);
	} else if(right <= r[2*z+1]){
		return query(left, right, 2*z+1);
	} else {
		return query(left, r[2*z+1], 2*z+1) + query(l[2*z+2], right, 2*z+2);
	}
}
int main(){
	int n;
	cin >> n;
	l[0] = 0;
	r[0] = n-1;
	sums[0] = n;
	maketree(0);

	for(int i = 0; i < n; i++) num[i] = 1;
	int ls = 0;
	int rs = n;
	int backwards = 0;
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int zz = 0;
		cin >> zz;
		if(zz == 1){
			int p;
			cin >> p;
			if(backwards){
				p = rs-ls-p;
				backwards = 0;
			}
			if(2*p >= (rs-ls)){
				backwards = 1;
				for(int i = 0; i < (rs-ls-p); i++){
					upd(ls+p-1-i, num[ls+p-1-i]+num[ls+p+i]);
					upd(ls+p+i, 0);
				}
				rs = ls+p;
			} else {
				for(int i = 0; i < p; i++){
					upd(ls+p+i, num[ls+p-1-i]+num[ls+p+i]);
					upd(ls+p-1-i, 0);
				}
				ls += p;
			}

		} else {
			int l1, r1;
			cin >> l1 >> r1;
			if(backwards == 0){
				cout << query(ls+l1, ls+r1-1, 0) << endl;
			} else {
				cout << query(rs-r1, rs-l1-1, 0) << endl;
			}
		}
	}

}