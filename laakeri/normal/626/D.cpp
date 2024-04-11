#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

ld d1[5050];

ld d2[10101];

const int M=5000;

int a[2020];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	ld tt=0;
	for (int i=0;i<n;i++){
		for (int ii=0;ii<n;ii++){
			if (i!=ii){
				if (a[i]>a[ii]){
					d1[a[i]-a[ii]]++;
					tt++;
				}
			}
		}
	}
	for (int i=0;i<=M;i++){
		d1[i]/=tt;
	}
	for (int i=0;i<=2*M;i++){
		for (int j=0;j<=M;j++){
			if (i-j>=0&&i-j<=M){
				d2[i]+=d1[i-j]*d1[j];
			}
		}
	}
	ld v=0;
	for (int i=0;i<=M;i++){
		ld p1=0;
		for (int j=0;j<i;j++){
			p1+=d2[j];
		}
		v+=p1*d1[i];
	}
	cout<<setprecision(15)<<v<<endl;
}