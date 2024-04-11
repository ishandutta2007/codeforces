//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo it[100001];
llo co[10];
llo pre[1000001][3];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	llo n=s.size();
	for(llo i=0;i<n;i++){
		it[i]=2;
		if(s[i]=='0'){
			it[i]=0;
		}
		if(s[i]=='1'){
			it[i]=1;
		}
	}
	llo aa,bb;
	cin>>aa>>bb;
	if(aa>bb){
		for(llo i=0;i<n;i++){
			if(it[i]<=1){
				it[i]=1-it[i];
			}
		}
		swap(aa,bb);
	}
	//now aa<=bb
	for(llo i=1;i<=n;i++){
		for(llo j=0;j<3;j++){
			pre[i][j]=pre[i-1][j];
		}
		pre[i][it[i-1]]++;
	}
	vector<llo> ss;
	llo cot=0;
	//llo pp=0;
	for(llo i=0;i<n;i++){
		if(it[i]==1){
			cot+=aa*co[0];
		//	pp+=co[0];
		}
		else if(it[i]==0){
			cot+=bb*co[1];
			//pp+=co[1];
		}

		co[it[i]]++;
		if(it[i]==2){
			ss.pb(i);
		}
	}
//	cout<<cot<<",,,"<<endl;
	llo ans=1e18;
	llo ac=0;
	llo cd=0;
	for(auto j:ss){
		cd+=(pre[n][0]-pre[j][0]);
	}
	for(llo i=0;i<=ss.size();i++){
		llo cc=co[0];
		llo dd=co[1];
		cc+=i;
		dd+=((llo)ss.size())-i;
		llo le=cc*dd-co[0]*co[1];
		//cout<<le<<endl;
		llo cur=cot;
		cur+=le*aa;
		if(i>0){
			ac+=pre[ss[i-1]+1][1];
			cd-=(pre[n][0]-pre[ss[i-1]][0]);
		}
		cur+=(ac+cd)*(bb-aa);
		//cout<<ac<<","<<cd<<endl;
	//	cout<<i<<":"<<cur<<endl;
		ans=min(ans,cur);
	}
	cout<<ans<<endl;











 
	return 0;
}