//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo n;
llo it[501];
pair<llo,llo> ans[501];
const llo mod=998244353;
llo gcd(llo aa,llo bb){
	if(aa==0){
		return bb;
	}

	return gcd(bb%aa,aa);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		/*if(it[i]==1){
			ans[i]={0,0};
			continue;
		}*/
		ans[i]={-1,-1};
		/*for(llo j=2;j*j*j<=it[i];j++){
			if(it[i]%j==0){
				llo cur=it[i];
				llo co=0;
				while(cur%j==0){
					cur/=j;
					co++;
				}
				if(cur==1){
					ans[i]={j,co};
					break;
				}
			}
		}*/
		if(ans[i].a==-1){
			llo low=1;
			llo high=37606;
			while(low<high){
				llo mid=(low+high)/2;
				llo xx=mid*mid*mid*mid;
				if(xx==it[i]){
					ans[i]={mid,4};
					break;
				}
				else if(xx<it[i]){
					low=mid+1;
				}
				else{
					high=mid-1;
				}
			}
			if(low*low*low*low==it[i]){
				ans[i]={low,4};
			}
		}
		if(ans[i].a==-1){
			llo low=1;
			llo high=1259921;
			while(low<high){
				llo mid=(low+high)/2;
				llo xx=mid*mid*mid;
				if(xx==it[i]){
					ans[i]={mid,3};
					break;
				}
				else if(xx<it[i]){
					low=mid+1;
				}
				else{
					high=mid-1;
				}
			}
			if(low*low*low==it[i]){
				ans[i]={low,3};
			}
		}
		if(ans[i].a==-1){
			llo low=1;
			llo high=1414213562;
			while(low<high){
				llo mid=(low+high)/2;
				llo xx=mid*mid;
				if(xx==it[i]){
					ans[i]={mid,2};
					break;
				}
				else if(xx<it[i]){
					low=mid+1;
				}
				else{
					high=mid-1;
				}
			}
			if(low*low==it[i]){
				ans[i]={low,2};
			}
		}
		
		


		/*llo x=sqrt(it[i]);
		if(x*x==it[i]){
			ans[i]={x,2};
			continue;
		}*/
	}
	map<llo,llo> ss;
	for(llo i=0;i<n;i++){
		for(llo j=i+1;j<n;j++){
			if(it[i]!=it[j]){
				llo x=gcd(it[i],it[j]);
				if(x>1){
					if(ans[i].a==-1){
						
						ans[i].a=-2;
						ss[x]+=1;
						ss[it[i]/x]+=1;
					//	ans[i]={x,it[i]/x};
					}
					if(ans[j].a==-1){
						ans[j].a=-2;
						ss[x]+=1;
						ss[it[j]/x]+=1;

					//	ans[j]={x,it[j]/x};
					}
				}
			}
		}
	}

	
	map<llo,llo> tt;
	for(llo i=0;i<n;i++){
		if(ans[i].a!=-1){
			if(ans[i].a==-2){
				continue;
			}
			ss[ans[i].a]+=ans[i].b;
		}
		else{
			tt[it[i]]++;
		}
	}
	llo aa=1;
	for(auto j:ss){
		aa=(aa*(j.b+1))%mod;
		//cout<<j.a<<":"<<j.b<<endl;
	}
	for(auto j:tt){
		aa=(aa*(j.b+1))%mod;
		aa=(aa*(j.b+1))%mod;
		//cout<<j.a<<",,"<<j.b<<endl;
	}
	cout<<aa<<endl;



 
	return 0;
}