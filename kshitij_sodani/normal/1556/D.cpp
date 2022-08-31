//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
//vector<llo> cc={1,6,4,2,3,5,4};
pair<llo,llo> query(llo aa,llo bb){
	cout<<"or "<<aa+1<<" "<<bb+1<<endl;
	llo x,y;
	cin>>x;
	//x=cc[aa]|cc[bb];
	cout<<"and "<<aa+1<<" "<<bb+1<<endl;
	cin>>y;
	//y=cc[aa]&cc[bb];
	return {x,y};
}
llo it[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	llo t;
	//cin>>t;
	t=1;
	while(t--){
		llo n,k;
		cin>>n>>k;
		llo ma=0;
		pair<llo,llo> xx=query(0,1);
		pair<llo,llo> yy=query(1,2);
		pair<llo,llo> zz=query(0,2);
		xx.a+=xx.b;
		yy.a+=yy.b;
		zz.a+=zz.b;
		llo su=xx.a+yy.a+zz.a;
		su/=2;
		it[2]=su-xx.a;
		it[0]=su-yy.a;
		it[1]=su-zz.a;
		for(llo i=3;i<n;i++){
			pair<llo,llo> kk=query(0,i);
			it[i]=kk.b+(kk.a-it[0]);
		}
/*		for(llo i=0;i<n;i++){
			cout<<it[i]<<",";
		}
		cout<<endl;*/
		sort(it,it+n);
		cout<<"finish "<<it[k-1]<<endl;


	}



 
 
 
	return 0;
}