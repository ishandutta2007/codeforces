//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

const llo mod=(1LL<<32);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	llo aa,bb,cc,dd;
	llo n;
	cin>>n;
	cin>>aa>>bb>>cc>>dd;
	llo ss=sqrt(n);
	vector<llo> ss2;
	for(llo i=0;i<=ss;i++){
		ss2.pb(0);
	}
	vector<llo> pp;
	for(llo i=2;i<=ss;i++){
		if(ss2[i]==0){
			pp.pb(i);
			for(llo j=i;j<=ss;j+=i){
				ss2[j]=1;
			}
		}
	}
	vector<llo> tt;
	for(llo i=0;i<ss;i++){
		tt.pb(0);
	}
	llo ans=0;
	llo ans2=0;
	llo ans3=0;
	llo ans4=0;
	llo fin=0;
	for(llo i=1;i<=n;i+=ss){
		for(llo j=0;j<ss;j++){
			tt[j]=0;
		}
		for(auto j:pp){
			llo x=((i+j-1))/j;
			x*=j;
			for(llo ii=x;ii<i+ss;ii+=j){
				if(ii>n){
					break;
				}
				if(ii>j){
					tt[ii-i]=1;
				}
			}
		}
		for(llo j=i;j<i+ss;j+=1){
			if(j>n){
				break;
			}
			if(tt[j-i]==0 and j>1){
				//cal
				llo cur=j;
				llo cot=0;
				while(cur<=n){
					cot+=(n/cur);
					cur*=j;
				}
				//cout<<j<<":"<<cot<<endl;

				llo cur2=aa;
				cur2=(cur2*j+bb)%mod;
				cur2=(cur2*j+cc)%mod;
				cur2=(cur2*j+dd)%mod;
				fin=(fin+cur2*cot)%mod;
			}
		}
	}
	cout<<fin<<endl;

 
	return 0;
}