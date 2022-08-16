//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

long double xx[3];
bool vis[3];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		long double aa,bb,cc,vv;
		cin>>aa>>bb>>cc>>vv;
		long double ans=0;
		long double kk=vv/(long double)2;
		for(int j=0;j<=20;j++){
			
			for(int i=0;i<(1<<j);i++){
				long double cur=1;
				xx[0]=aa;
				xx[1]=bb;
				xx[2]=cc;
			/*	for(int ii=0;ii<3;ii++){
				
					vis[ii]=0;
				}*/
				vis[0]=0;
				vis[1]=0;

				//vis[1]=1;
				for(int k=0;k<j;k++){
					if((1<<k)&i){
						if(vis[0]){
							cur=0;
							break;
						}
						cur*=xx[0];
						if(xx[0]>vv){
							//long double cot=vv;
							xx[0]-=vv;
							if(vis[1]){
								//xx[2]+=vv;
							}
							else{
								/*vis[0]=1;
								xx[0]=0;*/
								//xx[2]+=kk;
								xx[1]+=kk;
							}
						}
						else{
							vis[0]=1;
							long double cot=xx[0];
							xx[0]=0;
							if(vis[1]){
								//xx[2]+=cot;
							}
							else{
								//vis[0]=1;
								//xx[0]=0;
								//xx[2]+=cot/(long double)2;
								xx[1]+=cot/(long double)2;
							}
						}
					}
					else{
						if(vis[1]){
							cur=0;
							break;
						}

						cur*=xx[1];

						if(xx[1]>vv){
							//long double cot=vv;
							xx[1]-=vv;
							//if(j==10 and i==1){

								//cout<<11<<endl;
								//cout<<setprecision(5)<<":"<<xx[1]
							//}
							if(vis[0]){
								//xx[2]+=vv;
							}
							else{
								//vis[1]=1;
								//xx[1]=0;
								//xx[2]+=kk;
								xx[0]+=kk;
							}
						}
						else{
							long double cot=xx[1];
							xx[1]-=cot;
							vis[1]=1;
							if(vis[0]){
								//xx[2]+=cot;
							}
							else{
								/*vis[1]=1;
								xx[1]=0;*/
								//xx[2]+=cot/(long double)2;
								xx[0]+=cot/(long double)2;
							}
						}
					}
					if(xx[0]<=0.00000001){
						vis[0]=1;
					}
					if(xx[1]<=0.00000001){
						vis[1]=1;
					}
					/*if(j==10 and i==1){
						cout<<setprecision(5)<<"   "<<xx[0]<<"   "<<xx[1]<<"   "<<xx[2]<<endl;
					}*/
				}
				
				cur*=((long double)1-xx[0]-xx[1]);
				long double kk=j+1;
				/*if(cur>0.000001){
					cout<<j<<":"<<i<<"::"<<endl;
				}*/
			/*	if(cur>0){
					cout<<j<<":";//setprecision(10)<<cur<<":"<<j<<endl;
				}*/
				ans=(ans+cur*kk);
			}
			
		}
		cout<<setprecision(10)<<ans<<endl;
		/*for(int i=0;i<(1<<20);i++){

		}*/
	}


 
 
 
 
 
 
 
	return 0;
}