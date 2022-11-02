#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

const int M=1030;
int c[M+10];
int nc[M+10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k,x;
	cin>>n>>k>>x;
	for (int i=0;i<n;i++){
		int a;
		cin>>a;
		c[a]++;
	}
	for (int i=0;i<k;i++){
		int s=0;
		for (int j=0;j<M;j++){
			int t;
			if (s%2==0) t=c[j]/2+c[j]%2;
			else t=c[j]/2;
			nc[j^x]+=t;
			nc[j]+=c[j]-t;
			s+=c[j];
		}
		for (int j=0;j<M;j++){
			c[j]=nc[j];
			nc[j]=0;
		}
	}
	int mi=M;
	int ma=0;
	for (int i=0;i<M;i++){
		if (c[i]) mi=min(mi, i);
		if (c[i]) ma=max(ma, i);
	}
	cout<<ma<<" "<<mi<<endl;
}