//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
llo it[100001];
llo pc[2];
llo pre[30][100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n;
	cin>>n;
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
/*	for(int i=1;i<n;i++){
		if((it[i]^it[i+1])<it[i-1]){
			cout<<1<<endl;
			return 0;
		}
	}*/
	llo ans=n+1;
	llo kcc=n+1;
	for(llo i=29;i>=0;i--){
		llo co=0;
	//	llo kk=0;
	//	llo mm=-1;
	//	vector<int> pp;
	//	pp.pb(0);
		llo cot=0;
		for(llo j=0;j<n;j++){
			if(it[j]&(1LL<<i)){
				co+=1;
			}	
			pre[i][j+1]=co;
		}

	}
	for(llo i=29;i>=0;i--){
		llo co=pre[i][n];
		if(co==0){
			continue;
		}
		if(co==1){
			n-=1;
			continue;
		}
		if(co>=3){
			ans=min(ans,(llo)1);
			break;
		}
		llo cur=0;
		llo cot=0;
		for(llo j=n-2;j>=0;j--){
			cur^=it[j];
			cot+=1;
			if(cur>it[n-1]){

				ans=min(ans,cot-1);
			}
		}
		llo cur2=0;
		llo coc=0;
		for(int j=n-1;j>=0;j--){
			cur2^=it[j];
			coc+=1;
			if(j<n-1){
				for(int k=29;k>=0;k--){
					if(cur2&(1<<k)){
						if(pre[k][n-1]-pre[k][j]>0){
							ans=min(ans,coc-2);
						}
						else{
							break;
						}
					}
				}
			}
		}
		n-=2;
	}
	if(ans==kcc){
		cout<<-1<<endl;
		return 0;
	}
	cout<<ans<<endl;



 
 
	return 0;
}