#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
double x[N],b[N],d[N];
int pre[N];
void sol(int n){
	if(n==0)return;
	sol(pre[n]);
	cout<<n<<" ";
}
int main(){
	int n,i,j,T,ll;
	d[0]=0;
	cin>>n>>ll;
	for(i=1;i<=n;++i)
		cin>>x[i]>>b[i];
	T=100;
	double l,r=N,mid;
	while(T--){
		mid= (l+r)/2;
		for(i=1;i<=n;++i){
			d[i]=-1e9;
			for(j=0;j<i;++j)
				if( d[j]- sqrt(fabs(x[i]-x[j]-ll))+ b[i]*mid>d[i]){
					d[i]= d[j]- sqrt(fabs(x[i]-x[j]-ll))+ b[i]*mid;
					pre[i]=j;
				}
		}
		if(d[n]>0)
			r= mid;
		else
			l= mid;
	}
	sol(n);
}