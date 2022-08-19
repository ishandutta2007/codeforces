#include<iostream>
using namespace std;
typedef long long LL;
LL M;
const LL m = 110000;
LL type[m];
LL x[m];
LL l[m];
LL c[m];
LL before[m];
LL cur = 0;
LL query(LL pos){
	LL s = 0;
	LL e = M;
	while(s+1 < e){
		LL mid = (s+e)/2;
		if(pos < before[mid]){
			e = mid;
		} else if(pos >= before[mid]){
			s = mid;
		}
	}
	//cout << pos << " " << s << endl;
	if(type[s] == 1){
		return x[s];
	} else {
		return query((pos-before[s]) % l[s]);
	}
}
int main(){
	cin >> M;
	for(LL i = 0; i < M; i++){
		before[i] = cur;
		cin >> type[i];
		if(type[i] == 1){
			cin >> x[i];
			cur++;
		} else {
			cin >> l[i] >> c[i];
			cur += l[i]*c[i];
		}
	}
	before[M] = cur;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		LL a;
		cin >> a;
		query(a-1);
		cout << query(a-1) << " ";
	}
	cout << endl;
}