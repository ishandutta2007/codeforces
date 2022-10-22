#include<bits/stdc++.h>
using namespace std;
int l[200001];
vector<int> s;
int m;
int t;
int mr=0;
int n;
int one(int n) {
	if(n<=0) return 0;
	return n*(n-1)*(n-2)/6+n*(n-1)+n;
}
int two(int n,int m) {
	return m*(n*(n-1)/2+n);
}
int r,a,b,c,d;
int main()
{
	for(int i=1;i<=200000;i++) {
		s.clear();
		m=i;
		for(int j=2;j*j<=m;j++) {
			if(m%j==0) {
				while(m%j==0) {
					s.push_back(j);
					m/=j;
				}
			}
		}
		if(m!=1) s.push_back(m);
		r=1;
		d=1;
		if(s.size()>0) d++;
		for(int j=1;j<s.size();j++) {
			if(s[j]==s[j-1]) d++;
			else {
				r*=d;
				d=2;
			}
		}
		r*=d;
		l[i]=r;
		//cout<<i<<" "<<r<<endl;
		//if(l[i]>l[mr]) mr=i;
	}
	//cout<<mr<<endl;
	scanf("%d",&t);
	int x,y,z,w;
	while(t--) {
		scanf("%d %d %d",&a,&b,&c);
		x=__gcd(a,b);
		y=__gcd(b,c);
		z=__gcd(a,c);
		w=__gcd(x,y);
		n=l[a]+l[b]+l[c]-l[x]-l[y]-l[z]+l[w];
		//cout<<n<<" "<<one(n)<<endl;
		r=one(n);
		r-=(one(l[a]+l[b]-l[y]-l[z]-l[x]+l[w])+one(l[c]+l[b]-l[y]-l[z]-l[x]+l[w])+one(l[a]+l[c]-l[y]-l[z]-l[x]+l[w]));
		//cout<<<<endl;
		r+=(one(l[a]-l[x]-l[z]+l[w])+one(l[b]-l[x]-l[y]+l[w])+one(l[c]-l[y]-l[z]+l[w]));
		r-=(two(l[a]-l[x]-l[z]+l[w],l[y])+two(l[b]-l[x]-l[y]+l[w],l[z])+two(l[c]-l[y]-l[z]+l[w],l[x]));
		/*d=0;
		int d1=0;
		for(int i=1;i<=300;i++) {
			for(int j=i;j<=300;j++) {
				for(int k=j;k<=300;k++) {
					if(a%i==0 && b%j==0 && c%k==0) d++;
					else {
						if(a%i==0 && c%j==0 && b%k==0) d++;
						else {
							if(b%i==0 && a%j==0 && c%k==0) d++;
							else {
								if(b%i==0 && c%j==0 && a%k==0) d++;
								else {
									if(c%i==0 && a%j==0 && b%k==0) d++;
									else {
										if(c%i==0 && b%j==0 && a%k==0) d++;
									}
								}
							}
						}
					}
					//if(d>d1) cout<<i<<" "<<j<<" "<<k<<endl;
					d1=d;
				}
			}
		}*/
		printf("%d\n",r);
	}
	return 0;
}