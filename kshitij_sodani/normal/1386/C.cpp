#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
#define pb push_back
typedef long long llo;
//#define endl '\n'
int n,m,q;
int ans[200001];
vector<pair<int,int>> ed;
int st=0;
vector<pair<int,int>> kk;
vector<int> ll;
pair<int,int> par[200001];
int ss[200001];
pair<int,int> find(int aa){
	if(par[aa].a==aa){
		return {aa,0};
	}
	else{
		pair<int,int> xx=find(par[aa].a);
		return {xx.a,xx.b^par[aa].b};
	}
}
void add(int ii){
	//cout<<ii<<" +"<<endl;
	//ll.pb(ii);
	int aa=ed[ii].a;
	int bb=ed[ii].b;
	pair<int,int> xx=find(aa);
	pair<int,int> yy=find(bb);

	if(xx.a==yy.a){
		if(xx.b!=yy.b){
			kk.pb({-2,0});
		}
		else{
			st+=1;
			kk.pb({-1,0});
		}
	}
	else{
		if(ss[xx.a]<ss[yy.a]){
			swap(xx,yy);
		}
		if(xx.b==yy.b){
			par[yy.a]={xx.a,1};
			ss[xx.a]+=ss[yy.a];
			kk.pb({yy.a,xx.a});
		}
		else{
			par[yy.a]={xx.a,0};
			ss[xx.a]+=ss[yy.a];
			kk.pb({yy.a,xx.a});
		}
	}

}
void rollback(){
	//cout<<ll.back()<<"-"<<endl;
	if(kk.back().a==-1){
		st-=1;
	}
	else if(kk.back().a==-2){

	}
	else{
		par[kk.back().a]={kk.back().a,0};
		ss[kk.back().b]-=ss[kk.back().a];
	}
	kk.pop_back();
	//ll.pop_back();
}
void dnc(int aa,int bb,int cc,int dd){


	int mid=(aa+bb)/2;

	/*for(int i=0;i<n;i++){
		cout<<par[i]<<"/";
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<ss[i]<<"/";
	}
	cout<<endl;
	cout<<st<<endl;
*/
	int co=0;
	for(int i=aa;i<mid;i++){
		add(i);
		co+=1;
	}
	
/*	for(int i=0;i<n;i++){
		cout<<par[i]<<"/";
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<ss[i]<<"/";
	}
	cout<<endl;
*/
	//cout<<st<<endl;

 	if(st>0){
 		ans[mid]=dd+1;
 	}
 	else{
 		ans[mid]=mid;
 		for(int j=dd;j>=cc;j--){
 			if(j<=mid){
 				break;
 			}
	 		add(j);
 			co+=1;
 			if(st>0){
 				ans[mid]=j;
 				break;
 			}
 		}
 	}

 	for(int i=0;i<co;i++){
 		rollback();
 	}
 //	cout<<mid<<":"<<ans[mid]<<endl;
 	//cout<<aa<<":"<<bb<<":"<<cc<<":"<<dd<<endl;
 	//cout<<mid<<":"<<ans[mid]<<endl;
 /*		for(int i=0;i<n;i++){
		cout<<par[i]<<"/";
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<ss[i]<<"/";
	}
	cout<<endl;*/

//	cout<<st<<endl;


 //	cout<<endl<<endl;
 	if(mid<bb){
 		//(mid+1,bb) (max(ans[mid],mid+1),dd)
 		co=0;
 		for(int i=aa;i<=mid;i++){
 			add(i);
 			co+=1;
 		}
 		dnc(mid+1,bb,max(ans[mid],mid+1),dd);
 		for(int i=0;i<co;i++){
 			rollback();
 		}
 	}

 	if(mid>aa){
 		co=0;
 		//(aa,mid-1) (0,ans[mid])
 		for(int i=ans[mid]+1;i<=dd;i++){
 			add(i);
 			co+=1;
 		}
 		dnc(aa,mid-1,cc,ans[mid]);
 		for(int i=0;i<co;i++){
 			rollback();
 		}
 	}
 	








}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>q;
	for(int i=0;i<m;i++){
		int aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		ed.pb({aa,bb});
	}
	for(int i=0;i<n;i++){
		par[i]={i,0};
		ss[i]=1;
	}
	int coo=0;
	int ind=m-1;
	for(int i=0;i<m;i++){
		add(i);
		coo+=1;
		//cout<<st<<endl;
		if(st>0){
			ind=i;
			break;
		}
	}
	for(int i=0;i<coo;i++){
		rollback();
	}
	for(int i=ind+1;i<m;i++){
		ans[i]=m;
	}
	dnc(0,ind,0,m-1);
/*	for(int i=0;i<m;i++){
		cout<<ans[i]<<",";
	}
	cout<<endl;*/

	for(int i=0;i<q;i++){
		int aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		
		if(bb<ans[aa]){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		
	}







	return 0;
}