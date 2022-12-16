#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define F(i) for(int i=0;i<n;i++)
#define Fm(i) for(int i=0;i<m;i++)
typedef long long LL;
typedef long double LD;
vector<int> aa,ab;
int main(){
	int a,b;
	cin>>a>>b;
	int n=0,m=0;
	int ans=0;
	bool sw=false;
	if(a>b)swap(a,b),sw=true;
	while(a>=(ans+1)){
		a-=ans+1;
		aa.push_back(ans+1);
		n++;
		ans++;
	}
	while(b>=(ans+1)){
		b-=ans+1;
		ab.push_back(ans+1);
		m++;
		ans++;
	}
	if(a+b>=(ans+1)){
		swap(ab[0],aa[(ab[0]-a)-1]);
		b+=a,a=0;
		b-=ans+1;
		ab.push_back(ans+1);
		m++;
		ans++;
	}
	if(sw){
		swap(n,m);
		swap(aa,ab);
	}
	printf("%d\n",n);
	F(i)printf("%d ",aa[i]);
	printf("\n%d\n",m);
	Fm(i)printf("%d ",ab[i]);
	return 0;
}