#include <bits/stdc++.h>
using namespace std;

void nie(){
	cout<<"NO"<<endl;
	exit(0);
}

int a[101010];
int c[101010];
int d[101010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	if (n%2==1) nie();
	int mi=1e9;
	int ma=1;
	for (int i=0;i<n;i++){
		cin>>a[i];
		mi=min(mi, a[i]);
		ma=max(ma, a[i]);
	}
	if (ma-mi>n/2) nie();
	int s=0;
	for (int i=0;i<n;i++){
		c[a[i]-mi]++;
	}
	ma-=mi;
	for (int i=0;i<=ma;i++){
		if (c[i]==0) nie();
		s=-s;
		s+=2*c[i];
		if (s<0){
			nie();
		}
		d[i]+=s;
		d[i+1]+=s;
	}
	for (int i=0;i<=ma+1;i++){
		if (d[i]!=c[i]*2){
			nie();
		}
	}
	cout<<"YES"<<endl;
}