#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
LL x[210000];
double sum[210001];
double ans = 0;
LL maxcc = 1;
LL maxmed = 0;
LL maxex = 0;
//cc = 1 means odd, cc = 2 means even (med, med+1)
double skew(LL cc, LL med, LL ex){
	if(cc == 1){
		if(n-ex <= med) return 0.0;
		if(med-ex < 0) return 0.0;
		double a = sum[n]-sum[n-ex]+sum[med]-sum[med-ex]-2.0*(ex*1.0)*(1.0*x[med]);
		return a/(2.0*ex+1.0);
	} else if(cc == 2){
		if(n-ex <= med+1) return 0.0;
		if(med-ex < 0) return 0.0;
		double a = sum[n]-sum[n-ex]+sum[med]-sum[med-ex] - (ex*1.0)*(1.0*x[med]+1.0*x[med+1]);
		return a/(2.0*ex+2.0);
	}
}
LL ts(LL cc, LL med){
	LL left = 0;
	LL right;
	if(cc == 1){
		right = min(n-med-1,med);
	} else if(cc == 2){
		right = min(med, n-(med+1)-1);
	}
	while(left + 2 < right){
		LL m1 = left + (right-left)/3;
		LL m2 = left + 2*((right-left)/3);
		if(skew(cc,med,m1) < skew(cc,med,m2)){
			left = m1;
		} else {
			right = m2;
		}
	}
	double a = skew(cc,med,left);
	double b = skew(cc,med,(left+right)/2);
	double c = skew(cc,med,right);
	if(a >= b && a >= c) return left;
	if(b >= c && b >= a) return (left+right)/2;
	if(c >= a && c >= b) return right;
}
int main(){
	cin >> n;
	sum[0] = 0;
	for(LL i = 0; i < n; i++){
		cin >> x[i];
	}
	sort(x,x+n);
	for(LL i = 0; i <= n; i++){
		sum[i] = sum[i-1]+x[i-1];
		//cout << sum[i] << endl;
	}
	for(LL i = 0; i < n; i++){
		LL a = ts(1,i);
		if(skew(1,i,a) > ans){
			ans = skew(1,i,a);
			maxcc = 1;
			maxmed = i;
			maxex = a;
		}
		if(i < n-1){
			LL b = ts(2,i);
			if(skew(2,i,b) > ans){
				ans = skew(2,i,b);
				maxcc = 2;
				maxmed = i;
				maxex = a;
			}
		}
	}
	/*int r,s,t;
	cin >> r >> s >> t;
	cout << skew(r,s,t) << endl;*/
	if(maxcc == 1){
		cout << 2*maxex+1 << endl;
		for(int i = maxmed-maxex; i <= maxmed; i++){
			cout << x[i] << " ";
		}
		for(int i = n-maxex; i < n; i++){
			cout << x[i] << " ";
		}
		cout << endl;
	} else if(maxcc == 2){
		cout << 2*maxex + 2 << endl;
		for(int i = maxmed-maxex; i <= maxmed+1; i++){
			cout << x[i] << " ";
		}
		for(int i = n-maxex; i < n; i++){
			cout << x[i] << " ";
		}
		cout << endl;
	}

}