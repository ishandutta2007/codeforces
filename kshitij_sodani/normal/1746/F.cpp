#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
const llo mod=1e9+7;
llo it[300001];
llo it2[300001];
llo val[600001][30];
llo ans[300001];
llo tree[300001];
llo ind5=0;
void uu(llo i,llo j){
	while(i<=3e5){
		tree[i]+=j;
		i+=(i&-i);
	}
}
llo ss2(llo i){
	llo su=0;
	while(i>0){
		su+=tree[i];
		i-=(i&-i);
	}
	return su;
}
/*void build(llo no,llo l,llo r){
	if(l==r){
		tree[no]=val[it[l]][ind5];
	}
	else{
		llo mid=(l+r)/2;
		build(no*2+1,l,mid);
		build(no*2+2,mid+1,r);
		tree[no]=(tree[no*2+1]+tree[no*2+2]);

	}
}

void update(llo no,llo l,llo r,llo i,llo j){
	if(l==r){
		tree[no]=j;;
	}
	else{
		llo mid=(l+r)/2;
		if(i<=mid){
			update(no*2+1,l,mid,i,j);
		}
		else{
			update(no*2+2,mid+1,r,i,j);
		}
		tree[no]=(tree[no*2+1]+tree[no*2+2]);
	}

}
llo query(llo no,llo l,llo r,llo aa,llo bb){
	if(r<aa or l>bb or aa>bb){
		return 0;
	}
	if(aa<=l and r<=bb){
		return tree[no];
	}
	llo mid=(l+r)/2;
	return query(no*2+1,l,mid,aa,bb)+query(no*2+2,mid+1,r,aa,bb);
}*/
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	mt19937 rng;
	rng=mt19937(chrono::steady_clock::now().time_since_epoch().count());

	llo n,q;
	cin>>n>>q;
	map<llo,llo> ss;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		ss[it[i]]++;
/*		for(llo j=0;j<30;j++){
			val[i][j]=(rng()%mod);
		}*/
	}

	vector<pair<pair<llo,llo>,pair<llo,llo>>> qq;
	for(llo ii=0;ii<q;ii++){
		llo tt;
		cin>>tt;
		ans[ii]=1;
		if(tt==1){
			llo aa,bb;
			cin>>aa>>bb;
			ss[bb]++;
			aa--;
			qq.pb({{tt,-1},{aa,bb}});
		}
		else{
			llo aa,bb,cc;
			cin>>aa>>bb>>cc;
			aa--;
			bb--;
			qq.pb({{tt,cc},{aa,bb}});
		}
	}
	map<llo,llo> tt;
	llo ind=0;
	for(auto j:ss){
		tt[j.a]=ind;
		ind++;
	}
	for(llo i=0;i<ind;i++){
		for(llo j=0;j<30;j++){
			val[i][j]=(rng()%mod)+1;//i+1;
		}
	}
	for(llo i=0;i<n;i++){
		it[i]=tt[it[i]];
	}
	for(llo i=0;i<qq.size();i++){
		if(qq[i].a.a==1){
			qq[i].b.b=tt[qq[i].b.b];
		}
	}
	/*for(llo i=0;i<n;i++){
		cout<<it[i]<<",";
	}
	cout<<endl;
	for(llo i=0;i<qq.size();i++){
		if(qq[i].a.a==1){
			cout<<qq[i].b.b<<":";
		}
	}*/
	//cout<<endl;
	for(llo j=0;j<30;j++){
		ind5=j;
	//	build(0,0,n-1);
		for(llo i=0;i<=n;i++){
			tree[i]=0;
		}
		for(llo i=0;i<n;i++){
			uu(i+1,val[it[i]][j]);
			it2[i]=it[i];
		}
		for(llo i=0;i<q;i++){
			if(qq[i].a.a==1){
				llo x=val[qq[i].b.b][j]-val[it2[qq[i].b.a]][j];
				uu(qq[i].b.a+1,x);
				it2[qq[i].b.a]=qq[i].b.b;
			}
			else{
				llo su=ss2(qq[i].b.b+1)-ss2(qq[i].b.a);
				//cout<<i<<":"<<su<<":"<<qq[i].a.b<<endl;
				if((su%qq[i].a.b)!=0){
					ans[i]=0;
				}
			}
		}
	}
	for(llo i=0;i<q;i++){
		if(qq[i].a.a==2){
			if((qq[i].b.b-qq[i].b.a+1)%qq[i].a.b==0){
				if(ans[i]==0){
					cout<<"NO"<<endl;
				}
				else{
					cout<<"YES"<<endl;
				}
			}
			else{
				cout<<"NO"<<endl;
			}
		}
	}








	return 0;
}