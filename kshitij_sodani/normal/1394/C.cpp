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
vector<vector<llo>> ss;

bool check(llo mid,bool st=false){
	vector<llo> cur;
	vector<llo> cur2;
	cur.pb(0);
	cur.pb(0);
	cur.pb(-1e9);
	cur2.pb(1e9);
	cur2.pb(1e9);
	cur2.pb(1e9);
	for(llo i=0;i<n;i++){
		for(llo j=0;j<3;j++){
			cur[j]=max(cur[j],ss[i][j]-mid);
			cur2[j]=min(cur2[j],ss[i][j]+mid);
		}
		
	}

	for(llo i=0;i<3;i++){
		if(cur[i]>cur2[i]){
			return false;
		}
	}
	//llo xx=cur2[0]-cur[0];
	//llo yy=cur2[1]-cur[1];

	if(min(cur[0]-cur2[1],cur[1]-cur2[0])>cur2[2]){
		return false;
	}
	
	if(max(cur2[1]-cur[0],cur2[0]-cur[1])<cur[2]){
		return false;
	}
		pair<llo,llo> xx;
		xx.a=min(cur[0]-cur2[1],cur[1]-cur2[0]);
		xx.b=max(cur2[1]-cur[0],cur2[0]-cur[1]);
		llo cot;
		pair<llo,llo> ac={max(xx.a,cur[2]),min(xx.b,cur2[2])};
		if(ac.b<ac.a){
			return false;
		}
		if(ac.b-ac.a==0 and ac.a==0){
			cot=0;
		}
		else{
			cot=ac.a;
			if(cot==0){
				cot++;
			}
		}
		if(cot==0){
			pair<llo,llo> cc={max(cur[0],cur[1]),min(cur2[0],cur2[1])};
			if(cc.a>cc.b){
				return false;
			}
			if(cc.b-cc.a==0 and cc.a==0){
				return false;
			}
			llo pp=cc.a;
			if(pp==0){
				pp+=1;
			}
			if(st){
				for(llo i=0;i<pp;i++){
					cout<<"B";
				}
				for(llo i=0;i<pp;i++){
					cout<<"N";
				}
				cout<<endl;
			}
			return true;
		}

		//cot=max(xx.a,cur[2]);
		if(true){
			pair<llo,llo> yy={cur[1]+cot,cur2[1]+cot};
			if(yy.b<cur[0] or yy.a>cur2[0]){

			}
			else{
				if(st){
					llo zz=max(yy.a,cur[0]);
					for(llo i=0;i<zz;i++){
						cout<<'B';
					}
					for(llo i=0;i<zz-cot;i++){
						cout<<'N';
					}
					cout<<endl;
					assert(cot>=cur[2] and cot<=cur2[2]);
				}
				return true;
			}
		}
		/*if(true){
			pair<llo,llo> yy={cur[0]+cot,cur2[0]+cot};
			if(yy.b<cur[1] or yy.a>cur2[1]){

			}
			else{
				if(st){
					llo zz=max(yy.a,cur[1]);
					//zz-N
					for(llo i=0;i<zz;i++){
						cout<<'N';
					}
					for(llo i=0;i<zz-cot;i++){
						cout<<'B';
					}
					cout<<endl;

					assert(cot>=cur[2] and cot<=cur2[2]);
				}
				return true;
			}
		}*/
	
	return false;


}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	
	for(llo i=0;i<n;i++){
		string s;
		cin>>s;
		llo aa=0;
		llo bb=0;
		for(llo j=0;j<s.size();j++){
			if(s[j]=='B'){
				aa++;
			}
			else{
				bb++;
			}
		}
		ss.pb({aa,bb,aa-bb});
	}
	llo low=0;
	llo high=1000001;
	while(low<high-1){
		llo mid=(low+high)/2;
		if(check(mid)){
			high=mid;
		}
		else{
			low=mid;
		}
	}
	llo ans=high;
	if(check(low)){
		ans=low;
	}
	cout<<ans<<endl;

	check(ans,true);



 
	return 0;
}