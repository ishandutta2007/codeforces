#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n' 

llo n,r1,r2,r3,d;
llo it[1000001];
llo pre[1000001];
llo pre2[1000001];
llo dp[1000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>r1>>r2>>r3>>d;
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	llo ans=0;

	for(llo i=0;i<n;i++){
		llo mi=it[i]*r1+r3;
		mi=min(mi,min(r2+r1,(it[i]+2)*r1));
		pre2[i+1]=pre2[i]+mi;
		//cout<<pre2[i+1]<<":";
	}
	//cout<<endl;




	multiset<llo> cur;
	multiset<llo> cur2;
	llo ba=0;
	for(llo i=0;i<n;i++){
		dp[i]=pre2[i+1]+2*d*i;
		if(i==0){
			dp[i]+=2*d;
		}

		if(cur.size()>0){
			llo xx=*cur.begin();
			dp[i]=min(dp[i],pre2[i+1]+xx+2*i*d);
		}

		/*for(llo j=0;j<=i-1;j++){
			llo coo=0;
			if(j>0){
				coo=dp[j-1];
			}
			dp[i]=min(dp[i],pre2[i+1]-pre2[j]+coo+2*(i-j)*d);
		}*/
		if(i>0){
			dp[i]=min(dp[i],dp[i-1]+it[i]*r1+r3);
		}
		else{
			dp[i]=min(dp[i],it[i]*r1+r3);
		}


		if(i==n-1){
			llo ans=dp[n-1];

			llo xx=*cur2.begin();
			//cout<<xx<<".";
			ans=min(ans,pre2[i+1]+xx+i*d+2*d);
			ans=min(ans,pre2[i]+xx+i*d+it[i]*r1+r3);
			ans=min(ans,dp[n-3]+pre2[i+1]-pre2[i-1]+2*d);

			cout<<ans+(n-1)*d<<endl;
			return 0;
		}




		llo cot=0;
		if(i>0){
			cot=dp[i-1];
		}
		cur.insert(-pre2[i]-2*i*d+cot);
		cur2.insert(-pre2[i]-i*d+cot);
		//cout<<dp[i]<<",";
	
	}
//	cout<<endl;



	return 0;
	for(llo i=0;i<n;i++){
		llo kk=0;
		if(cur.size()){
			llo xx=*(cur.begin());
			xx+=pre2[i+1];
			xx+=i*d*2;
			kk=xx;
		}
		cur.insert(ba-pre2[i]-i*2*d);
		cur2.insert(ba-pre2[i]-i*d);


		ba=ba+it[i]*r1+r3;
		ba=min(ba,kk+it[i]*r1+r3);
		cout<<ba<<":"<<kk<<endl;
		if(i==n-1){
			llo ans=ba;

			llo xx=*(cur2.begin());
			xx+=pre2[i]+min(it[i]*r1+r3,2*d+min(r2+r1,(it[i]+2)*r1));
			xx+=i*d;
			ans=min(ans,xx);
			cout<<ans<<endl;
			return 0;
		}


		
		

	}
	return 0;







	for(llo i=0;i<n;i++){
		llo mi=it[i]*r1+r3;
		mi=min(mi,2*d+min(r2+r1,(it[i]+2)*r1));
		pre[i]=mi;
		if(i>0){
			pre[i]+=pre[i-1];
		}
	}
	ans+=pre[n-1];
	for(llo i=0;i<n;i++){
		cout<<pre[i]<<":";
	}
	cout<<endl;
	llo su=0;
	llo ii=n-1;
	llo mii=it[ii]*r1+r3;
	mii=min(mii,3*d+min(r2+r1,(it[ii]+2)*r1));
	su+=mii;

	llo maa=it[ii]*r1+r3;
	maa=min(maa,min(r2+r1,(it[ii]+2)*r1));
	cout<<mii<<"//"<<maa<<endl;
	for(llo i=n-2;i>=0;i--){
		su+=d;
		llo ma=it[i]*r1+r3;
		ma=min(ma,min(r2+r1,(it[i]+2)*r1));

		su+=ma;

		llo coo=0;
		if(i>0){
			coo+=pre[i-1];
		}
		ans=min(ans,su+coo);

		llo cot=su+coo+(n-1-i)*d;
		cot-=mii;
		cot+=maa;
		ans=min(ans,cot);
		cout<<coo+su<<":";
	}
	cout<<endl;




	cout<<ans+(n-1)*d<<endl;








	return 0;
}