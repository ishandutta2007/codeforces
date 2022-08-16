
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 
llo it[100001];
llo val(llo j,llo kk){
	llo su=(j/kk)*(j/kk)*kk;
	su+=((j/kk)*2+1)*(j%kk);
	return su;


}
llo cur[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n,k;
	cin>>n>>k;
	llo ans=0;
/*	for(llo j=1;j<=15;j++){
		cout<<val(15,j)<<",";
	}*/
//	cout<<endl;
	priority_queue<pair<llo,llo>> ss;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		ans+=val(it[i],1);
		cur[i]++;
		if(cur[i]<it[i]){
			ss.push({val(it[i],cur[i])-val(it[i],cur[i]+1),i});
		}
	/*	llo pp=k/n;

		if(n-k%(k/n)>=i){
			pp+=1;

		}
		else{

		}
		llo su=(it[i]/pp)*(it[i]/pp)*pp;
		su+=((it[i]/pp)*2+1)*(it[i]%pp);
		ans+=su;
		cout<<it[i]<<":"<<pp<<endl;*/
	}
	for(llo ii=n;ii<k;ii++){
		pair<llo,llo> tt=ss.top();
		ss.pop();
		ans-=tt.a;
		llo i=tt.b;
		cur[i]++;
		if(cur[i]<it[i]){
			ss.push({val(it[i],cur[i])-val(it[i],cur[i]+1),i});
		}



	}

	/*for(llo i=0;i<n;i++){
		llo	pp=min(it[i],le/(n-i));
		ans+=val(it[i],pp);
		le-=pp;
	}*/
	cout<<ans<<endl;
	return 0;



/*	llo st=1;
	for(llo i=1;i<=10;i++){
		for(llo j=i+1;j<=10;j++){
			vector<llo> pre;
			vector<llo> pre2;

			for(llo k=1;k<=i;k++){
				//splitting i in k parts
				llo su=(i/k)*(i/k)*k;
				su+=((i/k)*2+1)*(i%k);
				pre.pb(su);
			}
			for(llo k=1;k<=j;k++){
				//splitting i in k parts
				llo su=(j/k)*(j/k)*k;
				su+=((j/k)*2+1)*(j%k);
				pre2.pb(su);
			}
			for(auto jj:pre){
				cout<<jj<<":";
			}
			cout<<endl;
			for(auto jj:pre2){
				cout<<jj<<":";
			}
			cout<<endl;

			for(llo k=2;k<=i+j;k++){
				llo mi=1e9;
				llo ind=-1;
				for(llo kk=1;kk<=min(i,k-1);kk++){
					if(kk-i>j){
						continue;
					}
					if(pre[kk-1]+pre2[k-kk-1]<=mi){
						mi=pre[kk-1]+pre2[k-kk-1];
						ind=kk;
					}
				}
				cout<<ind<<",";
				if(ind>k/2){
					st=0;
				}
			}
			cout<<endl;;
		
		}
	}
	cout<<st<<endl;


*/



	return 0;
}