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
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,aa,bb,cc;
		cin>>n>>aa>>bb>>cc;
		string s;
		cin>>s;
		vector<pair<llo,llo>> cur;
		llo ans=0;
		for(llo i=0;i<n;i++){
			it[i]=s[i]-'0';
			if(cur.size()==0){
				cur.pb({it[i],1});
				continue;
			}
			if(it[i]==cur.back().a){
				cur[cur.size()-1].b+=1;
				continue;
			}
			cur.pb({it[i],1});
		}
	
	
		for(llo ii=0;ii<2;ii++){
			llo ind=-1;
			llo su=0;

				llo co=0;//number of blocks
		llo co2=0;//number of ones
		for(auto j:cur){
			if(j.a==1){
				co++;
				co2+=j.b;
			}
		}
		swap(co,co2);
		multiset<llo> xx;
		llo ee=0;
		llo ff=0;
		for(llo j=0;j<cur.size();j++){
			if(cur[j].a==0){
				if(j==0){
					ee=cur[j].b;
				}
				else if(j+1==cur.size()){
					ff=cur[j].b;
				}
				else{
					xx.insert(cur[j].b);
				}
			}
		}
		
			while(true){
				ind++;
				ans=max(ans,su);
				if((ind+ii)%2==0){
					//type 2
				//	cout<<11<<endl;
					if(co>co2){
						co--;
						su+=bb;
						continue;
					}
					else{
						break;
					}
				}
				else{	
					if(co==co2){

						llo st=1;
						if(xx.size()){
							auto j=xx.end();
							j--;
							if((*j)>1){
								st=0;
							}
						}
						if(ee>1){
							st=0;
						}
						if(ff>1){
							st=0;
						}
						if(st==0){
							ans=max(ans,su+aa);
						}
						if(xx.size()){
							if((*xx.begin())==1){
								su-=cc;
								xx.erase(xx.begin());
								co2--;

								continue;
							}	
						}
						break;
					}
					else{
					
						if(xx.size()){
							auto j=xx.lower_bound(2);
							if(j!=xx.end()){
								llo jj=(*j);
								xx.erase(j);
								xx.insert(jj-1);
								su+=aa;

								continue;
							}
						}
						if(ee>1){
							ee--;
							su+=aa;
							continue;
						}
						if(ff>1){
							ff--;
							su+=aa;
							continue;
						}
						if(xx.size()){
							if((*xx.begin())==1){
								su-=cc;
								xx.erase(xx.begin());
								co2--;
								continue;
							}
						}
						if(ee==1){
							ee--;
							su-=cc;
							continue;
						}
						if(ff==1){
							ff--;
							su-=cc;
							continue;
						}
						break;
					}
				}
				
			}
			ans=max(ans,su);
			
			




		}

		cout<<ans<<endl;


	}






 
	return 0;
}