#include <bits/stdc++.h>
using namespace std;

int x[400005];
int mx[400005];
int n;
vector<int> t[400005];

int main(){
	int k=1;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",x+i);
		x[n+i]=x[i];
		if(i)k=k&&x[i]==x[i-1];
	}
	if(k){cout<<1LL*n*(n-1)<<endl;return 0;}
	long long r=0;
	for(int i=1;i<n;++i)t[__gcd(n,i)].push_back(i);
	for(int i=1;i<n;++i){
		if(n%i==0){
			memset(mx,0,sizeof(mx));
			for(int j=0;j<n;++j){
				mx[j%i]=max(mx[j%i],x[j]);
			}
			bool z=false;
			for(int l=0;l<n;++l){
				if(x[l]!=mx[l%i]){
					z=true;
					k=-1;
					int a=0;
					for(int j=l;j<n+l;++j){
						if(x[j]==mx[j%i]){
							if(a<t[i].size()&&j-k==t[i][a])a++;
							r+=a;//if(j-k>=i)r++;
						}
						else {
							k=j;
							a=0;
						}
					}
					break;
				}
			}
			if(!z){
				r+=t[i].size()*n;
			}
		}
	}
	cout<<r<<endl;
	return 0;
}