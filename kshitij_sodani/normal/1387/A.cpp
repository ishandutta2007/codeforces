#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
typedef long double ld;

#define mp make_pair
#define pb push_back
#define a first 
#define b second
int n,m;
int vis[100001];
//llo ans=0;

vector<pair<int,int>> adj[100001];
pair<int,int> val[100001];
int st=0;
ld val2=0;
int stt=1;
ld dif=0.00000001;
ld ans[100001];
vector<int> ord;
void dfs(int no,int par=-1){
	vis[no]=1;
	ord.pb(no);
	for(auto j:adj[no]){
		if(vis[j.a]==0){
			val[j.a]={-val[no].a,j.b-val[no].b};
			dfs(j.a,no);
		}
		else{
			if(val[j.a].a+val[no].a!=0){
				ld cur=(((ld)j.b)-((ld)val[j.a].b)-((ld)val[no].b))/(((ld)val[no].a)+((ld)val[j.a].a));
			//	cout<<cur<<endl;
				if(st==0){
					st=1;
					val2=cur;
				}
				else{
					if(abs(val2-cur)>dif){
						stt=0;
					}
				}
			}
			else{
				if(val[j.a].b+val[no].b!=j.b){
					stt=0;
				}
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int aa,bb,cc;
		cin>>aa>>bb>>cc;
		aa--;
		bb--;
		adj[aa].pb({bb,cc});
		adj[bb].pb({aa,cc});
	}
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			val[i]={1,0};
			st=0;
			dfs(i);
			
			if(st==1){
				for(auto j:ord){
					ans[j]=(ld)val2*val[j].a+(ld)val[j].b;
				}
			}
			else{
				int ko=0;
				ld mi=0;
				ld cop=0;
				vector<ld> con;
				for(auto j:ord){
					ld val3;
					if(val[j].a==1){
						val3=-val[j].b;
					}
					else{
						val3=val[j].b;
					}
					con.pb(val3);

/*
					ld su=0;
					for(auto k:ord){
						su+=abs((ld)val[k].a*val3+(ld)val[k].b);
					}
					if(ko==0 or su<mi){
						for(auto k:ord){
							ans[k]=(ld)val[k].a*val3+(ld)val[k].b;
						}
						mi=su;
					}
					ko=1;*/
				}
				ld su=0;//negative sum
				ld su2=0;//positive sum
				ld co=0;//negative count
				ld co2=0;//positive count

				llo ss=ord.size();
				sort(con.begin(),con.end());
				vector<vector<ld>> co3;
				vector<vector<ld>> co4;
				for(int j=0;j<ss;j++){
					co3.pb({});
					co4.pb({});
				}
				for(auto j:ord){
					if(val[j].a==1){
						co+=1;
						su+=val[j].b;
						llo low=0;
						llo high=ss-1;
						while(low<high-1){
							llo mid=(low+high)/2;
							if(val[j].b+con[mid]>=0){
								high=mid;
							}
							else{
								low=mid;
							}
						}
						for(llo ii=low;ii<=high;ii++){
							if(val[j].b+con[ii]>=0){
								co3[ii].pb(val[j].b);
								break;
							}
						}
					}
					else{
						su2+=val[j].b;
						co2-=1;
						llo low=0;
						llo high=ss-1;
						while(low<high-1){
							llo mid=(low+high)/2;
							if(val[j].b-con[mid]<=0){
								high=mid;
							}
							else{
								low=mid;
							}
						}
						for(llo ii=low;ii<=high;ii++){
							if(val[j].b-con[ii]<=0){
								co4[ii].pb(val[j].b);
								break;
							}
						}
					}
				}
				int ind=-1;
				for(auto j:con){
					ind+=1;
					ld cur;
					for(auto ii:co3[ind]){
						co-=1;
						co2+=1;
						su-=ii;
						su2+=ii;
					}
					for(auto ii:co4[ind]){
						co2+=1;
						co-=1;
						su2-=ii;
						su+=ii;
					}
					cur=abs(su+j*co)+abs(su2+j*co2);
					if(ind==0 or cur<mi){
						cop=j;
						mi=cur;
					}

				}
				for(auto k:ord){
					ans[k]=(ld)val[k].a*cop+(ld)val[k].b;
				}

			}
			ord.clear();
		}
	}
	/*for(int i=0;i<n;i++){
		cout<<val[i].a<<","<<val[i].b<<endl;
	}*/
	if(stt==0){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++){
			cout<<setprecision(10)<<ans[i]<<" ";
		}
	}


	return 0;
}