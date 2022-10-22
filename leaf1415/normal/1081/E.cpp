#include <iostream>
#include <vector>
#define llint long long 

using namespace std;

llint n;
llint x[100005];
llint sum[100005];
vector<llint> vec[200005];

bool get(llint d, llint pre, llint &l, llint &r)
{
	if(d%2){
		llint p = (d-1)/2;
		if(p*p <= pre) return false;
		llint ub = (int)vec[d].size()-1, lb = -1, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			llint c = vec[d][mid], len = d/c;
			llint p = (c-(len-1)-1)/2;
			if(p > 0 && p*p > pre) ub = mid;
			else lb = mid;
		}
		llint C = vec[d][ub], Len = d/C;
		llint D = C-(Len-1);
		l = (D-1)/2, r = l+Len;
		return true;
	}
	else{
		llint p = (d-4)/4;
		if(p*p <= pre) return false;
		llint ub = (int)vec[d].size()-1, lb = -1, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			llint c = vec[d][mid], len = d/c;
			llint p = (c+1-len-1)/2;
			if(p > 0 && p*p > pre) ub = mid;
			else lb = mid;
		}
		llint C = vec[d][ub], Len = d/C;
		llint D = C+1-Len;
		l = (D-1)/2, r = l+Len;
		return true;
	}
}

int main(void)
{
	for(int i = 1; i < 200005; i++){
		for(int j = 1; i*j < 200005; j++){
			if(i%2 && j%2 || i%2==0 && j%2==0) vec[i*j].push_back(i);
		}
	}
	
	cin >> n;
	for(int i = 2; i <= n; i+=2) cin >> x[i];
	
	llint pre = 0;
	for(int i = 2; i <= n; i+=2){
		if(x[i] % 2 && x[i] >= 3 || x[i] % 4 == 0 && x[i] >= 8){
			llint l, r;
			if(!get(x[i], pre, l, r)){
				cout << "No" << endl;
				return 0;
			}
			sum[i-1] = l*l, sum[i] = r*r;
			pre = sum[i];
		}
		else{
			cout << "No" << endl;
			return 0;
		}
	}
	
	for(int i = 1; i <= n; i+=2) x[i] = sum[i] - sum[i-1];
	cout << "Yes" << endl;
	for(int i = 1; i <= n; i++) cout << x[i] << " "; cout << endl;
	return 0;
}