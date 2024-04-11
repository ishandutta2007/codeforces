#include<bits/stdc++.h>
using namespace std;
int n,m;
bool prime[200000];
bool step[200000];
vector<pair<int,int> > a;
int main()
{
	scanf("%d %d",&n,&m);
	if(m<n-1) {
		printf("Impossible");
		return 0;
	}
	if(n<=1100) {
		for(int i=2;i<=n;i++) {
			a.push_back(make_pair(1,i));
			m--;
		}
		for(int i=2;i<=n && m>0;i++) {
			for(int j=i+1;j<=n && m>0;j++) {
				if(__gcd(i,j)==1) {
					m--;
					a.push_back(make_pair(i,j));
				}
			}
		}
		if(m>0) printf("Impossible");
		else {
			printf("Possible\n");
			for(int i=0;i<a.size();i++) printf("%d %d\n",a[i].first,a[i].second);
		}
		return 0;
	}
	else {
		printf("Possible\n");
		for(int i=2;i<=n;i++) {
			printf("1 %d\n",i);
			m--;
			prime[i]=true;
		}
		//for(int i=2;i<=n;i=i*2) step[i]=true;
		for(int i=2;i<=n && m>0;i++) {
			if(prime[i] || step[i]) {
				for(int j=i+1;j<=n && m>0;j++) {
					if(j%i!=0) {
						printf("%d %d\n",i,j);
						m--;
					}
					else prime[j]=false;
				}
			}
		}
		//cout<<m<<endl;
	}
	return 0;
}