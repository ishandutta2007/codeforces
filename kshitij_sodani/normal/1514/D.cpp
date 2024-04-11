//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo n,q;
llo it[300001];
llo ans[300001];
const llo cc=600;
llo ma=0;
llo co[300001];
llo freq[300001];
pair<llo,llo> qq[300001];
bool cmp(pair<pair<llo,llo>,llo> aa ,pair<pair<llo,llo>,llo> bb){
	llo x=aa.a.a/cc;
	llo y=bb.a.a/cc;
	if(x==y){
		return aa.a.b<bb.a.b;
	}
	else{
		return x<y;
	}
}
void add(llo i){
	co[freq[it[i]]]--;
	freq[it[i]]++;
	co[freq[it[i]]]++;
	if(co[ma+1]>0){
		ma++;
	}
}
void remove(llo i){
	co[freq[it[i]]]--;
	freq[it[i]]--;
	co[freq[it[i]]]++;
	if(co[ma]==0){
		ma--;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q;
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	vector<pair<pair<llo,llo>,llo>> ss;
	for(llo i=0;i<q;i++){
		llo l,r;
		cin>>l>>r;
		l--;
		r--;
		qq[i]={l,r};
		ss.pb({{l,r},i});
	}
	sort(ss.begin(),ss.end(),cmp);
	co[n]=0;
	pair<llo,llo> cur={-1,-1};
	for(auto j:ss){
		if(cur.a==-1){
			for(llo i=j.a.a;i<=j.a.b;i++){
				add(i);
			}
			cur={j.a.a,j.a.b};

		}
		else{
			while(cur.a>j.a.a){
				cur.a--;
				add(cur.a);
			}
			while(cur.b<j.a.b){
				cur.b++;
				add(cur.b);
			}
			while(cur.a<j.a.a){
				remove(cur.a);
				cur.a++;
			}
			while(cur.b>j.a.b){
				remove(cur.b);
				cur.b--;
			}
		}
		ans[j.b]=ma;
	}
	for(llo i=0;i<q;i++){
		llo nn=(qq[i].b-qq[i].a+1);
		llo aa=(nn+1)/2;
		llo le=nn-ans[i];

		if(ans[i]<=le+1){
			cout<<1<<endl;
		}
		else{
			cout<<nn-2*le<<endl;
			//cout<<ans[i]-aa+1<<endl;
		}
		//cout<<ans[i]<<endl;
	}





 
 
	return 0;
}