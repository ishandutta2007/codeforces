//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

vector<llo> pre[200001];

const llo xx=300;
llo n;
bool check(int aa,int bb){
	if(pre[aa].size()==0){
		return 0;
	}
	if(aa<0 or aa>100000){
		return 0;
	}

	int cc=lower_bound(pre[aa].begin(),pre[aa].end(),bb)-pre[aa].begin();
	if(cc<pre[aa].size()){
		if(pre[aa][cc]==bb){
			return true;
		}
	}
	return false;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	vector<pair<llo,llo>> ss;
	for(llo i=0;i<n;i++){
		llo aa,bb;
		cin>>aa>>bb;
		ss.pb({aa,bb});

		pre[aa].pb(bb);
	}

	llo ans=0;
	for(llo i=0;i<=100000;i++){
		if(pre[i].size()){
			sort(pre[i].begin(),pre[i].end());
			if(pre[i].size()<=xx){
				for(llo j=0;j<pre[i].size();j++){
					for(llo k=j+1;k<pre[i].size();k++){
						llo xx=i-(pre[i][k]-pre[i][j]);
						if(xx<0){
							continue;
						}
						if(pre[xx].size()<=1){
							continue;
						}
					//	cout<<pre[i][j]<<","<<pre[i][k]<<endl;
						//cout<<xx<<endl;
						if(check(xx,pre[i][j])){
							if(check(xx,pre[i][k])){
								ans+=1;
							}
						}
						/*llo kk=lower_bound(pre[xx].begin(),pre[xx].end(),pre[i][j])-pre[xx].begin();
						if(check(xx,pre[i][j]))
						if(kk<pre[xx].size()){
							if(pre[xx][kk]==pre[i][j]){
								//cout<<pre[i][j]<<","<<pre[i][k]<<endl;
								llo mm=lower_bound(pre[xx].begin(),pre[xx].end(),pre[i][k])-pre[xx].begin();
								if(mm<pre[xx].size()){
									if(pre[xx][mm]==pre[i][k]){
										ans+=1;
									}
								}
							}
						}*/
					}
				}
			}
			else{
				for(auto j:ss){
					if(j.a<i){
						llo xx=(i-j.a);
						//js
						//j+xx,j
						//j,j+xx
						//j+xx,j+xx
						if(xx+j.a<=100000 and xx+j.b<=100000){
							if(pre[xx+j.a].size()>1 and pre[j.a].size()>1){



								if(check(j.a,xx+j.b)){
									if(check(j.a+xx,j.b)){
										if(check(j.a+xx,j.b+xx)){
											ans+=1;
										}
									}
								}
								/*llo kk=lower_bound(pre[j.a].begin(),pre[j.a].end(),xx+j.b)-pre[j.a].begin();
								//cout<<j.a<<":"<<j.b<<":"<<xx<<endl;
								if(kk<pre[j.a].size()){
								//	cout<<j.a<<":"<<j.b<<":"<<xx<<endl;		
									if(pre[xx][kk]==j.b+xx){
									//	cout<<j.a<<":"<<j.b<<":"<<xx<<endl;		
										llo mm=lower_bound(pre[j.a+xx].begin(),pre[j.a+xx].end(),j.b)-pre[j.a+xx].begin();
										if(mm<pre[xx+j.a].size()){
											if(pre[xx+j.a][mm]==j.b){
												llo nn=lower_bound(pre[j.a+xx].begin(),pre[j.a+xx].end(),j.b+xx)-pre[j.a+xx].begin();
												if(nn<pre[xx+j.a].size()){
													if(pre[xx+j.a][nn]==j.b+xx){
														//cout<<j.a<<":"<<j.b<<":"<<xx<<endl;							
														ans+=1;
													}
												}
											}
										}
									}
								}*/
							}
						}

					}
				}
			}
		}
	}
	cout<<ans<<endl;







 
 
	return 0;
}