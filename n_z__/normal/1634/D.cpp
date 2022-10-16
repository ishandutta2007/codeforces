#include <bits/stdc++.h>
#define int long long
using namespace std;
int qry(int x,int y,int z){
	cout<<"? "<<x<<" "<<y<<" "<<z<<endl;
	fflush(stdout);
	int ret;
	cin>>ret;
	return ret;
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> vc;
		for(int i=1;i<=n;i++){
			vc.push_back(i);
		}
		while(vc.size()>2){
			if(vc.size()==3){
                for(int i=1;i<=n;i++){
                    if(vc[0]!=i&&vc[1]!=i&&vc[2]!=i){
                        vc.push_back(i);
                        break;
                    }
                }
            }
			vector<int> newvc;
			for(int i=0;i<vc.size();){
				if(i+3<vc.size()){
				int q[5];
				q[1]=qry(vc[i],vc[i+1],vc[i+2]),q[2]=qry(vc[i],vc[i+1],vc[i+3]),q[3]=qry(vc[i],vc[i+2],vc[i+3]),q[4]=qry(vc[i+1],vc[i+2],vc[i+3]);
				int maxv=max(max(q[1],q[2]),max(q[3],q[4]));
				int ok=0;
				for(int j=1;j<=4&&!ok;j++){
					if(q[j]==maxv){
						for(int k=j+1;k<=4&&!ok;k++){
							if(q[j]==q[k]){
								int m1,m2,m3,m4,m5,m6;
								if(j==1){
									m1=vc[i],m2=vc[i+1],m3=vc[i+2];
								}
								if(j==2){
									m1=vc[i],m2=vc[i+1],m3=vc[i+3];
								}
								if(j==3){
									m1=vc[i],m2=vc[i+2],m3=vc[i+3];
								}
								if(j==4){
									m1=vc[i+1],m2=vc[i+2],m3=vc[i+3];
								}
								if(k==1){
									m4=vc[i],m5=vc[i+1],m6=vc[i+2];
								}
								if(k==2){
									m4=vc[i],m5=vc[i+1],m6=vc[i+3];
								}
								if(k==3){
									m4=vc[i],m5=vc[i+2],m6=vc[i+3];
								}
								if(k==4){
									m4=vc[i+1],m5=vc[i+2],m6=vc[i+3];
								}
								set<int> st;
								st.insert(m1); st.insert(m2); st.insert(m3);
								if(st.count(m4)) newvc.push_back(m4);
								if(st.count(m5)) newvc.push_back(m5);
								if(st.count(m6)) newvc.push_back(m6);
								ok=1;
							}
						}
					}
				}
				}
				else{
					for(int j=i;j<vc.size();j++){
						newvc.push_back(vc[j]);
					}
				}
				i+=4;
			}
			vc=newvc;
		}
		cout<<"! "<<vc[0]<<" "<<vc[1]<<endl;
		fflush(stdout);
	}
	return 0;
}