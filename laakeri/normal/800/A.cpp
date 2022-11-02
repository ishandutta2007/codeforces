#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
const ld eps=1e-6;

ld a[101010];
ld b[101010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	ld p;
	cin>>p;
	ld su=0;
	for (int i=0;i<n;i++){
		int aa,bb;
		cin>>aa>>bb;
		a[i]=aa;
		b[i]=bb;
		su+=a[i];
	}
	if (su<p+eps){
		cout<<-1<<endl;
		return 0;
	}
	ld mi=0;
	ld ma=1e16;
	int fo=0;
	for (int it=0;it<200;it++){
		ld mid=(mi+ma)/2;
		ld np=0;
		for (int i=0;i<n;i++){
			ld pp=b[i]-a[i]*mid;
			if (pp<0) np+=(-pp)/p;
		}
		if (np>mid-eps){
			fo=1;
			ma=mid;
		}
		else{
			mi=mid;
		}
	}
	if (!fo){
		cout<<-1<<endl;
	}
	else{
		cout<<setprecision(15)<<ma<<endl;
	}
}