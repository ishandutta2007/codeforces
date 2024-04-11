//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo vis[101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*for(llo ii=0;ii<50;ii++){
		llo st=0;
		for(llo i=1;;i++){
			for(llo j=i;;j++){
				for(llo k=j;;k++){
					if((i^j)==k){
						if(vis[i]==0 and vis[j]==0 and vis[k]==0){
							cout<<i<<","<<j<<","<<k<<endl;
							vis[i]=1;
							vis[j]=1;
							vis[k]=1;
							st=1;
							break;
						}
					}
				}
				if(st){
					break;
				}
			}
			if(st){
				break;
			}
		}
		cout<<endl;
	}*/
	llo cur=1;
	vector<pair<llo,llo>> ss;
	ss.pb({1,1});
	for(llo i=0;i<60;i+=2){
		cur+=(1LL<<i);
		ss.pb({cur,i+3});
	}
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		llo cur=(n+2)/3;
		for(llo ii=0;ii+1<ss.size();ii++){
			if(ss[ii].a<=cur and ss[ii+1].a>cur){
				llo aa=(1LL<<(ss[ii].b-1))+cur-ss[ii].a;
				llo bb=0;
				llo cc=0;
				bb+=(1LL<<ss[ii].b);
				cc+=(1LL<<ss[ii].b);
				cc+=(1LL<<(ss[ii].b-1));
				for(llo i=0;i<ss[ii].b-1;i+=2){
					llo dd=aa&(1LL<<(i+1));
					llo ee=aa&(1LL<<(i));
				//	cout<<dd<<":"<<ee<<endl;
					if(dd==0 and ee==0){
						continue;
					}
					if(dd and ee==0){
						bb+=(1LL<<i);
						bb+=(1LL<<(i+1));
						cc+=(1LL<<i);
					}
					else if(dd and ee){
						bb+=(1LL<<i);
						cc+=(1LL<<(i+1));
					}
					else{
						bb+=(1LL<<(i+1));
						cc+=(1LL<<i);
						cc+=(1LL<<(i+1));
					}
				}
			//	cout<<aa<<":"<<bb<<":"<<cc<<endl;
				if(n%3==0){
					cout<<cc<<endl;
				}
				else if(n%3==2){
					cout<<bb<<endl;
				}
				else{
					cout<<aa<<endl;
				}


				break;
			}
		}
	}


	//cout<<ss[ss.size()-2].a<<endl;
	return 0;
}