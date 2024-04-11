#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int n;

ll a[202020];
ll s[202020];

ld getv(int x, int i){
	if (i-x<0||n-x<=i) return -1;
	ld avg=s[n-1]-s[n-1-x]+s[i];
	if (i-x-1>=0) avg-=s[i-1-x];
	avg/=(ld)(2*x+1);
	return avg-(ld)a[i];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	srand(time(0));
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	if (n<3){
		cout<<1<<endl;
		cout<<a[0]<<endl;
		return 0;
	}
	sort(a, a+n);
	for (int i=0;i<n;i++){
		s[i]=a[i];
		if (i) s[i]+=s[i-1];
	}
	ld v=-0.1;
	int b1=-1;
	int b2=-1;
	int f=0;
	for (int i=0;i<n&&f<1000;i++){
		if (i<n-1&&a[i+1]==a[i]){
			ld t=getv(min(i, n-i-1), i);
			//cout<<x<<" "<<i<<" "<<t<<endl;
			if (t>v){
				v=t;
				b1=i;
				b2=min(i, n-i-1);
			}
			continue;
		}
		f++;
		for (int x=0;x<=n/2;x++){
			ld t=getv(x, i);
			//cout<<x<<" "<<i<<" "<<t<<endl;
			if (t>v){
				v=t;
				b1=i;
				b2=x;
			}
			if (t<-0.5) break;
		}
	}
	for (int i=1000;i<n;i++){
		for (int x=0;x<=min(n/2, 500);x++){
			ld t=getv(x, i);
			if (t>v){
				v=t;
				b1=i;
				b2=x;
			}
		}
	}
	cout<<b2*2+1<<endl;
	for (int i=b1;i>=b1-b2;i--){
		cout<<a[i]<<" ";
	}
	for (int i=n-b2;i<n;i++){
		cout<<a[i]<<" ";
	}
}