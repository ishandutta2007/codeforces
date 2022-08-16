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
llo aa[200001];
llo bb[200001];
llo cc[200001];
llo val[200001];
llo pre[200001];
llo pre2[200001];
const llo mod=998244353;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(llo i=0;i<n;i++){
		cin>>aa[i]>>bb[i]>>cc[i];
	}
	llo ans=0;
	llo cur=0;
	llo su=0;
	for(llo i=0;i<n;i++){
		ans=(ans+aa[i]-cur)%mod;
		cur=aa[i];
		/*if(cc[i]==0){
			cur++;
			ans=(ans+1)%mod;
			continue;
		}*/
		//do something
		pre[i]=aa[i]-bb[i];
		if(i==0){
			pre2[i]=pre[i];
		}
		else{
			llo low=i;
			for(llo j=19;j>=0;j--){
				if(low-(1<<j)>=0){
					if(bb[i]<aa[low-(1<<j)]){
						low-=(1<<j);
					}
				}
			}
			llo cur=pre2[i-1];
			if(low>0){
				cur=(cur-pre2[low-1]+mod)%mod;
			}
			pre[i]=(pre[i]+cur)%mod;
			/*
			for(llo j=0;j<i;j++){
				if(bb[i]<aa[j]){
					pre[i]=(pre[i]+pre[j])%mod;
				}
			}*/
			pre2[i]=(pre2[i-1]+pre[i])%mod;
		}
/*
		for(llo j=i;j>=0;j--){
			if(j==i){
				val[j]=1;
			}
			else{
				val[j]=0;
				for(llo k=j+1;k<=i;k++){
					if(bb[k]<aa[j]){
						val[j]=(val[j]+val[k])%mod;
					}
				}
			}
			ans=(ans+val[j]*(aa[j]-bb[j]))%mod;
		}*/
		su=(su+pre[i])%mod;
		if(cc[i]==1){
			ans=(ans+pre[i])%mod;
		}
		cur=aa[i];
		cur++;
		ans=(ans+1)%mod;



	}
 	
 
	cout<<ans<<endl;
 
 
 
	return 0;
}