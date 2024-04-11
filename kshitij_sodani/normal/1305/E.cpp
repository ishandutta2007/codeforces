#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long int llo;
#define a first
#define  b second
#define endl "\n"
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n,m;
	cin>>n>>m;
	vector<llo> aa;
	
	llo tot=0;
	llo ind=-1;
	for(llo i=0;i<n;i++){
		tot+=i/2;
		/*if(ind!=-1){
			continue;
		}*/
		if(tot>m){
			tot-=i/2;
			ind=i;
			break;
			
		}
	}

	llo tot2=0;
	for(int i=0;i<n;i++){
		tot2+=i/2;
	}
	if(m>tot2){
		cout<<-1<<endl;
	}
	else if(m==tot2){
		for(int i=0;i<n;i++){
			cout<<i+1<<" ";
		}
		cout<<endl;
	}
	else{
		for(llo i=1;i<=ind;i++){
			aa.pb(i);
		}
		aa.pb(2*ind+1-2*(m-tot));
		for(int i=ind+1;i<n;i++){
			aa.pb(10000000+(aa[ind]+1)*i);
		}
/*		llo mm=tot-m;
	//	cout<<mm<<endl;
		for(llo i=n-1;i>=2;i--){
			if(mm==0){
				break;
			}
			if((i)/2<=mm ){
				llo x=aa[i-1]+aa[i-2]-aa[i]+1;
				llo tot2=2;
				llo p1=1;
				llo p2=1;
				for(llo j=i;j<n;j++){
					aa[j]+=(x);
					if(j>=i+2){
						aa[j]+=p1+p2+10;
						llo xx=p1+p2+10;
						p1=p2;
						p2=xx;
					}
				}
				mm-=(i)/2;
				cout<<mm<<endl;
				for(llo j=0;j<n;j++){
					cout<<aa[j]<<" ";
				}
				cout<<endl;
			}
			else{
				/*for(llo j=0;j<n;j++){
					cout<<aa[j]<<" ";
				}
				cout<<endl;
				cout<<mm<<endl;*/
				/*llo jj=i-1-(mm*2-1);
				llo x=(aa[i-1]+aa[jj]-aa[i]);
				for(llo j=i;j<n;j++){
					if(j==i){
						aa[j]+=x;
					}
					else{
						aa[j]+=x+((j-i)*(j-i+1))/2;
					}
				}
				mm=0;
			}
		}*/
		for(llo i=0;i<n;i++){
			cout<<aa[i]<<" ";
		}
	}
















	return 0;
}